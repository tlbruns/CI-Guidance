#ifndef PATIENT_REG_WIDGET_H
#define PATIENT_REG_WIDGET_H

#include <QDialog>
#include <qvector.h>
#include "ui_patient_registration.h"
#include <qtimer.h>
#include <Eigen/dense>
#include "PositionAverage.h"
#include "patient_data.h"
#include "rigidregistration.h"

namespace Ui {
	class Pat_Reg_Widget;}

class Pat_Reg_Widget : public QDialog
{
	Q_OBJECT

public:
    explicit Pat_Reg_Widget(const patient_data & ref_patient_data, QWidget *parent = 0);
    ~Pat_Reg_Widget();
	void RegisterCollectedData(const patient_data & ref_patient_data);
    void RegisterSkull();
	RigidRegistration	GetRegistration() const;

private:
	typedef enum {
		COLLECTING_1,
		COLLECTING_2,
		COLLECTING_3,
        COLLECTING_SKULL,
		NOT_COLLECTING
	} DataCollectingState;

	void StartCollection1();
	void StartCollection2();
	void StartCollection3();
    void StartCollectionSkull();

	DataCollectingState Collect1(double,double,double);
	DataCollectingState Collect2(double,double,double);
	DataCollectingState Collect3(double,double,double);
    DataCollectingState CollectSkull(Eigen::Matrix3Xd);

public slots:
	void slot_onButton1Clicked();
	void slot_onButton2Clicked();
	void slot_onButton3Clicked();
    void slot_onButtonSkullClicked();
	void slot_onTimer1();
	void slot_onTimer2();
	void slot_onTimer3();
    void slot_onTimerSkull();
    void slot_onNewProbePosition(double, double, double);
    void slot_onNewFiducialPositions(Eigen::Matrix3Xd &, int);
	void slot_onRegister();
	void slot_onSaveandFinish();

private:
	Ui::PatientRegistration	*ui;
	QTimer				     m_timer;
	int						 m_ticks;
	PositionAverage			 m_AverageMk1;
	PositionAverage			 m_AverageMk2;
	PositionAverage			 m_AverageMk3;
    const qint8              m_maxPossibleStrays; // max number of stray markers
    const float              m_matchingTolerance; // tolerance in [mm] that determines stray marker correspondence
    QVector<PositionAverage> m_AverageSkull;
	DataCollectingState		 m_DataState;
	patient_data			 m_patient_data;
	RigidRegistration		 m_registration;
    bool isDataValid(double x, double y, double z);
    bool isDataValid(Eigen::Matrix3Xd testMatrix);
    bool isMatch(Eigen::Vector3d point1, Eigen::Vector3d point2, double matchingTolerance);
};

#endif // PATIENT_REG_WIDGET_H
