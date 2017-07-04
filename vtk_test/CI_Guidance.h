#ifndef CI_GUIDANCE_H
#define CI_GUIDANCE_H

#include <QtWidgets/QMainWindow>
#include "ui_CI_Guidance.h"
#include <qtimer.h>
#include <qelapsedtimer.h>
#include <qlabel.h>
#include <qfile.h>
#include <vector>
#include "Tracker.h"
#include <vtkActor.h>
#include <Conversions.h>
#include <vtkTransform.h>
#include <vtkSmartPointer.h>
#include <Eigen/Dense>
#include <patient_data.h>
#include "demo_widget.h"
#include "TrackerSetup.h"

class vtkRenderer;
class QVTKWidget;


struct AlignmentErrors { // Note: all units are [mm] or [rad]
	double x; // cartesian errors
	double y;
	double z;
	double radial; // distance to primary axis (perpendicular)
	double axial;  // distance along primary axis (tangential)
	double theta;  // angle to primary axis
	double phi;	   // angle about primary axis
};

class CI_Guidance : public QMainWindow
{
	Q_OBJECT

public:
	CI_Guidance(QWidget *parent = 0);
	~CI_Guidance();
    void Initialize();
    vtkSmartPointer<vtkActor> LoadOBJFile(QString const& str, double opacity, double color[3]) const;
	vtkSmartPointer<vtkActor> LoadSTLFile(QString const & str, double opacity, double color[3]) const;
	void SetTransformforCI_target(patient_data *, Eigen::Matrix4d);
	void SetTransformforCI_target(Eigen::MatrixXd);

protected:
	Demo_Widget *pDemo_Widget;

protected slots:
    void slot_Tracker_Init();
    void slot_Tracker_Stop();
    void slot_refreshTracker();
	void slot_update_COM(int thePort);
	void slot_onGUITimer();
    void slot_updateActorAit(Eigen::Matrix4d);
    void slot_updateActorAitTarget(Eigen::Matrix4d);
    void slot_updateActorTube(Eigen::Matrix4d);
    void slot_updateActorTubeTarget(Eigen::Matrix4d);
    void slot_updateActorProbe(Eigen::Matrix4d);
    void slot_updateActorCochlea(Eigen::Matrix4d);
    void slot_updateActorFiducials(Eigen::Matrix3Xd, quint8);
	void slot_CenterView(QString);
	void slot_CenterTarget();
    void slot_Load_Plan();
    void slot_Pivot_Calibation();
    void slot_Update_Skull(Eigen::Matrix3Xd, quint8);
    void slot_LiveTracking(int);
	void slot_Register_Patient();
	void slot_Tracker_Setup();
	void slot_SetTarget();
	void slot_onFrameRateTimer();
	void resizeEvent(QResizeEvent *event);
	void slot_onRegistration(Eigen::MatrixXd);
	void slot_Demo();
	void slot_DatalogStart();
	void slot_DatalogStop();
	void slot_WriteData(double,double);
	void slot_WriteData();

signals:
	void sgn_NewProbePosition(double,double,double);
	void sgn_NewCIPosition(double,double,double);
    void sgn_NewAitTransform(Eigen::Matrix4d);
    void sgn_NewAitTargetTransform(Eigen::Matrix4d);
    void sgn_NewTubeTransform(Eigen::Matrix4d);
    void sgn_NewTubeTargetTransform(Eigen::Matrix4d);
    void sgn_NewProbeTransform(Eigen::Matrix4d);
    void sgn_NewCtTransform(Eigen::Matrix4d);
	void sgn_NewMagPosition(double,double,double);
    void sgn_NewFiducialPositions(Eigen::Matrix3Xd, quint8);
    void sgn_NewSkullPosition(double, double, double);
    void sgn_NewFre(double);
	void sgn_err(double,double);
	void sgn_err_ang(double);
	void sgn_WriteData();

private:
    Ui::CI_Guidance_Ui	ui;

    void Update_err();
    void InitVTK();

	bool isTracking;
    bool planLoaded;
	int tracker_Port;
	double dpi;
	TrackerSetup     *pTrackerSetup;
    NDIAuroraTracker *m_tracker;
    patient_data     *m_patientData;
	QTimer			  m_guiTimer;
	QTimer			  m_frameRateTimer;
    QTimer            m_trackerTimer;
	QElapsedTimer	  m_datalogTimer;
	int				  m_frames;
	QLabel			  m_statusLabel;
	QLabel		 	  m_frameRateLabel;
	QVTKWidget		 *m_pQVTK_top;
	QVTKWidget		 *m_pQVTK_top_inset;
	QVTKWidget		 *m_pQVTK_oblique;
	QVTKWidget		 *m_pQVTK_front;
	QVTKWidget		 *m_pQVTK_front_inset;
	QVTKWidget		 *m_pQVTK_side;
	QVTKWidget		 *m_pQVTK_side_inset;
	QFile			 *pDatalogFile;
	int				  m_time;

    vtkSmartPointer<vtkRenderer>    m_pRenderer_oblique;
    vtkSmartPointer<vtkRenderer>	m_pRenderer_top;
    vtkSmartPointer<vtkRenderer>	m_pRenderer_top_inset;
    vtkSmartPointer<vtkRenderer>	m_pRenderer_front;
    vtkSmartPointer<vtkRenderer>	m_pRenderer_front_inset;
    vtkSmartPointer<vtkRenderer>	m_pRenderer_side;
    vtkSmartPointer<vtkRenderer>	m_pRenderer_side_inset;

	vtkSmartPointer<vtkActor>		m_pActor_probe;
	vtkSmartPointer<vtkActor>		m_pActor_Ait;
	vtkSmartPointer<vtkActor>		m_pActor_AitTarget;
    vtkSmartPointer<vtkActor>       m_pActor_guideTube;
    vtkSmartPointer<vtkActor>       m_pActor_guideTubeTarget;
    vtkSmartPointer<vtkActor>       m_pActor_cochlea;
    vtkSmartPointer<vtkActor>       m_pActor_target_desired;
    vtkSmartPointer<vtkActor>       m_pActor_target_current;
    std::vector<vtkSmartPointer<vtkActor>> m_pActor_fiducials;
    quint8                          numFiducialActors;

    Eigen::Vector3d  m_colorCiTool;
    Eigen::Vector3d  m_colorCiTarget;
    Eigen::Vector3d  m_colorCochlea;
    Eigen::Vector3d  m_colorProbe;
    Eigen::Vector3d  m_colorFiducials;
    Eigen::Vector3d  m_colorStrays;

    vtkSmartPointer<vtkTransform>   pvtk_T_tracker_probe;
    vtkSmartPointer<vtkTransform>   pvtk_T_tracker_ait;
    vtkSmartPointer<vtkTransform>   pvtk_T_tracker_AitTarget;
    vtkSmartPointer<vtkTransform>   pvtk_T_tracker_tube;
    vtkSmartPointer<vtkTransform>   pvtk_T_tracker_tubeTarget;
    vtkSmartPointer<vtkTransform>   pvtk_T_tracker_ct;
    std::vector<vtkSmartPointer<vtkTransform>> pvtk_T_fiducials;

	RotationMatrix		dtRotMatrix;
    Eigen::Matrix4d     m_T_tracker_target;
	Eigen::Matrix4d		m_T_tracker_Ait;
    Eigen::Matrix4d     m_T_tool_tip; // tip offset obtained from pivot calibration dialog
    Eigen::Matrix4d     m_T_tracker_tip;
	Eigen::Matrix4d		m_probe_transform;
    Eigen::Matrix4d     m_skull_transform;
	Eigen::MatrixXd		CI_entry;
	bool				flag_SetTarget;
	AlignmentErrors		m_errors;
};

#endif // CI_GUIDANCE_H