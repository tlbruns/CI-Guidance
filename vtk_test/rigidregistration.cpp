#include "rigidregistration.h"
#include <QDebug>
#include <Eigen/SVD>
#include <Eigen/Geometry>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

#ifndef NDEBUG
#define PRINT_MATRIX(mat) {std::cout << #mat ##":" << std::endl << mat << std::endl;}
#else
#define PRINT_MATRIX(mat) (mat);
#endif

using ::Eigen::MatrixXd;
using ::Eigen::MatrixXi;
using ::Eigen::VectorXd;
using ::Eigen::Dynamic;

RigidRegistration::RigidRegistration()
{
}

double RigidRegistration::GetFRE() const
{
    return m_FRE;
}

MatrixXd RigidRegistration::GetTransform() const
{
    return m_transform;
}

Eigen::ArrayXi RigidRegistration::GetIndexMatch() const
{
    return m_indexMatch;
}

Eigen::MatrixXd RigidRegistration::getPtsMatch() const
{
    return m_ptsMatch;
}

void print_matrix(MatrixXd& mat, const char* str)
{
    std::cout << str << ":" << std::endl << mat << std::endl;
}

void pointRegister(MatrixXd ptsX, MatrixXd ptsY, RigidRegistration& reg)
{
    if (ptsX.rows() != ptsY.rows()) {
        qDebug() << "Both vectors of points must have the same number of rows";
    }
    if (ptsX.cols() != ptsY.cols()) {
        qDebug() << "Both matrices must have the same number of columns (number of points)";
    }

    int K = ptsX.rows(); //Dimension of the space
    int N = ptsX.cols(); //Number of points used in the registration

    MatrixXd xbar = ptsX.rowwise().mean();
    MatrixXd ybar = ptsY.rowwise().mean();

    PRINT_MATRIX(xbar);
    PRINT_MATRIX(ybar);

    //Get the De-meaned vector lists
    MatrixXd xtilde = ptsX - xbar.replicate(1,N);
    MatrixXd ytilde = ptsY - ybar.replicate(1,N);

    PRINT_MATRIX(xtilde);
    PRINT_MATRIX(ytilde);

    MatrixXd Hcov = xtilde*(ytilde.transpose()); //covariance matrix

    PRINT_MATRIX(Hcov);

    Eigen::JacobiSVD<MatrixXd> svdH = Hcov.jacobiSvd(Eigen::ComputeFullU | Eigen::ComputeFullV);
    MatrixXd U = svdH.matrixU();
    MatrixXd V = svdH.matrixV();

    PRINT_MATRIX(U);
    PRINT_MATRIX(V);

    VectorXd Dvec (K);
    Dvec = VectorXd::Constant(K, 1.0);
    Dvec(K-1) = (V*U).determinant();

    MatrixXd D = MatrixXd::Zero(K,K);
    for (int i = 0; i < K; ++i) {
        D(i,i) = Dvec(i);
    }

    MatrixXd R = V*D*U.transpose();
    MatrixXd t = ybar - R*xbar;

    PRINT_MATRIX(R);
    PRINT_MATRIX(t);

    MatrixXd FREcomponents = R*ptsX + t.replicate(1,N) - ptsY;
    double FRE = sqrt(FREcomponents.array().pow(2).colwise().sum().mean());
    reg.m_FRE = FRE;
    reg.m_transform = MatrixXd::Identity(4,4);
    reg.m_transform.block(0,0,3,3) = R;
    reg.m_transform.block(0,3,3,1) = t;
}

int pointRegisterOutliers(MatrixXd ptsX, MatrixXd ptsY, RigidRegistration & reg)
{
    // Finds the set of points in ptsY that corresponds to those in ptsX (rejecting outlier points) 
    // and computes registration: T*ptsX = ptsY
    // 
    // Each column of ptsX & ptsY defines a point

    /* 
    check dimensions 
    */

    if (ptsX.rows() != ptsY.rows()) {
        qDebug() << "Both vectors of points must have the same number of rows (same dimension)";
        return -1;
    }

    if (ptsX.cols() > ptsY.cols()) {
        qDebug() << "Y must have at least as many points as X";
        return -1;
    }

    int dim = ptsX.rows();  // dimension of the space
    int Xnum = ptsX.cols(); // number of points in X
    int Ynum = ptsY.cols(); // number of points in Y


    /* 
    compute registrations for all permutations of points in Y that could match X 
    */

    MatrixXi iPerms; // each element is the index of a point in X; each column is unique set of points
    createPermutations(Ynum, Xnum, iPerms); // create list (iPerms) of all choices of points

    MatrixXd testY(dim, Xnum); // holds the current set being tested
    std::vector<int> indexBest(Ynum); // choice of indices that resulted in FREbest

    reg.m_FRE = 5000.0; // current best FRE (initialize to arbitrarily large number)
    reg.m_transform = MatrixXd::Identity(4, 4);

    for (int ii = 0; ii < iPerms.rows(); ++ii)
    {
        // assemble set of points to test
        for (int jj = 0; jj < Xnum; ++jj)
        {
            testY.col(jj) = ptsY.col(iPerms(ii, jj));
        }

        // get the De-meaned vector lists
        MatrixXd xbar = ptsX.rowwise().mean();
        MatrixXd ybar = testY.rowwise().mean();
        MatrixXd xtilde = ptsX - xbar.replicate(1, Xnum);
        MatrixXd ytilde = testY - ybar.replicate(1, Xnum);

        // covariance matrix
        MatrixXd Hcov = xtilde*(ytilde.transpose());

        Eigen::JacobiSVD<MatrixXd> svdH = Hcov.jacobiSvd(Eigen::ComputeFullU | Eigen::ComputeFullV);
        MatrixXd U = svdH.matrixU();
        MatrixXd V = svdH.matrixV();
        VectorXd Dvec(dim);
        Dvec = VectorXd::Constant(dim, 1.0);
        Dvec(dim - 1) = (V*U).determinant();

        MatrixXd D = MatrixXd::Zero(dim, dim);
        for (int i = 0; i < dim; ++i) {
            D(i, i) = Dvec(i);
        }

        MatrixXd R = V*D*U.transpose();
        MatrixXd t = ybar - R*xbar;

        MatrixXd FREcomponents = R*ptsX + t.replicate(1, Xnum) - testY;
        double FRE = sqrt(FREcomponents.array().pow(2).colwise().sum().mean());

        // check if better than current best
        if (FRE < reg.m_FRE)
        {
            reg.m_FRE = FRE;
            reg.m_transform.block(0, 0, 3, 3) = R;
            reg.m_transform.block(0, 3, 3, 1) = t;
            reg.m_ptsMatch = testY;
            reg.m_indexMatch = iPerms.row(ii);
        }   
    }
    return 1;
}

void createPermutations(int n, int k, MatrixXi & iPerms)
{
    /*
        Returns a list of all n-choose-k permutations
    */

    std::vector<int> x(n); // create initial vector for permutations
    std::iota(x.begin(), x.end(), 0); // x = [0 1 2 ... n]

    iPerms.resize(numPermutations(n, k), k); // each row is unique permutation

    int row = 0;
    do
    {
        for (int col = 0; col < k; col++)
        {
            iPerms(row, col) = x[col];
        }
       
        std::reverse(x.begin() + k, x.end());
        ++row;
    } while (std::next_permutation(x.begin(), x.end()));
}

quint64 factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

quint32 numPermutations(int n, int k)
{
    return (factorial(n) / factorial(n - k));
}