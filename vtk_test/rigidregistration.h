#ifndef RIGIDREGISTRATION_H
#define RIGIDREGISTRATION_H

#include <Eigen/Dense>

class RigidRegistration
{
public:
    RigidRegistration();
    double GetFRE() const;
    Eigen::MatrixXd GetTransform() const;

private:
    Eigen::MatrixXd m_transform;
    double          m_FRE;

    friend void point_register(Eigen::MatrixXd ptsX, Eigen::MatrixXd ptsY, RigidRegistration &reg);
};

void point_register(Eigen::MatrixXd ptsX, Eigen::MatrixXd ptsY, RigidRegistration& reg);


#endif // RIGIDREGISTRATION_H
