#include "CI_Guidance.h"
#include "patient_reg_widget.h"
#include "Pivot_Calibration.h"
#include "demo_widget.h"

 #include <vtkAutoInit.h>
 VTK_MODULE_INIT(vtkRenderingOpenGL);
 VTK_MODULE_INIT(vtkInteractionStyle);

#include "Tracker.h"
#include <QtGlobal>
#include <qscreen.h>
#include <QVTKWidget.h>
#include <qvector.h>
#include <vector>
#include <qfiledialog.h>
#include <qfile.h>
#include <qdatetime.h>
#include <qtextstream.h>
#include <vtkCamera.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkOBJReader.h>
#include <vtkSTLReader.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataNormals.h>
#include <Conversions.h>
#include <vtkTransform.h>
#include <vtkSmartPointer.h>
#include <vtkProperty.h>
#include <vtkTriangleFilter.h>
#include <vtkStripper.h>
#include <vtkSphereSource.h>
#include <math.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "infowidget.h"
#include <cassert>

#ifndef NDEBUG
#define PRINT_MATRIX(mat) {std::cout << #mat ##":" << std::endl << mat << std::endl;}
#else
#define PRINT_MATRIX(mat) (mat);
#endif

#define	 TRACKER_SIMULATE		0		// 1 for simulate, 0 if using tracker  NOT CURRENTLY WORKING!!
#define  TRACKER_COMPORT		8		// NOTE: COM port is zero-indexed (N-1)
#define	 PROBE_DESIRED_X		-79.3	// fixed position to use as the target pose
#define	 PROBE_DESIRED_Y		-376.8	
#define	 PROBE_DESIRED_Z		1451.95
#define  SIMULATE_ERROR			0.9		// Error to use when simulating

const static int TRACKER_UPDATE_INTERVAL = 20; // [ms]
const static int FRAME_RATE_UPDATE_INTERVAL = 2000; // [ms]
const static int NUM_TRACKED_TOOLS = 2; // which tools depends on the order in the .ini file (first N tools)

using namespace Eigen;

CI_Guidance::CI_Guidance(QWidget *parent)
	: QMainWindow(parent),
	m_time(0),
	m_frames(0),
    numFiducialActors(15),
	flag_SetTarget(FALSE),
    m_T_tracker_Ait(Matrix4d::Identity()),
    m_T_tool_tip(Matrix4d::Identity()),
	m_probe_transform(Matrix4d::Identity()),
    m_T_tracker_target(Matrix4d::Zero())
{
	pDemo_Widget = NULL;
	pDatalogFile = NULL;
	pTrackerSetup = NULL;
	m_tracker = NULL;

	isTracking = false;
    planLoaded = false;
	ui.setupUi(this);

    hideProbe = true;
    hideCochlea = true;
	
	dpi = QApplication::screens().at(0)->physicalDotsPerInch();

    m_colorCiTool    << 0.3, 1.0, 0.3;
    m_colorCiTarget  << 0.8, 0.3, 0.3;
    m_colorCochlea   << 0.75, 0.04, 0.84;
    m_colorProbe     << 0.3, 0.3, 1.0;
    m_colorFiducials << 0.81, 0.37, 0.08;
    m_colorStrays    << 0.31, 0.65, 0.79;

    m_T_tool_tip(0, 3) = 50;

	// setup info panel on left side
	InfoWidget *iw = new InfoWidget(this);
	ui.gridlayout->addWidget(iw,0,0,2,1);
	iw->setMaximumSize( (int)(2*dpi), (int)(25*dpi));
	

	// setup top view
	m_pQVTK_top= new QVTKWidget(this);
	ui.gridlayout->addWidget(m_pQVTK_top,0,1,1,1,0); // create QT widget
	
	// setup top inset
	m_pQVTK_top_inset = new QVTKWidget(this);
	ui.gridlayout->addWidget(m_pQVTK_top_inset, 0, 1, 1, 1, Qt::AlignBottom | Qt::AlignRight);

	// setup oblique view
	m_pQVTK_oblique = new QVTKWidget(this);
	ui.gridlayout->addWidget(m_pQVTK_oblique,0,2,1,1,0);

	// setup front view
	m_pQVTK_front = new QVTKWidget(this);
	ui.gridlayout->addWidget(m_pQVTK_front,1,1,1,1,0);

	// setup front inset
	m_pQVTK_front_inset = new QVTKWidget(this);
	ui.gridlayout->addWidget(m_pQVTK_front_inset, 1, 1, 1, 1, Qt::AlignBottom | Qt::AlignRight);

	// setup right side view
	m_pQVTK_side = new QVTKWidget(this);
	ui.gridlayout->addWidget(m_pQVTK_side,1,2,1,1,0);

	// setup right side inset
	m_pQVTK_side_inset = new QVTKWidget(this);
	ui.gridlayout->addWidget(m_pQVTK_side_inset, 1, 2, 1, 1, Qt::AlignBottom | Qt::AlignRight);

	// setup timers
    m_trackerTimer.setInterval(TRACKER_UPDATE_INTERVAL);
    m_trackerTimer.setSingleShot(false);
    connect(&m_trackerTimer, SIGNAL(timeout()), this, SLOT(slot_refreshTracker()));

	m_guiTimer.setInterval(0);
	m_guiTimer.setSingleShot(false);
	connect(&m_guiTimer, SIGNAL(timeout()), this, SLOT(slot_onGUITimer()));

	m_frameRateTimer.setInterval(FRAME_RATE_UPDATE_INTERVAL);
	m_frameRateTimer.setSingleShot(false);
	connect(&m_frameRateTimer, SIGNAL(timeout()), this, SLOT(slot_onFrameRateTimer()));
	m_frameRateTimer.start();
	ui.statusBar->addWidget(&m_frameRateLabel);

	// connect signals/slots
    connect(ui.actionTracker_Init, SIGNAL(triggered()), this, SLOT(slot_Tracker_Init()));
    connect(ui.actionTracker_Stop, SIGNAL(triggered()), this, SLOT(slot_Tracker_Stop()));
	connect(ui.actionRegister_Patient, SIGNAL(triggered()),this, SLOT(slot_Register_Patient()));
    connect(ui.actionLoad_Plan, SIGNAL(triggered()), this, SLOT(slot_Load_Plan()));
    connect(ui.actionPivot_Calibration, SIGNAL(triggered()), this, SLOT(slot_Pivot_Calibation()));
	connect(ui.actionTracker_Setup_2, SIGNAL(triggered()), this, SLOT(slot_Tracker_Setup()));
	connect(ui.actionDemo, SIGNAL(triggered()), this, SLOT(slot_Demo()));
    connect(ui.actionCenter_Target, SIGNAL(triggered()), this, SLOT(slot_CenterTarget()));

    connect(this, SIGNAL(sgn_NewProbeTransform(Eigen::Matrix4d)), this, SLOT(slot_updateActorProbe(Eigen::Matrix4d)));
    connect(this, SIGNAL(sgn_NewAitTransform(Eigen::Matrix4d)), this, SLOT(slot_updateActorAit(Eigen::Matrix4d)));
    connect(this, SIGNAL(sgn_NewAitTargetTransform(Eigen::Matrix4d)), this, SLOT(slot_updateActorAitTarget(Eigen::Matrix4d)));
    connect(this, SIGNAL(sgn_NewTubeTransform(Eigen::Matrix4d)), this, SLOT(slot_updateActorTube(Eigen::Matrix4d)));
    connect(this, SIGNAL(sgn_NewTubeTargetTransform(Eigen::Matrix4d)), this, SLOT(slot_updateActorTubeTarget(Eigen::Matrix4d)));
    connect(this, SIGNAL(sgn_NewFiducialPositions(Eigen::Matrix3Xd, quint8)), this, SLOT(slot_updateActorFiducials(Eigen::Matrix3Xd, quint8)));
    connect(this, SIGNAL(sgn_NewCtTransform(Eigen::Matrix4d)), this, SLOT(slot_updateActorCochlea(Eigen::Matrix4d)));


	connect(this, SIGNAL(sgn_NewProbePosition(double,double,double)), iw, SLOT(slot_NewProbePosition(double,double,double)));
	connect(this, SIGNAL(sgn_NewCIPosition(double,double,double)), iw, SLOT(slot_NewCIPosition(double,double,double)));
	connect(this, SIGNAL(sgn_NewMagPosition(double,double,double)), iw, SLOT(slot_NewMagPosition(double,double,double)));
	connect(this, SIGNAL(sgn_err(double,double)), iw, SLOT(slot_update_err(double,double)));
	connect(this, SIGNAL(sgn_err_ang(double)), iw, SLOT(slot_update_err_theta(double)));
    connect(this, SIGNAL(sgn_NewFre(double)), iw, SLOT(slot_NewFre(double)));
    connect(iw, SIGNAL(sgn_CenterView(QString)), this, SLOT(slot_CenterView(QString)));
    connect(iw, SIGNAL(sgn_LiveTracking(int)), this, SLOT(slot_LiveTracking(int)));
    connect(iw, SIGNAL(sgn_DatalogStart()), this, SLOT(slot_DatalogStart()));
    connect(iw, SIGNAL(sgn_DatalogStop()), this, SLOT(slot_DatalogStop()));


	//Tracker GUI
	ui.actionTracker_Stop->setEnabled(false);
	this->tracker_Port = TRACKER_COMPORT;
	QString trackerText = "Init Port " + QString::number(this->tracker_Port);
	ui.actionTracker_Init->setText(trackerText);

	//InitVTK
	InitVTK();
}

CI_Guidance::~CI_Guidance()
{
	// stop tracker
	if (isTracking)
		m_tracker->StopTracking();
	
	// Close file
	if(pDatalogFile != NULL){
		if(pDatalogFile->isOpen()){
			pDatalogFile->close();
		}
	}
}

void CI_Guidance::InitVTK() 
{
	m_pRenderer_top = vtkSmartPointer<vtkRenderer>::New();  // setup VTK renderer
	m_pQVTK_top->setMinimumSize((int)(3 * dpi), (int)(3 * dpi));
	m_pQVTK_top->GetRenderWindow()->AddRenderer(m_pRenderer_top);
	m_pRenderer_top->SetBackground(0.8, 0.8, 0.8);
	m_pRenderer_top->SetGradientBackground(true);

	vtkSmartPointer<vtkCamera> camera_top = vtkSmartPointer<vtkCamera>::New();
	camera_top->SetPosition(-100, 0, 0); // YZ Plane
	camera_top->SetFocalPoint(0, 0, 0);
	camera_top->SetViewUp(0, 0, 1);
	camera_top->SetClippingRange(-1500, 1500); // based on tracker workspace limits in x
	m_pRenderer_top->SetActiveCamera(camera_top);

	m_pRenderer_top_inset = vtkSmartPointer<vtkRenderer>::New();
	//m_pQVTK_top_inset->setMinimumSize((int)(0.5 * dpi), (int)(0.5 * dpi)); // for lower res displays
	m_pQVTK_top_inset->setMinimumSize((int)(1 * dpi), (int)(1 * dpi));
	m_pQVTK_top_inset->setMaximumSize((int)(1.5*dpi), (int)(1.5*dpi));
	m_pQVTK_top_inset->GetRenderWindow()->AddRenderer(m_pRenderer_top_inset);
	m_pRenderer_top_inset->SetBackground(0.8, 0.8, 0.8);
	m_pRenderer_top_inset->SetGradientBackground(true);

	vtkSmartPointer<vtkCamera> camera_top_inset = vtkSmartPointer<vtkCamera>::New();
	int inset_dist = -20;
	camera_top_inset->SetPosition(inset_dist, 0, 0); // YZ Plane
	camera_top_inset->SetFocalPoint(0, 0, 0);
	camera_top_inset->SetViewUp(0, 0, 1);
	camera_top_inset->SetClippingRange(-1500, 1500); // based on tracker workspace limits in x
	m_pRenderer_top_inset->SetActiveCamera(camera_top_inset);

	m_pRenderer_oblique = vtkSmartPointer<vtkRenderer>::New();
	m_pQVTK_oblique->setMinimumSize((int)(3 * dpi), (int)(3 * dpi));
	m_pQVTK_oblique->GetRenderWindow()->AddRenderer(m_pRenderer_oblique);
	m_pRenderer_oblique->SetBackground(0.8, 0.8, 0.8);
	m_pRenderer_oblique->SetGradientBackground(true);

	vtkSmartPointer<vtkCamera> camera_oblique = vtkSmartPointer<vtkCamera>::New();
	camera_oblique->SetPosition(100, 100, -1000);
	camera_oblique->SetFocalPoint(0, 0, 0);
	camera_oblique->SetViewUp(0, 0, 1);
	camera_oblique->SetClippingRange(-3000, 3000);
	m_pRenderer_oblique->SetActiveCamera(camera_oblique);

	m_pRenderer_front = vtkSmartPointer<vtkRenderer>::New();
	m_pQVTK_front->setMinimumSize((int)(3 * dpi), (int)(3 * dpi));
	m_pQVTK_front->GetRenderWindow()->AddRenderer(m_pRenderer_front);
	m_pRenderer_front->SetBackground(0.8, 0.8, 0.8);
	m_pRenderer_front->SetGradientBackground(true);

	vtkSmartPointer<vtkCamera> camera_front = vtkSmartPointer<vtkCamera>::New();
	camera_front->SetPosition(0, 0, -500); // XY Plane
	camera_front->SetFocalPoint(0, 0, 0);
	camera_front->SetViewUp(-1, 0, 0);
	camera_front->SetClippingRange(-3500, 1000); // based on tracker workspace limits in z
	m_pRenderer_front->SetActiveCamera(camera_front);

	m_pRenderer_front_inset = vtkSmartPointer<vtkRenderer>::New();
	//m_pQVTK_front_inset->setMinimumSize((int)(0.5 * dpi), (int)(0.5 * dpi)); // for lower res displays
	m_pQVTK_front_inset->setMinimumSize((int)(1 * dpi), (int)(1 * dpi));
	m_pQVTK_front_inset->setMaximumSize((int)(1.5*dpi), (int)(1.5*dpi));
	m_pQVTK_front_inset->GetRenderWindow()->AddRenderer(m_pRenderer_front_inset);
	m_pRenderer_front_inset->SetBackground(0.8, 0.8, 0.8);
	m_pRenderer_front_inset->SetGradientBackground(true);

	vtkSmartPointer<vtkCamera> camera_front_inset = vtkSmartPointer<vtkCamera>::New();
	camera_front_inset->SetPosition(0, 0, inset_dist); // XY Plane
	camera_front_inset->SetFocalPoint(0, 0, 0);
	camera_front_inset->SetViewUp(-1, 0, 0);
	camera_front_inset->SetClippingRange(-3500, 100); // based on tracker workspace limits in z
	m_pRenderer_front_inset->SetActiveCamera(camera_front_inset);

	m_pRenderer_side = vtkSmartPointer<vtkRenderer>::New();
	m_pQVTK_side->setMinimumSize((int)(3 * dpi), (int)(3 * dpi));
	m_pQVTK_side->GetRenderWindow()->AddRenderer(m_pRenderer_side);
	m_pRenderer_side->SetBackground(0.8, 0.8, 0.8);
	m_pRenderer_side->SetGradientBackground(true);

	vtkSmartPointer<vtkCamera> camera_side = vtkSmartPointer<vtkCamera>::New();
	camera_side->SetPosition(0, -500, 0); // XZ Plane
	camera_side->SetFocalPoint(0, 0, 0);
	camera_side->SetViewUp(-1, 0, 0);
	camera_side->SetClippingRange(-1500, 1500); // based on tracker workspace limits in x
	m_pRenderer_side->SetActiveCamera(camera_side);

	m_pRenderer_side_inset = vtkSmartPointer<vtkRenderer>::New();
	//m_pQVTK_side_inset->setMinimumSize((int)(0.5 * dpi), (int)(0.5 * dpi));
	m_pQVTK_side_inset->setMinimumSize((int)(1 * dpi), (int)(1 * dpi));
	m_pQVTK_side_inset->setMaximumSize((int)(1.5*dpi), (int)(1.5*dpi));
	m_pQVTK_side_inset->GetRenderWindow()->AddRenderer(m_pRenderer_side_inset);
	m_pRenderer_side_inset->SetBackground(0.8, 0.8, 0.8);
	m_pRenderer_side_inset->SetGradientBackground(true);

	vtkSmartPointer<vtkCamera> camera_side_inset = vtkSmartPointer<vtkCamera>::New();
	camera_side_inset->SetPosition(-inset_dist, 0, 0); // YZ Plane
	camera_side_inset->SetFocalPoint(0, 0, 0);
	camera_side_inset->SetViewUp(-1, 0, 0);
	camera_side_inset->SetClippingRange(-1500, 1500); // based on tracker workspace limits in x
	m_pRenderer_side_inset->SetActiveCamera(camera_side_inset);

}

void CI_Guidance::Initialize()
{
    QString AitFilename = QString::fromLocal8Bit("D:\\Trevor\\My Documents\\Code\\VTKtest\\vtk_test\\cad_roms\\AIT_noSplit.obj");
    QString guideTubeFilename = QString::fromLocal8Bit("D:\\Trevor\\My Documents\\Code\\VTKtest\\vtk_test\\cad_roms\\Hypo_Tube_18XT_MedElFlex.obj");
    QString probeFilename = QString::fromLocal8Bit("D:\\Trevor\\My Documents\\Code\\VTKtest\\vtk_test\\x64\\Release\\polaris_probe.obj");
    QString cochleaFilename = QString::fromLocal8Bit("D:\\Trevor\\My Documents\\MED lab\\Cochlear R01\\Code\\Magnetic Steering\\ImageData\\MagSteeringTest01\\structures_LPS\\MagSteeringTest01_Cochlea.stl");

    m_pActor_AitTarget = LoadOBJFile(AitFilename, 0.3, m_colorCiTarget.data());
    m_pRenderer_top->AddActor(m_pActor_AitTarget);
	//m_pRenderer_top_inset->AddActor(m_pActor_AitTarget);
	m_pRenderer_oblique->AddActor(m_pActor_AitTarget);
	m_pRenderer_front->AddActor(m_pActor_AitTarget);
	//m_pRenderer_front_inset->AddActor(m_pActor_AitTarget);
	m_pRenderer_side->AddActor(m_pActor_AitTarget);
	//m_pRenderer_side_inset->AddActor(m_pActor_AitTarget);

    m_pActor_guideTubeTarget = LoadOBJFile(guideTubeFilename, 1.0, m_colorCiTarget.data());
    m_pRenderer_top->AddActor(m_pActor_guideTubeTarget);
    m_pRenderer_top_inset->AddActor(m_pActor_guideTubeTarget);
    m_pRenderer_oblique->AddActor(m_pActor_guideTubeTarget);
    m_pRenderer_front->AddActor(m_pActor_guideTubeTarget);
    m_pRenderer_front_inset->AddActor(m_pActor_guideTubeTarget);
    m_pRenderer_side->AddActor(m_pActor_guideTubeTarget);
    m_pRenderer_side_inset->AddActor(m_pActor_guideTubeTarget);

    m_pActor_Ait = LoadOBJFile(AitFilename, 1.0, m_colorCiTool.data());
    m_pRenderer_top->AddActor(m_pActor_Ait);
    //m_pRenderer_top_inset->AddActor(m_pActor_Ait);
    m_pRenderer_oblique->AddActor(m_pActor_Ait);
    m_pRenderer_front->AddActor(m_pActor_Ait);
    //m_pRenderer_front_inset->AddActor(m_pActor_Ait);
    m_pRenderer_side->AddActor(m_pActor_Ait);
    //m_pRenderer_side_inset->AddActor(m_pActor_Ait);

    m_pActor_guideTube = LoadOBJFile(guideTubeFilename, 1.0, m_colorCiTool.data());
    m_pRenderer_top->AddActor(m_pActor_guideTube);
    m_pRenderer_top_inset->AddActor(m_pActor_guideTube);
    m_pRenderer_oblique->AddActor(m_pActor_guideTube);
    m_pRenderer_front->AddActor(m_pActor_guideTube);
    m_pRenderer_front_inset->AddActor(m_pActor_guideTube);
    m_pRenderer_side->AddActor(m_pActor_guideTube);
    m_pRenderer_side_inset->AddActor(m_pActor_guideTube);

	m_pActor_probe = LoadOBJFile(probeFilename, 1.0, m_colorProbe.data());
	m_pRenderer_top->AddActor(m_pActor_probe);
	m_pRenderer_oblique->AddActor(m_pActor_probe);
	m_pRenderer_front->AddActor(m_pActor_probe);
	m_pRenderer_side->AddActor(m_pActor_probe);

    m_pActor_cochlea = LoadSTLFile(cochleaFilename, 1.0, m_colorCochlea.data());
    /*m_pRenderer_top->AddActor(m_pActor_cochlea);
    m_pRenderer_top_inset->AddActor(m_pActor_cochlea);
    m_pRenderer_oblique->AddActor(m_pActor_cochlea);
    m_pRenderer_front->AddActor(m_pActor_cochlea);
    m_pRenderer_front_inset->AddActor(m_pActor_cochlea);
    m_pRenderer_side->AddActor(m_pActor_cochlea);
    m_pRenderer_side_inset->AddActor(m_pActor_cochlea);*/

    vtkSmartPointer<vtkSphereSource> sphereTemp = vtkSmartPointer<vtkSphereSource>::New();
    sphereTemp->SetCenter(0.0, 0.0, 0.0);
    sphereTemp->SetRadius(0.25);
    sphereTemp->SetThetaResolution(12);
    sphereTemp->SetPhiResolution(10);
    vtkSmartPointer<vtkPolyDataMapper> mapperTemp = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapperTemp->SetInputConnection(sphereTemp->GetOutputPort());

    m_pActor_target_current = vtkSmartPointer<vtkActor>::New();
    m_pActor_target_current->SetMapper(mapperTemp);
    m_pActor_target_current->GetProperty()->SetColor(m_colorCiTool.data());
    m_pRenderer_top->AddActor(m_pActor_target_current);
    m_pRenderer_top_inset->AddActor(m_pActor_target_current);
    m_pRenderer_oblique->AddActor(m_pActor_target_current);
    m_pRenderer_front->AddActor(m_pActor_target_current);
    m_pRenderer_front_inset->AddActor(m_pActor_target_current);
    m_pRenderer_side->AddActor(m_pActor_target_current);
    m_pRenderer_side_inset->AddActor(m_pActor_target_current);

    m_pActor_target_desired = vtkSmartPointer<vtkActor>::New();
    m_pActor_target_desired->SetMapper(mapperTemp);
    m_pActor_target_desired->GetProperty()->SetColor(m_colorCiTarget.data());
    m_pRenderer_top->AddActor(m_pActor_target_desired);
    m_pRenderer_top_inset->AddActor(m_pActor_target_desired);
    m_pRenderer_oblique->AddActor(m_pActor_target_desired);
    m_pRenderer_front->AddActor(m_pActor_target_desired);
    m_pRenderer_front_inset->AddActor(m_pActor_target_desired);
    m_pRenderer_side->AddActor(m_pActor_target_desired);
    m_pRenderer_side_inset->AddActor(m_pActor_target_desired);

    for (int i = 0; i < numFiducialActors; i++) {
        vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
        sphereSource->SetCenter(0.0, 0.0, 0.0);
        sphereSource->SetRadius(3.0);
        sphereSource->SetThetaResolution(14);
        sphereSource->SetPhiResolution(10);

        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(sphereSource->GetOutputPort());

        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        actor->GetProperty()->SetColor(m_colorStrays.data());
        actor->SetMapper(mapper);
        
        m_pActor_fiducials.push_back(actor);
        m_pRenderer_top->AddActor(m_pActor_fiducials.at(i));
        m_pRenderer_oblique->AddActor(m_pActor_fiducials.at(i));
        m_pRenderer_front->AddActor(m_pActor_fiducials.at(i));
        m_pRenderer_side->AddActor(m_pActor_fiducials.at(i));

        vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
        pvtk_T_fiducials.push_back(transform);
    }
    
    pvtk_T_tracker_probe = vtkSmartPointer<vtkTransform>::New();
    pvtk_T_tracker_ait = vtkSmartPointer<vtkTransform>::New();
    pvtk_T_tracker_AitTarget = vtkSmartPointer<vtkTransform>::New();
    pvtk_T_tracker_tube = vtkSmartPointer<vtkTransform>::New();
    pvtk_T_tracker_tubeTarget = vtkSmartPointer<vtkTransform>::New();

	slot_CenterView(QString("centerCItool"));
}

void CI_Guidance::slot_onGUITimer()
{
	// update QVTKWidgets
	m_pQVTK_top->update();
	m_pQVTK_top_inset->update();
	m_pQVTK_oblique->update();
	m_pQVTK_front->update();
	m_pQVTK_front_inset->update();
	m_pQVTK_side->update();
	m_pQVTK_side_inset->update();

	m_frames++;
}

void CI_Guidance::slot_refreshTracker(void)
{
    QVector<Eigen::Quaterniond> quat_Polaris;
    QVector<Eigen::Vector3d> p;
    QVector<Eigen::Matrix3d> R;
    QVector<Eigen::Matrix4d> T_tracker_tools;

    quat_Polaris.resize(NUM_TRACKED_TOOLS + 1); // 0 index not used in order to match with list in tracker.ini 
    p.resize(NUM_TRACKED_TOOLS + 1);
    R.resize(NUM_TRACKED_TOOLS + 1);
    T_tracker_tools.resize(NUM_TRACKED_TOOLS + 1);

    // query tracker
    std::vector<ToolInformationStruct> tools = m_tracker->GetTransformationsAndStrays();

    // tool transformations
    for (int toolnum = 1; toolnum <= NUM_TRACKED_TOOLS; toolnum++) {
        quat_Polaris[toolnum] = Eigen::Quaterniond(tools[toolnum].q0, tools[toolnum].qx, tools[toolnum].qy, tools[toolnum].qz);
        p[toolnum](0) = tools[toolnum].x;
        p[toolnum](1) = tools[toolnum].y;
        p[toolnum](2) = tools[toolnum].z;
    }

    // convert quaternion to rotation matrix and combine with translation into a transformation matrix
    for (int toolnum = 1; toolnum <= NUM_TRACKED_TOOLS; toolnum++) {
        R[toolnum] = quat_Polaris[toolnum].toRotationMatrix();
        T_tracker_tools[toolnum] = Eigen::Matrix4d::Identity();
        T_tracker_tools[toolnum].block<3, 3>(0, 0) = R[toolnum];
        T_tracker_tools[toolnum].block<3, 1>(0, 3) = p[toolnum];
    }

    // probe transform in tracker frame
    Matrix4d T_tracker_probe = T_tracker_tools[1];
    emit sgn_NewProbeTransform(T_tracker_probe);

    // automated insertion tool transform in tracker frame
    Matrix4d T_tracker_Ait   = T_tracker_tools[2]; 
    m_T_tracker_Ait = T_tracker_Ait;
    emit sgn_NewAitTransform(T_tracker_Ait);

    // T_tracker_tip: transform for the tip of the guide tube, in tracker frame
    Matrix4d T_tracker_tip = T_tracker_Ait * m_T_tool_tip;
    m_T_tracker_tip = T_tracker_tip;
    emit sgn_NewTubeTransform(T_tracker_tip);

    // stray markers positions
    Position3dStruct strayMarkersTemp[NO_STRAYMARKERS];
    quint8 numStrayMarkers = m_tracker->GetStrayMarkers(*strayMarkersTemp);
    if (numStrayMarkers > 0) {
        Eigen::Matrix3Xd strayMarkers(3, numStrayMarkers);
        for (qint32 i = 0; i < numStrayMarkers; ++i)
        {
            strayMarkers.col(i) << strayMarkersTemp[i].x,
                                   strayMarkersTemp[i].y,
                                   strayMarkersTemp[i].z;
        }

        emit sgn_NewFiducialPositions(strayMarkers, numStrayMarkers);
    }

    if (flag_SetTarget)
    {
        // update target actors
        m_T_tracker_target = m_T_tracker_tip;
        emit sgn_NewTubeTargetTransform(m_T_tracker_target); // target and tip of guide tube are coincident
        emit sgn_NewAitTargetTransform(T_tracker_Ait);

        // recenter view on target
        slot_CenterView(QString("centerCItarget"));

        // reset flag
        flag_SetTarget = FALSE;
    }

    // Update alignment error
    Update_err();

    emit sgn_NewProbePosition(m_probe_transform(0, 3), m_probe_transform(1, 3), m_probe_transform(2, 3));
    emit sgn_NewCIPosition(m_T_tracker_tip(0, 3), m_T_tracker_tip(1, 3), m_T_tracker_tip(2, 3));
    emit sgn_WriteData();
}

void CI_Guidance::slot_updateActorAit(Eigen::Matrix4d T_tracker_Ait)
{
    T_tracker_Ait.transposeInPlace();
    pvtk_T_tracker_ait->SetMatrix(T_tracker_Ait.data());
    m_pActor_Ait->SetUserTransform(pvtk_T_tracker_ait);
}

void CI_Guidance::slot_updateActorAitTarget(Eigen::Matrix4d T_tracker_AitTarget)
{
    T_tracker_AitTarget.transposeInPlace();
    pvtk_T_tracker_AitTarget->SetMatrix(T_tracker_AitTarget.data());
    m_pActor_AitTarget->SetUserTransform(pvtk_T_tracker_AitTarget);
}

void CI_Guidance::slot_updateActorTube(Eigen::Matrix4d T_tracker_tube)
{
    T_tracker_tube.transposeInPlace();
    pvtk_T_tracker_tube->SetMatrix(T_tracker_tube.data());

    m_pActor_guideTube->SetUserTransform(pvtk_T_tracker_tube);
    m_pActor_target_current->SetUserTransform(pvtk_T_tracker_tube); // target sphere is always at tip of guide tube
}

void CI_Guidance::slot_updateActorTubeTarget(Eigen::Matrix4d T_tracker_tubeTarget)
{
    T_tracker_tubeTarget.transposeInPlace();
    pvtk_T_tracker_tubeTarget->SetMatrix(T_tracker_tubeTarget.data());

    m_pActor_guideTubeTarget->SetUserTransform(pvtk_T_tracker_tubeTarget);
    m_pActor_target_desired->SetUserTransform(pvtk_T_tracker_tubeTarget); // target sphere is always at tip of guide tube
}

void CI_Guidance::slot_updateActorProbe(Eigen::Matrix4d T_tracker_probe)
{
    if (!hideProbe) {
        m_pActor_probe->SetVisibility(true);
        T_tracker_probe.transposeInPlace();
        pvtk_T_tracker_probe->SetMatrix(T_tracker_probe.data());
        m_pActor_probe->SetUserTransform(pvtk_T_tracker_probe);
    }
    else {
        m_pActor_probe->SetVisibility(false);
    }
}

void CI_Guidance::slot_updateActorCochlea(Eigen::Matrix4d T_tracker_ct)
{
    if (!hideCochlea) {
        m_pActor_cochlea->SetVisibility(true);
        T_tracker_ct.transposeInPlace();
        pvtk_T_tracker_ct->SetMatrix(T_tracker_ct.data());
        m_pActor_cochlea->SetUserTransform(pvtk_T_tracker_ct);
    }
    else {
        m_pActor_cochlea->SetVisibility(false);
    }
}

void CI_Guidance::slot_updateActorFiducials(Eigen::Matrix3Xd fiducials, quint8 numFiducials)
{
    // update fiducial actor positions
    for (int i = 0; i < qMin(numFiducialActors, numFiducials); i++) {
        Matrix4d T_fiducial = Eigen::Matrix4d::Identity();
        T_fiducial.block<3, 1>(0, 3) = fiducials.col(i);
        T_fiducial.transposeInPlace();
        pvtk_T_fiducials.at(i)->SetMatrix(T_fiducial.data());
        m_pActor_fiducials.at(i)->SetUserTransform(pvtk_T_fiducials.at(i));
    }
}

void CI_Guidance::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
	m_frameRateLabel.setGeometry( m_pQVTK_top->geometry() );
}

void CI_Guidance::slot_onFrameRateTimer()
{
	double rate = (double)m_frames*1000.0 / (double)FRAME_RATE_UPDATE_INTERVAL;
	m_frameRateLabel.setText( QString::number((int)rate).rightJustified(4,' ',false) );
	m_frames = 0;
}

void CI_Guidance::slot_onRegistration(Eigen::MatrixXd T)
{
	std::cout << T << std::endl;
}

void CI_Guidance::slot_CenterView(QString senderObjName)
{
	double cam_offset = 30; // distance to offset camera from focal point
    double inset_offset = 5;

    double targetx = m_T_tracker_target(0, 3);
    double targety = m_T_tracker_target(1, 3);
    double targetz = m_T_tracker_target(2, 3);
    
	// ensure view orientations are correct
    m_pRenderer_top->GetActiveCamera()->SetViewUp(0, 0, 1);
    m_pRenderer_front->GetActiveCamera()->SetViewUp(-1, 0, 0);
    m_pRenderer_side->GetActiveCamera()->SetViewUp(-1, 0, 0);

	// determine sender
	if (senderObjName == "centerCItool")
	{
		double toolx = m_T_tracker_Ait(0,3);
		double tooly = m_T_tracker_Ait(1,3);
		double toolz = m_T_tracker_Ait(2,3);

		m_pRenderer_top->GetActiveCamera()->SetPosition(toolx - cam_offset, tooly, toolz);
		m_pRenderer_top->GetActiveCamera()->SetFocalPoint(toolx, tooly, toolz);
		m_pRenderer_top->ResetCamera(m_pActor_Ait->GetBounds());

		m_pRenderer_front->GetActiveCamera()->SetPosition(toolx, tooly, toolz-cam_offset);
		m_pRenderer_front->GetActiveCamera()->SetFocalPoint(toolx, tooly, toolz);
		m_pRenderer_front->ResetCamera(m_pActor_Ait->GetBounds());
		
		m_pRenderer_side->GetActiveCamera()->SetPosition(toolx, tooly - cam_offset, toolz);
		m_pRenderer_side->GetActiveCamera()->SetFocalPoint(toolx, tooly, toolz);
		m_pRenderer_side->ResetCamera(m_pActor_Ait->GetBounds());

		m_pRenderer_oblique->GetActiveCamera()->SetFocalPoint(toolx, tooly, toolz);
		m_pRenderer_oblique->ResetCamera(m_pActor_Ait->GetBounds());
	}
	else if (senderObjName == "centerProbe")
	{
		double probex = m_probe_transform(0, 3);
		double probey = m_probe_transform(1, 3);
		double probez = m_probe_transform(2, 3);
		m_pRenderer_top->GetActiveCamera()->SetPosition(probex - cam_offset, probey, probez);
		m_pRenderer_top->GetActiveCamera()->SetFocalPoint(probex, probey, probez);
		m_pRenderer_top->ResetCamera(m_pActor_probe->GetBounds());

		m_pRenderer_front->GetActiveCamera()->SetPosition(probex, probey, probez - cam_offset);
		m_pRenderer_front->GetActiveCamera()->SetFocalPoint(probex, probey, probez);
		m_pRenderer_front->ResetCamera(m_pActor_probe->GetBounds());

		m_pRenderer_side->GetActiveCamera()->SetPosition(probex, probey - cam_offset, probez);
		m_pRenderer_side->GetActiveCamera()->SetFocalPoint(probex, probey, probez);
		m_pRenderer_side->ResetCamera(m_pActor_probe->GetBounds());

		m_pRenderer_oblique->GetActiveCamera()->SetFocalPoint(probex, probey, probez);
		m_pRenderer_oblique->ResetCamera(m_pActor_probe->GetBounds());
	}
	else if (senderObjName == "centerCItarget")
	{    
		m_pRenderer_top->GetActiveCamera()->SetPosition(targetx - cam_offset, targety, targetz);
		m_pRenderer_top->GetActiveCamera()->SetFocalPoint(targetx, targety,	targetz);
		m_pRenderer_top->ResetCamera(m_pActor_AitTarget->GetBounds());

		m_pRenderer_front->GetActiveCamera()->SetPosition(targetx, targety, targetz - cam_offset);
		m_pRenderer_front->GetActiveCamera()->SetFocalPoint(targetx, targety, targetz);
		m_pRenderer_front->ResetCamera(m_pActor_AitTarget->GetBounds());

		m_pRenderer_side->GetActiveCamera()->SetPosition(targetx, targety - cam_offset, targetz);
		m_pRenderer_side->GetActiveCamera()->SetFocalPoint(targetx, targety, targetz);
		m_pRenderer_side->ResetCamera(m_pActor_AitTarget->GetBounds());

		m_pRenderer_oblique->ResetCamera(m_pActor_AitTarget->GetBounds());
	}
	else
	{
		return; // no match for sender name
	}

	// increase size to fill window better
    double zoom = 1.0;
    m_pRenderer_top->GetActiveCamera()->Zoom(zoom);
    m_pRenderer_front->GetActiveCamera()->Zoom(zoom);
	m_pRenderer_side->GetActiveCamera()->Zoom(zoom);

	// center inset views (always centered on target)
	m_pRenderer_top_inset->GetActiveCamera()->SetPosition  (targetx - inset_offset, targety, targetz);
	m_pRenderer_front_inset->GetActiveCamera()->SetPosition(targetx, targety, targetz - inset_offset);
	m_pRenderer_side_inset->GetActiveCamera()->SetPosition (targetx, targety - inset_offset, targetz);

	m_pRenderer_top_inset->GetActiveCamera()->SetFocalPoint  (targetx, targety, targetz);
	m_pRenderer_front_inset->GetActiveCamera()->SetFocalPoint(targetx, targety, targetz);
	m_pRenderer_side_inset->GetActiveCamera()->SetFocalPoint (targetx, targety, targetz);

	m_pRenderer_top_inset->GetActiveCamera()->SetViewUp(0, 0, 1);
	m_pRenderer_front_inset->GetActiveCamera()->SetViewUp(-1, 0, 0);
	m_pRenderer_side_inset->GetActiveCamera()->SetViewUp(-1, 0, 0);


    m_pRenderer_top->ResetCameraClippingRange();
    m_pRenderer_top_inset->ResetCameraClippingRange();
    m_pRenderer_front->ResetCameraClippingRange();
    m_pRenderer_front_inset->ResetCameraClippingRange();
    m_pRenderer_oblique->ResetCameraClippingRange();
    m_pRenderer_side->ResetCameraClippingRange();
    m_pRenderer_side_inset->ResetCameraClippingRange();
}

void CI_Guidance::slot_CenterTarget()
{
	slot_CenterView("centerCItarget");
}

void CI_Guidance::slot_Load_Plan()
{
    // open file dialog and select trajectory plan
    QString fileName = QFileDialog::getOpenFileName(this, "Open Patient Data File", NULL, "CI Plan (*.ini);;All Files (*.*)");
    
    // parse patient data
    m_patientData = new patient_data(fileName);
    if (m_patientData->parse()) {
        planLoaded = true;
        emit sgn_NewFre(0); // signals to infowidget to make live tracking checkbox checkable
    }
    else {
        planLoaded = false;
    }
}

void CI_Guidance::slot_Pivot_Calibation()
{
    Pivot_Calibration pivotCalWidget;
    connect(this, SIGNAL(sgn_NewAitTransform(Eigen::Matrix4d)), &pivotCalWidget, SLOT(slot_onNewAitTransform(Eigen::Matrix4d)));

    pivotCalWidget.exec();

    // save the tip offset translation
    m_T_tool_tip.block<3, 1>(0, 3) = pivotCalWidget.tOffset();

    disconnect(this, SIGNAL(sgn_NewAitTransform(Matrix4d)), &pivotCalWidget, SLOT(slot_onNewAitTransform(Matrix4d)));
}

void CI_Guidance::slot_Update_Skull(Eigen::Matrix3Xd fiducials, quint8 numFiducials)
{
    // compute registration to find transformation that takes points in CT frame into the tracker frame
    // pts_tracker = T_tracker_ct * pts_ct
    RigidRegistration T_tracker_ct;
    pointRegisterOutliers(m_patientData->fiducials(), fiducials, T_tracker_ct);
    
    // reset all markers
    for (qint8 ii = 0; ii < numFiducialActors; ++ii) {
        m_pActor_fiducials.at(ii)->GetProperty()->SetColor(m_colorStrays.data());
        m_pActor_fiducials.at(ii)->SetVisibility(false);
    }

    // unhide detected markers
    for (qint8 ii = 0; ii < numFiducials; ++ii) {
        m_pActor_fiducials.at(ii)->SetVisibility(true);
    }

    // ensure FRE is valid (unitialized double is very small -> ~6e-15)
    if (T_tracker_ct.GetFRE() > 1e-5) {
        emit sgn_NewFre(T_tracker_ct.GetFRE());

        // if registration was successful, update target
        if (T_tracker_ct.GetFRE() <= 1.5) {
            Eigen::ArrayXi indexMatch = T_tracker_ct.GetIndexMatch();

            // set color for skull fiducials
            for (qint8 ii = 0; ii < indexMatch.size(); ++ii) {
                m_pActor_fiducials.at(indexMatch[ii])->GetProperty()->SetColor(m_colorFiducials.data());
            }

            SetTransformforCI_target(m_patientData, T_tracker_ct.GetTransform());
        }
        else {
        }
    }

    static bool firstTime = true;
    if (firstTime) {
        slot_CenterTarget();
        firstTime = false;
    }
    
}

void CI_Guidance::slot_LiveTracking(int state)
{
    if (planLoaded) {
        if (state) {
            connect(this, SIGNAL(sgn_NewFiducialPositions(Eigen::Matrix3Xd, quint8)), this, SLOT(slot_Update_Skull(Eigen::Matrix3Xd, quint8)));
        }
        else {
            disconnect(this, SIGNAL(sgn_NewFiducialPositions(Eigen::Matrix3Xd, quint8)), this, SLOT(slot_Update_Skull(Eigen::Matrix3Xd, quint8)));
        }
    }
}

void CI_Guidance::slot_Tracker_Stop() {
	ui.actionTracker_Init->setDisabled(false);
	ui.actionTracker_Stop->setDisabled(true);
	m_guiTimer.stop();
	m_tracker->StopTracking();
    m_trackerTimer.stop();
	isTracking = false;
}

void CI_Guidance::slot_Tracker_Init() {
	if (m_tracker != NULL)
		delete m_tracker;
	m_tracker = new NDIAuroraTracker(this->tracker_Port);
	cout << "Connecting to the tracker in port " << this->tracker_Port << "...." << endl;
	int result = m_tracker->InitializeSystem();
	if (result != 0) {
		result = m_tracker->StartTracking();
		if (result == 0)
			cout << "Error! The tracker can no track! " << endl;
		else {
			cout << "Working! Starting tracking!" << endl;
			m_guiTimer.start();
            m_trackerTimer.start();
			ui.actionTracker_Init->setDisabled(true);
			ui.actionTracker_Stop->setDisabled(false);
			isTracking = true;
		}
	}
	else
		cout << " ERROR! The tracker can not be initialized!" << endl;
}

void CI_Guidance::Update_err()
{
    // first check if a target pose has been set
    if (m_T_tracker_target.isZero(1e-3)) {
        return;
    }

	// transformation between tip of the AIT and the target, in the tip frame
    Matrix4d T_tip_target = m_T_tracker_tip.inverse().eval() * m_T_tracker_target;

	// Cartesian error in tip frame
	m_errors.x = T_tip_target(0,3);
	m_errors.y = T_tip_target(1,3);
	m_errors.z = T_tip_target(2,3);

	// errors tangential and perpendicular to trajectory axis (xhat)
	Vector2d radial(m_errors.y, m_errors.z);
	m_errors.radial = radial.norm();
	m_errors.axial = m_errors.x;

	// angular error between trajectory axes (x)
    // x_i = T_tip_target.block<3,1>(0,0);   dot(x_i,[1;0;0]) = x_i(0) = T_tip_target(0,0)
    m_errors.theta = acos(T_tip_target(0, 0)); // [rad]

	// Find axis of rotation corresponding to theta
	// (orthogonal to x_i and x_t)
	Vector3d axis_theta;
 	if (m_errors.theta != m_errors.theta) // test if NAN
	{
        m_errors.theta = 0;
		axis_theta = Vector3d::UnitY(); // arbitrary because theta = 0, just can't be NAN
	}
	else
	{
		axis_theta = T_tip_target.block<3,1>(0,0).cross(Vector3d::UnitX());
		axis_theta.normalize();
	}

	// Rotate to align x axes and make xy planes coplanar
	Matrix3d R_theta;
	R_theta = AngleAxisd(m_errors.theta, axis_theta);
	Matrix3d R_xalign = R_theta*T_tip_target.block<3, 3>(0, 0);

	// Find angular error about the x axis
	// dot product of y column and yhat is just R_xalign(1,1)
	m_errors.phi = acos(R_xalign(1, 1));

	/*cout << "CItarget:" << endl << m_T_tracker_target << endl;
	cout << "CItool:"	<< endl << m_T_tracker_Ait << endl;
	cout << "Hti:"		<< endl << Hti << endl;
	cout << "phi = "	<< (m_errors.phi*180.0 / M_PI) << endl;
	cout << "theta = "	<< (m_errors.theta*180.0 / M_PI) << endl << endl;*/

	emit sgn_err(m_errors.radial,100);
	emit sgn_err_ang(m_errors.theta);
}

void CI_Guidance::SetTransformforCI_target(patient_data * ref_patient_data, Eigen::Matrix4d T_tracker_ct)
{
    /* 
        We want to find T_tracker_tool: the transformation for the desired tool pose in the tracker frame
        T_tracker_tool = T_tracker_ct * T_ct_tool
        We know T_tracker_ct, so we just need T_ct_tool
    */

    /* T_ct_target: transformation for the target in the ct frame */
    // first we need R_ct_target, which aligns the AIT coordinate frame with the target coordinate frame (in CT space)
    Vector3d xAxis_target = ref_patient_data->target() - ref_patient_data->entry(); // AIT x-axis corresponds to trajectory axis
    xAxis_target = xAxis_target / xAxis_target.norm();

    Vector3d zAxis_target = ref_patient_data->orientation(); // AIT z-axis corresponds to electrode orientation
    zAxis_target = zAxis_target / zAxis_target.norm();

    Vector3d yAxis_target = zAxis_target.cross(xAxis_target); // create y-axis
    yAxis_target = yAxis_target / yAxis_target.norm();

    Matrix3d R_ct_target;
    R_ct_target.col(0) = xAxis_target;
    R_ct_target.col(1) = yAxis_target;
    R_ct_target.col(2) = zAxis_target;

    // assemble T_ct_target
    Eigen::Matrix4d T_ct_target = Eigen::Matrix4d::Identity();
    T_ct_target.block<3, 3>(0, 0) = R_ct_target;
    T_ct_target.block<3, 1>(0, 3) = ref_patient_data->target();


    /* T_target_tool: transformation to tool base in the target frame (same as the tube tip frame) */
    // T_target_tool = T_tip_tool = (T_tool_tip)^-1
    Eigen::Matrix4d T_target_tool = Eigen::Matrix4d::Identity();
    T_target_tool.block<3, 1>(0, 3) = -m_T_tool_tip.block<3,1>(0,3); // no rotation component so inverse is just negative translation component


    /* T_tracker_target: tranformation for the target point, in the tracker frame */
    m_T_tracker_target = T_tracker_ct * T_ct_target;
    emit sgn_NewTubeTargetTransform(m_T_tracker_target); // target and tip of guide tube are coincident


    /* T_tracker_tool: transformation for the desired tool pose, in the tracker frame */
    Eigen::Matrix4d T_tracker_AitTarget = m_T_tracker_target * T_target_tool;
    emit sgn_NewAitTargetTransform(T_tracker_AitTarget);
}

void CI_Guidance::SetTransformforCI_target(Eigen::MatrixXd T_target)
{
	vtkSmartPointer<vtkTransform> vtkT_CI = vtkSmartPointer<vtkTransform>::New();
	vtkT_CI->SetMatrix(T_target.data());
	m_pActor_AitTarget->SetUserTransform( vtkT_CI );
}

vtkSmartPointer<vtkActor> CI_Guidance::LoadOBJFile(QString const& str,double opacity, double color[3]) const
{
	vtkSmartPointer<vtkOBJReader> reader = vtkSmartPointer<vtkOBJReader>::New();
	reader->SetFileName( str.toLocal8Bit().data() );
    reader->Update();
	
	/*vtkSmartPointer<vtkTriangleFilter> tris = vtkSmartPointer<vtkTriangleFilter>::New();
	tris->SetInputConnection(reader->GetOutputPort());
	tris->GetOutput()->GlobalReleaseDataFlagOn();

	vtkSmartPointer<vtkStripper> stripper = vtkSmartPointer<vtkStripper>::New();
	stripper->SetInputConnection(tris->GetOutputPort());
	stripper->GetOutput()->GlobalReleaseDataFlagOn();*/

    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->DeepCopy(reader->GetOutput());

    // calculate normals
    vtkSmartPointer<vtkPolyDataNormals> normalGenerator = vtkSmartPointer<vtkPolyDataNormals>::New();
    normalGenerator->SetInputData(polyData);
    normalGenerator->ComputePointNormalsOn();
    normalGenerator->ComputeCellNormalsOn();
    normalGenerator->Update();

    polyData = normalGenerator->GetOutput();

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    //mapper->SetInputConnection(stripper->GetOutputPort());
    //mapper->SetInputConnection(reader->GetOutputPort());
    mapper->SetInputData(polyData);
    mapper->ReleaseDataFlagOn();

	vtkSmartPointer<vtkActor> pActor = vtkSmartPointer<vtkActor>::New();
	pActor->GetProperty()->SetOpacity(opacity);
	pActor->GetProperty()->SetColor(color);
	pActor->SetMapper(mapper);

	return pActor;
}

vtkSmartPointer<vtkActor> CI_Guidance::LoadSTLFile(QString const& str, double opacity, double color[3]) const
{
	vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(str.toLocal8Bit().data());

	vtkSmartPointer<vtkTriangleFilter> tris = vtkSmartPointer<vtkTriangleFilter>::New();
	tris->SetInputConnection(reader->GetOutputPort());
	tris->GetOutput()->GlobalReleaseDataFlagOn();

	vtkSmartPointer<vtkStripper> stripper = vtkSmartPointer<vtkStripper>::New();
	stripper->SetInputConnection(tris->GetOutputPort());
	stripper->GetOutput()->GlobalReleaseDataFlagOn();

    //vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    //polyData->DeepCopy(reader->GetOutput());

    //// calculate normals
    //vtkSmartPointer<vtkPolyDataNormals> normalGenerator = vtkSmartPointer<vtkPolyDataNormals>::New();
    //normalGenerator->SetInputData(polyData);
    //normalGenerator->ComputePointNormalsOn();
    //normalGenerator->ComputeCellNormalsOn();
    //normalGenerator->Update();

    //polyData = normalGenerator->GetOutput();

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(stripper->GetOutputPort());
    //mapper->SetInputData(polyData);
    mapper->ReleaseDataFlagOn();

    vtkSmartPointer<vtkActor> pActor = vtkSmartPointer<vtkActor>::New();
    pActor->GetProperty()->SetOpacity(opacity);
    pActor->GetProperty()->SetColor(color);
    pActor->SetMapper(mapper);

	return pActor;
}

void CI_Guidance::slot_Register_Patient()
{
	// open file dialog and select patient trajectory plan
    QString fileName = QFileDialog::getOpenFileName(this, "Open Patient Data File", NULL, "CI Plan (*.ini);;All Files (*.*)");

	// parse patient data
    m_patientData = new patient_data(fileName);
    if (m_patientData->parse()) {
        planLoaded = true;
    }
    else {
        planLoaded = false;
    }

	Pat_Reg_Widget Pat_Reg_Widget(*m_patientData);
	connect(this, SIGNAL(sgn_NewProbePosition(double,double,double) ), &Pat_Reg_Widget, SLOT(slot_onNewProbePosition(double,double,double)));
    connect(this, SIGNAL(sgn_NewFiducialPositions(Eigen::Matrix3Xd, quint8)), &Pat_Reg_Widget, SLOT(slot_onNewFiducialPositions(Eigen::Matrix3Xd, quint8)));

    Pat_Reg_Widget.exec();
	RigidRegistration reg = Pat_Reg_Widget.GetRegistration();

    disconnect(this, SIGNAL(sgn_NewProbePosition(double, double, double)), &Pat_Reg_Widget, SLOT(slot_onNewProbePosition(double, double, double)));
    disconnect(this, SIGNAL(sgn_NewFiducialPositions(Eigen::Matrix3Xd, quint8)), &Pat_Reg_Widget, SLOT(slot_onNewFiducialPositions(Eigen::Matrix3Xd, quint8)));

	SetTransformforCI_target(m_patientData, reg.GetTransform());
}

void CI_Guidance::slot_update_COM(int thePort) {
	this->tracker_Port = thePort;
	QString trackerText = "Init Port " + QString::number(this->tracker_Port + 1);
	ui.actionTracker_Init->setText(trackerText);
}

void CI_Guidance::slot_Tracker_Setup()
{
	// ensure we are not creating duplicates
	if (pTrackerSetup != NULL)
	{
		delete pTrackerSetup;
	}
	pTrackerSetup = new TrackerSetup(this->tracker_Port, this);
	pTrackerSetup->show();
}

void CI_Guidance::slot_Demo()
{
	// ensure we are not creating duplicates
	if(pDemo_Widget != NULL)
	{
		delete pDemo_Widget;
	}
	pDemo_Widget = new Demo_Widget();

	// connect signals from Demo_Widget to slots in CI_Guidance
	connect(pDemo_Widget, SIGNAL(sgn_SetTarget()),	  this, SLOT(slot_SetTarget()));
	connect(pDemo_Widget, SIGNAL(sgn_DatalogStart()), this, SLOT(slot_DatalogStart()));
	connect(pDemo_Widget, SIGNAL(sgn_DatalogStop()),  this, SLOT(slot_DatalogStop()));

	// open dialog
	pDemo_Widget->setModal(false);
	pDemo_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
	pDemo_Widget->show();
}

void CI_Guidance::slot_SetTarget()
{
	flag_SetTarget = TRUE;
}

void CI_Guidance::slot_DatalogStart()
{
	// create time-stamped filename
	QString filename = QDate::currentDate().toString("yyyy-MM-dd");
	QString time = QTime::currentTime().toString("_hh-mm");
	filename.append(time);
	filename.append(QString(".csv"));

	// open file
	pDatalogFile = new QFile(filename);
	pDatalogFile->open(QIODevice::WriteOnly);

	// ensure file opened ok
	if(!pDatalogFile->isOpen()){
		cout << "Error opening file";
		return;
	}

	// write header
	QTextStream datalogStream(pDatalogFile);
	datalogStream << "elapsed time [ms], x [mm], y [mm], z [mm], radial [mm], axial [mm], theta [rad], phi [rad]\n";
	//datalogStream << "elapsed time [ms], error [mm]\n";
	
	// start timer
	m_datalogTimer.start();

	// enable datalogging
	connect(this, SIGNAL(sgn_WriteData()), this, SLOT(slot_WriteData()));
	//connect(this, SIGNAL(sgn_err(double,double)), this, SLOT(slot_WriteData(double,double)));

	// Note: file is automatically closed when program is terminated
}

void CI_Guidance::slot_DatalogStop()
{
	// stop datalogging
	disconnect(this, SIGNAL(sgn_WriteData()), this, SLOT(slot_WriteData()));
	//disconnect(this, SIGNAL(sgn_err(double,double)), this, SLOT(slot_WriteData(double,double)));

	// close file
	if(pDatalogFile != NULL){
		if(pDatalogFile->isOpen()){
			pDatalogFile->close();
		}
	}
}

void CI_Guidance::slot_WriteData(double err_ci, double err_mag)
{	// legacy method- do not use!!

	// write next line
	QTextStream datalogStream(pDatalogFile);
	datalogStream << QString::number(m_datalogTimer.elapsed()) << ", " << QString::number(err_ci) << endl;
}

void CI_Guidance::slot_WriteData()
{
	// write next line
	QTextStream datalogStream(pDatalogFile);
	datalogStream << QString::number(m_datalogTimer.elapsed()) << ", " 
				  << QString::number(m_errors.x) << ", "
				  << QString::number(m_errors.y) << ", "
				  << QString::number(m_errors.z) << ", "
				  << QString::number(m_errors.radial) << ", "
				  << QString::number(m_errors.axial) << ", "
				  << QString::number(m_errors.theta) << ", "
				  << QString::number(m_errors.phi)	 << endl;
}