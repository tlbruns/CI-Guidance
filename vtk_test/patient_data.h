#pragma once
#include <Eigen/dense>

class patient_data
{
public:
	patient_data(void);
	~patient_data(void);
	Eigen::MatrixXd GetPatientData() const;
	Eigen::MatrixXd GetMarkers() const;
	Eigen::MatrixXd GetTraj() const;
	Eigen::MatrixXd GetEntry() const;
	Eigen::MatrixXd GetTarget() const;
	void SetPatientData(Eigen::MatrixXd);

private:
	Eigen::MatrixXd m_patientdata;
};

