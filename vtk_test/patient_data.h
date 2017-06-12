#pragma once
#include <Eigen/dense>
#include <qvector.h>
#include <qvector3d.h>
#include <qstring.h>
#include <qdatetime.h>

class patient_data
{
public:
	patient_data(void); // for demo/testing
    patient_data(QString filename); // reads filename.ini and parses patient data
	~patient_data(void);
    bool parse(void);
    quint32 id();
    QDate date();
    QVector<QVector3D> fiducials();
    QVector<QVector3D> trajectory();
    QVector3D target();
    QVector3D axis();
	Eigen::MatrixXd GetPatientData() const;
	Eigen::MatrixXd GetMarkers() const;
	Eigen::MatrixXd GetTraj() const;
	Eigen::MatrixXd GetEntry() const;
	Eigen::MatrixXd GetTarget() const;
	void SetPatientData(Eigen::MatrixXd);

private:
    QString iniFileName;
    quint32 m_id;
    QDate m_date;
    QVector<QVector3D> m_fiducials;
    QVector<QVector3D> m_trajectory;
    QVector3D m_target;
    QVector3D m_axis;

	Eigen::MatrixXd m_patientdata;
};

