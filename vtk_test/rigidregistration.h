#ifndef RIGIDREGISTRATION_H
#define RIGIDREGISTRATION_H

#include <Eigen/Dense>
#include <QtGlobal>

class RigidRegistration
{
public:
    RigidRegistration();

    // always available
    double GetFRE() const;
    Eigen::MatrixXd GetTransform() const;

    // only available if pointRegisterOutliers() was used
    Eigen::ArrayXi GetIndexMatch() const; // indices of correctly matched pts
    Eigen::MatrixXd getPtsMatch() const;    // actual matched pts

private:
    Eigen::MatrixXd m_transform;
    double          m_FRE;

    Eigen::MatrixXd m_ptsMatch; 
    Eigen::ArrayXi m_indexMatch;
    
    friend void pointRegister(Eigen::MatrixXd ptsX, Eigen::MatrixXd ptsY, RigidRegistration &reg);
    friend void pointRegisterOutliers(Eigen::MatrixXd ptsX, Eigen::MatrixXd ptsY, RigidRegistration& reg);
};

void pointRegister(Eigen::MatrixXd ptsX, Eigen::MatrixXd ptsY, RigidRegistration& reg); // ordered point sets of the same size
void pointRegisterOutliers(Eigen::MatrixXd ptsX, Eigen::MatrixXd ptsY, RigidRegistration& reg); // determines which points in ptsX correspond to those in ptsY
quint64 factorial(int n);
quint32 numPermutations(int n, int k);
void createPermutations(int n, int k, Eigen::MatrixXi & iPerms);

#endif // RIGIDREGISTRATION_H
