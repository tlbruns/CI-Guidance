#include "rigidregistration.h"
#include <QDebug>
#include <Eigen/SVD>
#include <Eigen/Geometry>
#include <iostream>
#include <cmath>

#ifndef NDEBUG
#define PRINT_MATRIX(mat) {std::cout << #mat ##":" << std::endl << mat << std::endl;}
#else
#define PRINT_MATRIX(mat) (mat);
#endif

using ::Eigen::MatrixXd;
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

void print_matrix(Eigen::MatrixXd& mat, const char* str)
{
    std::cout << str << ":" << std::endl << mat << std::endl;
}

void point_register(MatrixXd ptsX, MatrixXd ptsY, RigidRegistration& reg)
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
