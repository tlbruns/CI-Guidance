#ifndef VTK_TEST_H
#define VTK_TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_vtk_test.h"
#include <qtimer.h>
#include <qlabel.h>
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

class vtk_test : public QMainWindow
{
	Q_OBJECT

public:
	vtk_test(QWidget *parent = 0);
	~vtk_test();
	vtkSmartPointer<vtkActor> LoadOBJFile(QString const& str, double opacity, double color[3]) const;
	void Initialize();
	void SetTransformforCI_target(patient_data, Eigen::MatrixXd);
	void SetTransformforCI_target(Eigen::MatrixXd);

protected:
	Demo_Widget *pDemo_Widget;

protected slots:
	void slot_onGUITimer();
	void slot_Register_Patient();
	void slot_Tracker_Setup();
	void slot_SetTarget();
	void slot_onFrameRateTimer();
	void resizeEvent(QResizeEvent *event);
	void slot_onRegistration(Eigen::MatrixXd);
	void slot_Demo();
	void slot_DatalogStart();
	void slot_DatalogStop();

signals:
	void sgn_NewProbePosition(double,double,double);
	void sgn_NewCIPosition(double,double,double);
	void sgn_NewMagPosition(double,double,double);
	void sgn_err(double,double);

private:
	Ui::vtk_testClass ui;
	QTimer			  m_timer;
	QTimer			  m_frameRateTimer;
	int				  m_frames;
	QLabel			  m_statusLabel;
	QLabel			  m_frameRateLabel;
	QVTKWidget        *m_pQVTK_top;
	QVTKWidget        *m_pQVTK_oblique;
	QVTKWidget        *m_pQVTK_front;
	QVTKWidget        *m_pQVTK_side;
	int				  m_time;
	vtkRenderer       *m_pRenderer_oblique;
	vtkRenderer		  *m_pRenderer_top;
	vtkRenderer		  *m_pRenderer_front;
	vtkRenderer		  *m_pRenderer_side;
	NDIAuroraTracker  m_tracker;
	vtkSmartPointer<vtkActor>		  m_pActor_probe;
	vtkSmartPointer<vtkActor>		  m_pActor_CItool;
	vtkSmartPointer<vtkActor>		  m_pActor_CItarget;
	RotationMatrix	  dtRotMatrix;
	Eigen::MatrixXd	  CI_entry;
	bool			  flag_SetTarget;
	bool			  flag_DatalogStart;
	bool			  flag_DatalogStop;
	void Update_err(std::vector<ToolInformationStruct> const& tools);
};

#endif // VTK_TEST_H
