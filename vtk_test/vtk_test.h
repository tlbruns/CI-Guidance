#ifndef VTK_TEST_H
#define VTK_TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_vtk_test.h"
#include <qtimer.h>
#include <qelapsedtimer.h>
#include <qlabel.h>
#include <qfile.h>
#include "Tracker.h"
#include <vtkActor.h>
#include <Conversions.h>
#include <vtkTransform.h>
#include <vtkSmartPointer.h>
#include <Eigen/Dense>
#include <patient_data.h>
#include "demo_widget.h"

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

class vtk_test : public QMainWindow
{
	Q_OBJECT

public:
	vtk_test(QWidget *parent = 0);
	~vtk_test();
	vtkSmartPointer<vtkActor> LoadOBJFile(QString const& str, double opacity, double color[3]) const;
	void Initialize();
	vtkSmartPointer<vtkActor> LoadSTLFile(QString const & str, double opacity, double color[3]) const;
	void SetTransformforCI_target(patient_data, Eigen::MatrixXd);
	void SetTransformforCI_target(Eigen::MatrixXd);

protected:
	Demo_Widget *pDemo_Widget;

protected slots:
	void slot_onGUITimer();
	void slot_CenterView(QString);
	void slot_CenterTarget();
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
	void sgn_NewMagPosition(double,double,double);
	void sgn_err(double,double);
	void sgn_err_ang(double);
	void sgn_WriteData();

private:
	Ui::vtk_testClass	ui;
	QTimer			m_timer;
	QTimer			m_frameRateTimer;
	QElapsedTimer	m_datalogTimer;
	int				m_frames;
	QLabel			m_statusLabel;
	QLabel			m_frameRateLabel;
	QVTKWidget		*m_pQVTK_top;
	QVTKWidget		*m_pQVTK_top_inset;
	QVTKWidget		*m_pQVTK_oblique;
	QVTKWidget		*m_pQVTK_front;
	QVTKWidget		*m_pQVTK_front_inset;
	QVTKWidget		*m_pQVTK_side;
	QVTKWidget		*m_pQVTK_side_inset;
	QFile			*pDatalogFile;
	int				m_time;
	vtkSmartPointer<vtkRenderer>    m_pRenderer_oblique;
	vtkSmartPointer<vtkRenderer>	m_pRenderer_top;
	vtkSmartPointer<vtkRenderer>	m_pRenderer_top_inset;
	vtkSmartPointer<vtkRenderer>	m_pRenderer_front;
	vtkSmartPointer<vtkRenderer>	m_pRenderer_front_inset;
	vtkSmartPointer<vtkRenderer>	m_pRenderer_side;
	vtkSmartPointer<vtkRenderer>	m_pRenderer_side_inset;
	vtkSmartPointer<vtkActor>		  m_pActor_probe;
	vtkSmartPointer<vtkActor>		  m_pActor_CItool;
	vtkSmartPointer<vtkActor>		  m_pActor_CItarget;
	NDIAuroraTracker	m_tracker;
	RotationMatrix		dtRotMatrix;
	Eigen::Matrix4d		m_CItarget_transform;
	Eigen::Matrix4d		m_CItool_transform;
	Eigen::Matrix4d		m_probe_transform;
	Eigen::MatrixXd		CI_entry;
	bool				flag_SetTarget;
	AlignmentErrors		m_errors;
	void Update_err(std::vector<ToolInformationStruct> const& tools);
	void Update_err();
};

#endif // VTK_TEST_H
