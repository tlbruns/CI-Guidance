#include "patient_data.h"
#include "Eigen/dense"
#include <qsettings.h>
#include <qvector.h>
#include <qvector3d.h>

Eigen::Vector3d Tuple2Vector(std::tuple<double,double,double> x)	// already defined (TupleToVector) in patient_reg_widget.cpp
{                                                                   // bad form, fix this later!!
	return Eigen::Vector3d( std::get<0>(x), std::get<1>(x), std::get<2>(x) );
}

patient_data::patient_data(void) :
	m_patientdata(5,3)
{
	//std::tuple<double,double,double> mk1 = std::make_tuple(275.9,-411.7,1314.8);
	//std::tuple<double,double,double> mk2 = std::make_tuple(289.4,-441.0,1376.5);
	//std::tuple<double,double,double> mk3 = std::make_tuple(340.5,-435.3,1329.0);
	//std::tuple<double,double,double> target = std::make_tuple(295.5,-479.6, 1329.9);
	//std::tuple<double,double,double> entry = std::make_tuple(295.90, -476.6, 1331.0);
	std::tuple<double,double,double> mk1 = std::make_tuple(35.2, -221.9, 1604);	  // test
	std::tuple<double,double,double> mk2 = std::make_tuple(103.6, -217.3, 1594.2);	  // test
	std::tuple<double,double,double> mk3 = std::make_tuple(61.4, -222.2, 1539.3);	  // test
	std::tuple<double,double,double> target = std::make_tuple(62.7, -248.7, 1569.8); // test
	std::tuple<double,double,double> entry = std::make_tuple(62.3, -240.6, 1572.6);  // test
	

	m_patientdata.row(0) = (Tuple2Vector(mk1));
	m_patientdata.row(1) = (Tuple2Vector(mk2));
	m_patientdata.row(2) = (Tuple2Vector(mk3));
	m_patientdata.row(3) = (Tuple2Vector(target));
	m_patientdata.row(4) = (Tuple2Vector(entry));
}

patient_data::patient_data(QString filename) :
    iniFileName(filename)
{
}


patient_data::~patient_data(void)
{
}

bool patient_data::parse(void)
{
    QSettings iniFile(iniFileName, QSettings::IniFormat);

    // check that file is correct format
    QStringList keys = iniFile.allKeys();


    // parse file and save data
    m_id = iniFile.value("header/ID").toInt();

    m_date.fromString(iniFile.value("header/date").toString());

    m_target.setX(iniFile.value("plan/target/x").toFloat());
    m_target.setY(iniFile.value("plan/target/y").toFloat());
    m_target.setZ(iniFile.value("plan/target/z").toFloat());    

    m_axis.setX(iniFile.value("plan/axis/x").toFloat());
    m_axis.setY(iniFile.value("plan/axis/y").toFloat());
    m_axis.setZ(iniFile.value("plan/axis/z").toFloat());

    quint32 arraySize = iniFile.beginReadArray("plan/fiducials");
    m_fiducials.reserve(arraySize);
    for (qint32 i = 0; i < arraySize; ++i)
    {
        iniFile.setArrayIndex(i);
        m_fiducials.push_back(QVector3D(iniFile.value("x").toFloat(), iniFile.value("y").toFloat(), iniFile.value("z").toFloat()));
    }
    iniFile.endArray();

    arraySize = iniFile.beginReadArray("plan/trajectory");
    m_fiducials.reserve(arraySize);
    for (qint32 i = 0; i < arraySize; ++i)
    {
        iniFile.setArrayIndex(i);
        m_trajectory.push_back(QVector3D(iniFile.value("x").toFloat(), iniFile.value("y").toFloat(), iniFile.value("z").toFloat()));
    }
    iniFile.endArray();


    // legacy format
    m_patientdata.row(0) = Eigen::Vector3d((double)fiducials().at(0).x(), (double)fiducials().at(0).y(), (double)fiducials().at(0).z());
    m_patientdata.row(1) = Eigen::Vector3d(fiducials().at(1).x(), fiducials().at(1).y(), fiducials().at(1).z());
    m_patientdata.row(2) = Eigen::Vector3d(fiducials().at(2).x(), fiducials().at(2).y(), fiducials().at(2).z());
    m_patientdata.row(3) = Eigen::Vector3d(target().x(), target().y(), target().z());
    m_patientdata.row(4) = Eigen::Vector3d(axis().x(), axis().y(), axis().z());

    return true;
}

quint32 patient_data::id()
{
    return m_id;
}

QDate patient_data::date()
{
    return m_date;
}

QVector<QVector3D> patient_data::fiducials()
{
    return m_fiducials;
}

QVector<QVector3D> patient_data::trajectory()
{
    return m_trajectory;
}

QVector3D patient_data::target()
{
    return m_target;
}

QVector3D patient_data::axis()
{
    return m_axis;
}

Eigen::MatrixXd patient_data::GetPatientData() const
{
	return m_patientdata;
}

Eigen::MatrixXd patient_data::GetMarkers() const
{
	return m_patientdata.block<3,3>(0,0);
}

Eigen::MatrixXd patient_data::GetTraj() const
{
	return m_patientdata.block<2,3>(3,0);
}

Eigen::MatrixXd patient_data::GetTarget() const
{
	return m_patientdata.row(3);
}

Eigen::MatrixXd patient_data::GetEntry() const
{
	return m_patientdata.row(4);
}

void patient_data::SetPatientData(Eigen::MatrixXd x)
{
	m_patientdata = x;
}
