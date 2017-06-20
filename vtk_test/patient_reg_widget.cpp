#include "patient_reg_widget.h"
#include "ui_patient_registration.h"
#include <qdialog.h>
#include <qtimer.h>
#include <qdebug.h>
#include <qelapsedtimer.h>
#include "patient_data.h"
#include <Eigen/dense>
#include "rigidregistration.h"
#include <algorithm>


const static int WAIT_TIME = 3;
const static int DATA_COUNT = 200;

Pat_Reg_Widget::Pat_Reg_Widget(const patient_data & ref_patient_data, QWidget *parent)
	: QDialog(parent),
    m_maxPossibleStrays(15),
    m_matchingTolerance(6.0),
	ui(new Ui::PatientRegistration),
	m_DataState( NOT_COLLECTING ),
	m_ticks(0),
	m_patient_data(ref_patient_data)
{
    m_AverageSkull.reserve(m_maxPossibleStrays);

	ui->setupUi(this);

	connect(ui->button_mk1_collection, SIGNAL(clicked()), this, SLOT(slot_onButton1Clicked()));
	connect(ui->button_mk2_collection, SIGNAL(clicked()), this, SLOT(slot_onButton2Clicked()));
	connect(ui->button_mk3_collection, SIGNAL(clicked()), this, SLOT(slot_onButton3Clicked()));
    connect(ui->button_skull_collection, SIGNAL(clicked()), this, SLOT(slot_onButtonSkullClicked()));
	connect(ui->button_finish, SIGNAL(clicked()), this, SLOT(slot_onRegister()));
}

Pat_Reg_Widget::~Pat_Reg_Widget()
{
	delete ui;
}

void Pat_Reg_Widget::StartCollection1()
{
	m_DataState = COLLECTING_1;
}

void Pat_Reg_Widget::StartCollection2()
{
	m_DataState = COLLECTING_2;
}

void Pat_Reg_Widget::StartCollection3()
{
	m_DataState = COLLECTING_3;
}

void Pat_Reg_Widget::StartCollectionSkull()
{
    m_DataState = COLLECTING_SKULL;
}

void Pat_Reg_Widget::slot_onTimer1()
{
	if (++m_ticks == WAIT_TIME) {
		ui->label_mk1_msg->setText( QString("Collecting...") );
		disconnect( &m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimer1()));
		StartCollection1();
	} else {
		ui->label_mk1_msg->setText( QString("Collecting in ") + QString::number(WAIT_TIME-m_ticks) + QString(" seconds") );
		m_timer.setInterval(1000);
		m_timer.setSingleShot(true);
		m_timer.start();
	}
}

void Pat_Reg_Widget::slot_onTimer2()
{
	if (++m_ticks == WAIT_TIME) {
		ui->label_mk2_msg->setText( QString("Collecting...") );
		disconnect( &m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimer2()));
		StartCollection2();
	} else {
		ui->label_mk2_msg->setText( QString("Collecting in ") + QString::number(WAIT_TIME-m_ticks) + QString(" seconds") );
		m_timer.setInterval(1000);
		m_timer.setSingleShot(true);
		m_timer.start();
	}
}

void Pat_Reg_Widget::slot_onTimer3()
{
	if (++m_ticks == WAIT_TIME) {
		ui->label_mk3_msg->setText( QString("Collecting...") );
		disconnect( &m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimer3()));
		StartCollection3();
	} else {
		ui->label_mk3_msg->setText( QString("Collecting in ") + QString::number(WAIT_TIME-m_ticks) + QString(" seconds") );
		m_timer.setInterval(1000);
		m_timer.setSingleShot(true);
		m_timer.start();
	}
}

void Pat_Reg_Widget::slot_onTimerSkull()
{
    if (++m_ticks == WAIT_TIME) {
        ui->label_skull_msg->setText(QString("Collecting..."));
        disconnect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimerSkull()));
        StartCollectionSkull();
    }
    else {
        ui->label_skull_msg->setText(QString("Collecting in ") + QString::number(WAIT_TIME - m_ticks) + QString(" seconds"));
        m_timer.setInterval(1000);
        m_timer.setSingleShot(true);
        m_timer.start();
    }
}

Pat_Reg_Widget::DataCollectingState Pat_Reg_Widget::Collect1(double x, double y, double z)
{
	m_AverageMk1.AddMeasurement(x,y,z);
	ui->progressBar_mk1->setValue( m_AverageMk1.count() );
	ui->label_mk1_x->setText( QString::number(x, 'f', 1).rightJustified( 8, ' ', false ) );
	ui->label_mk1_y->setText( QString::number(y, 'f', 1).rightJustified( 8, ' ', false ) );
	ui->label_mk1_z->setText( QString::number(z, 'f', 1).rightJustified( 8, ' ', false ) );

	if (m_AverageMk1.count() == DATA_COUNT) {
		ui->label_mk1_msg->setText( QString("Finished Collecting") );
		std::tuple<double,double,double> xyz = m_AverageMk1.GetAverage();
		ui->label_mk1_x->setText( QString::number(std::get<0>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		ui->label_mk1_y->setText( QString::number(std::get<1>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		ui->label_mk1_z->setText( QString::number(std::get<2>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		return Pat_Reg_Widget::NOT_COLLECTING;
	} else {
		return Pat_Reg_Widget::COLLECTING_1;
	}
}

Pat_Reg_Widget::DataCollectingState Pat_Reg_Widget::Collect2(double x, double y, double z)
{
	m_AverageMk2.AddMeasurement(x,y,z);
	ui->progressBar_mk2->setValue( m_AverageMk2.count() );
	ui->label_mk2_x->setText( QString::number(x, 'f', 1).rightJustified( 8, ' ', false ) );
	ui->label_mk2_y->setText( QString::number(y, 'f', 1).rightJustified( 8, ' ', false ) );
	ui->label_mk2_z->setText( QString::number(z, 'f', 1).rightJustified( 8, ' ', false ) );

	if (m_AverageMk2.count() == DATA_COUNT) {
		ui->label_mk2_msg->setText( QString("Finished Collecting") );
		std::tuple<double,double,double> xyz = m_AverageMk2.GetAverage();
		ui->label_mk2_x->setText( QString::number(std::get<0>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		ui->label_mk2_y->setText( QString::number(std::get<1>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		ui->label_mk2_z->setText( QString::number(std::get<2>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		return Pat_Reg_Widget::NOT_COLLECTING;
	} else {
		return Pat_Reg_Widget::COLLECTING_2;
	}
}

Pat_Reg_Widget::DataCollectingState Pat_Reg_Widget::Collect3(double x, double y, double z)
{
	m_AverageMk3.AddMeasurement(x,y,z);
	ui->progressBar_mk3->setValue( m_AverageMk3.count() );
	ui->label_mk3_x->setText( QString::number(x, 'f', 1).rightJustified( 8, ' ', false ) );
	ui->label_mk3_y->setText( QString::number(y, 'f', 1).rightJustified( 8, ' ', false ) );
	ui->label_mk3_z->setText( QString::number(z, 'f', 1).rightJustified( 8, ' ', false ) );

	if (m_AverageMk3.count() == DATA_COUNT) {
		ui->label_mk3_msg->setText( QString("Finished Collecting") );
		std::tuple<double,double,double> xyz = m_AverageMk3.GetAverage();
		ui->label_mk3_x->setText( QString::number(std::get<0>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		ui->label_mk3_y->setText( QString::number(std::get<1>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		ui->label_mk3_z->setText( QString::number(std::get<2>(xyz), 'f', 1).rightJustified( 8, ' ', false ) );
		return Pat_Reg_Widget::NOT_COLLECTING;
	} else {
		return Pat_Reg_Widget::COLLECTING_3;
	}
}

Pat_Reg_Widget::DataCollectingState Pat_Reg_Widget::CollectSkull(Eigen::Matrix3Xd fiducials)
{
    qint8 numFiducials = fiducials.cols(); // number of potential fiducials detected in the latest frame (i.e. total stray markers)

    /* stray markers are not reported in a uniquely identifiable way so we must first determine correspondence */
    /* NOTE: not designed to handle a changing number of stray markers during collection! */

    // if this is the first collection, initialize m_AverageSkull with current values
    if (m_AverageSkull.at(0).count() == 0) { 
        for (qint8 i = 0; i < numFiducials; ++i){
            m_AverageSkull[i].AddMeasurement(fiducials(0, i), fiducials(1, i), fiducials(2, i));
        }
    }
    // otherwise, check if a corresponding m_AverageSkull instance already exists
    else {
        for (qint8 i = 0; i < numFiducials; ++i) {
            // check marker in same position (i) first
            if (isMatch(fiducials.col(i), m_AverageSkull.at(i).GetAverageVector3d(), m_matchingTolerance)) { 
                m_AverageSkull[i].AddMeasurement(fiducials(0, i), fiducials(1, i), fiducials(2, i));
            }
            // if no match, check all others
            else {
                for (qint8 j = 0; j < m_AverageSkull.size(); ++j) {
                    if (isMatch(fiducials.col(i), m_AverageSkull.at(j).GetAverageVector3d(), m_matchingTolerance)) {
                        m_AverageSkull[j].AddMeasurement(fiducials(0, i), fiducials(1, i), fiducials(2, i));
                        break; // stop once match is found
                    }
                }
            }
        }
    }

    ui->progressBar_skull->setValue(m_AverageSkull.at(0).count());

    if (m_AverageSkull.at(0).count() == DATA_COUNT) {

        // update label
        ui->label_skull_msg->setText(QString("Finished Collecting"));

        // perform registration
        QElapsedTimer regTime;
        regTime.start();
        RegisterSkull();
        qDebug() << "Registration took " << regTime.elapsed() << "ms";

        return Pat_Reg_Widget::NOT_COLLECTING;
    }
    else {
        return Pat_Reg_Widget::COLLECTING_SKULL;
    }
}

bool Pat_Reg_Widget::isDataValid(double x, double y, double z)
{
	if (x == 0 && y == 0 && z == 0)
		return false;
	else
		return true;
}

bool Pat_Reg_Widget::isDataValid(Eigen::Matrix3Xd testMatrix)
{
    // must not be all zeros AND must have at least as many fiducials as expected
    if (!testMatrix.isZero(1e-5) && (testMatrix.cols() >= m_patient_data.fiducials().cols()) )
        return true;
    else
        return false;
}

bool Pat_Reg_Widget::isMatch(Eigen::Vector3d point1, Eigen::Vector3d point2, double matchingTolerance)
{
    Eigen::Vector3d diff = point1 - point2;

    return (diff.norm() <= matchingTolerance);
}

void Pat_Reg_Widget::slot_onNewProbePosition(double x, double y, double z)
{
	if(!isDataValid(x,y,z))
		return;

	switch (m_DataState) {
	case NOT_COLLECTING:
		break;
	case COLLECTING_1:
		m_DataState = Collect1(x,y,z);
		break;
	case COLLECTING_2:
		m_DataState = Collect2(x,y,z);
		break;
	case COLLECTING_3:
		m_DataState = Collect3(x,y,z);
		break;
	default:
		break;
	}
}

void Pat_Reg_Widget::slot_onNewFiducialPositions(Eigen::Matrix3Xd & fiducials, int numFiducials)
{
    Eigen::Matrix3Xd fiducialsTrimmed = fiducials.block(0,0, 3, numFiducials); // remove extra columns

    if (!isDataValid(fiducialsTrimmed))
        return;
    else if (m_DataState == COLLECTING_SKULL)
        m_DataState = CollectSkull(fiducialsTrimmed);
    else
        return;
}

void Pat_Reg_Widget::slot_onButton1Clicked()
{
	if ( m_DataState == NOT_COLLECTING ) {
		ui->progressBar_mk1->setValue(0);
		m_AverageMk1 = PositionAverage();
		m_ticks = 0;
		m_timer.setInterval(1000);
		m_timer.setSingleShot(true);
		ui->label_mk1_msg->setText( QString("Collecting in ") + QString::number(WAIT_TIME) + QString(" seconds") );
		connect( &m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimer1()));
		m_timer.start();
	}
}

void Pat_Reg_Widget::slot_onButton2Clicked()
{
	if ( m_DataState == NOT_COLLECTING ) {
		ui->progressBar_mk2->setValue(0);
		m_AverageMk2 = PositionAverage();
		m_ticks = 0;
		m_timer.setInterval(1000);
		m_timer.setSingleShot(true);
		ui->label_mk2_msg->setText( QString("Collecting in ") + QString::number(WAIT_TIME) + QString(" seconds") );
		connect( &m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimer2()));
		m_timer.start();
	}
}

void Pat_Reg_Widget::slot_onButton3Clicked()
{
	if ( m_DataState == NOT_COLLECTING ) {
		ui->progressBar_mk3->setValue(0);
		m_AverageMk3 = PositionAverage();
		m_ticks = 0;
		m_timer.setInterval(1000);
		m_timer.setSingleShot(true);
		ui->label_mk3_msg->setText( QString("Collecting in ") + QString::number(WAIT_TIME) + QString(" seconds") );
		connect( &m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimer3()));
		m_timer.start();
	}
}

void Pat_Reg_Widget::slot_onButtonSkullClicked()
{
    if (m_DataState == NOT_COLLECTING) {
        disconnect(ui->button_finish, SIGNAL(clicked()), this, SLOT(slot_onRegister())); // registration performed automatically after collection is finished

        m_AverageSkull.clear(); // reset any previously collected data
        for (qint8 i = 0; i < m_maxPossibleStrays; ++i)
        {
            m_AverageSkull.push_back(PositionAverage());
        }
        ui->progressBar_skull->setValue(0);
        m_ticks = 0;
        m_timer.setInterval(1000);
        m_timer.setSingleShot(true);
        ui->label_skull_msg->setText(QString("Collecting in ") + QString::number(WAIT_TIME) + QString(" seconds"));
        connect(&m_timer, SIGNAL(timeout()), this, SLOT(slot_onTimerSkull()));
        m_timer.start();
    }
}

void Pat_Reg_Widget::slot_onRegister()
{
	RegisterCollectedData(m_patient_data);
}

RigidRegistration Pat_Reg_Widget::GetRegistration() const
{
	return m_registration;
}

void Pat_Reg_Widget::slot_onSaveandFinish()
{
}

Eigen::Vector3d TupleToVector(std::tuple<double,double,double> x)
{
	return Eigen::Vector3d( std::get<0>(x), std::get<1>(x), std::get<2>(x) );
}

void Pat_Reg_Widget::RegisterCollectedData(const patient_data & ref_patient_data)
{
    Eigen::Matrix3Xd fiducials = ref_patient_data.fiducials();
    Eigen::MatrixXd collected_data(3, 3);
    collected_data.row(0) = TupleToVector(m_AverageMk1.GetAverage());
    collected_data.row(1) = TupleToVector(m_AverageMk2.GetAverage());
    collected_data.row(2) = TupleToVector(m_AverageMk3.GetAverage());

    pointRegister(fiducials.transpose(), collected_data.transpose(), m_registration); // function requires each point to be a column, thus transpose

    ui->label_registration_msg->setText(QString("Registered with FRE = ") + QString::number(m_registration.GetFRE(), 'f', 2) + QString("mm"));

    if (m_registration.GetFRE() <= 1.0) {
        QPixmap greencheck(":/images/Resources/greencheck_small.png");
        ui->label_registration_check->setPixmap(greencheck);
        ui->button_finish->setText("Save and Finish");
        disconnect(ui->button_finish, SIGNAL(clicked()), this, SLOT(slot_onRegister()));
        connect(ui->button_finish, SIGNAL(clicked()), this, SLOT(close()));
    }
    else {
        QPixmap greencheck(":/images/Resources/redX_small.png");
        ui->label_registration_check->setPixmap(greencheck);
    }

}

void Pat_Reg_Widget::RegisterSkull()
{
    // determine number of markers
    qint8 numMarkers;
    for (qint8 ii = 0; ii < m_AverageSkull.size(); ++ii)
    {
        if (m_AverageSkull.at(ii).count() == 0) {
            numMarkers = ii;
            break;
        }
    }

    // assemble matrix of the detected markers
    Eigen::Matrix3Xd markers(3, numMarkers);
    for (qint8 ii = 0; ii < numMarkers; ++ii)
    {
        markers.col(ii) = m_AverageSkull.at(ii).GetAverageVector3d();
    }

    Eigen::Matrix3Xd fiducials = m_patient_data.fiducials();

    // compute registration
    pointRegisterOutliers(fiducials, markers, m_registration);

    // update labels
    ui->label_registration_msg->setText(QString("Registered with FRE = ") + QString::number(m_registration.GetFRE(), 'f', 2) + QString("mm"));

    if (m_registration.GetFRE() <= 0.6) {
        QPixmap greencheck(":/images/Resources/greencheck_small.png");
        ui->label_registration_check->setPixmap(greencheck);
        ui->button_finish->setText("Save and Finish");
        disconnect(ui->button_finish, SIGNAL(clicked()), this, SLOT(slot_onRegister()));
        connect(ui->button_finish, SIGNAL(clicked()), this, SLOT(close()));
    }
    else {
        QPixmap greencheck(":/images/Resources/redX_small.png");
        ui->label_registration_check->setPixmap(greencheck);
    }
}

//void Pat_Reg_Widget::RegisterCollectedData(const patient_data & ref_patient_data)
//{
//    Eigen::MatrixXd ref_patient_mat = ref_patient_data.GetMarkers();
//    Eigen::MatrixXd collected_data(3, 3);
//    collected_data.row(0) = TupleToVector(m_AverageMk1.GetAverage());
//    collected_data.row(1) = TupleToVector(m_AverageMk2.GetAverage());
//    collected_data.row(2) = TupleToVector(m_AverageMk3.GetAverage());
//
//    point_register(ref_patient_mat.transpose(), collected_data.transpose(), m_registration); // function requires each point to be a column, thus transpose
//
//    ui->label_registration_msg->setText(QString("Registered with FRE = ") + QString::number(m_registration.GetFRE(), 'f', 2) + QString("mm"));
//
//    if (m_registration.GetFRE() <= 0.4) {
//        QPixmap greencheck(":/images/Resources/greencheck_small.png");
//        ui->label_registration_check->setPixmap(greencheck);
//        ui->button_finish->setText("Save and Finish");
//        disconnect(ui->button_finish, SIGNAL(clicked()), this, SLOT(slot_onRegister()));
//        connect(ui->button_finish, SIGNAL(clicked()), this, SLOT(close()));
//    }
//    else {
//        QPixmap greencheck(":/images/Resources/redX_small.png");
//        ui->label_registration_check->setPixmap(greencheck);
//    }
//
//}
