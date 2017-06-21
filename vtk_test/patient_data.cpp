#include "patient_data.h"
#include "Eigen/dense"
#include <qsettings.h>
#include <qvector.h>


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

    m_target << iniFile.value("plan/target/x").toDouble(),
                iniFile.value("plan/target/y").toDouble(),
                iniFile.value("plan/target/z").toDouble();
    m_offset =  iniFile.value("plan/target/offset").toDouble();

    m_entry << iniFile.value("plan/entry/x").toDouble(),
               iniFile.value("plan/entry/y").toDouble(),
               iniFile.value("plan/entry/z").toDouble();

    if (m_target.isZero(1e-5) | m_offset == 0 | m_entry.isZero(1e-5)) {
        return false;
    }

    quint32 arraySize = iniFile.beginReadArray("plan/fiducials");
    m_fiducials.resize(Eigen::NoChange, arraySize); // resize to 3-by-arraySize
    for (qint32 i = 0; i < arraySize; ++i)
    {
        iniFile.setArrayIndex(i);
        m_fiducials.col(i) << iniFile.value("x").toDouble(),
                              iniFile.value("y").toDouble(),
                              iniFile.value("z").toDouble();
    }
    iniFile.endArray();

    arraySize = iniFile.beginReadArray("plan/trajectory");
    m_trajectory.resize(Eigen::NoChange, arraySize);
    for (qint32 i = 0; i < arraySize; ++i)
    {
        iniFile.setArrayIndex(i);
        m_trajectory.col(i) << iniFile.value("x").toDouble(),
                               iniFile.value("y").toDouble(),
                               iniFile.value("z").toDouble();
    }
    iniFile.endArray();

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

Eigen::Matrix3Xd patient_data::fiducials() const
{
    return m_fiducials;
}

Eigen::Matrix3Xd patient_data::trajectory() const
{
    return m_trajectory;
}

Eigen::Vector3d patient_data::target() const
{
    return m_target;
}

Eigen::Vector3d patient_data::entry() const
{
    return m_entry;
}

double patient_data::offset() const
{
    return m_offset;
}

//Eigen::MatrixXd patient_data::GetPatientData() const
//{
//	return m_patientdata;
//}
//
//Eigen::MatrixXd patient_data::GetMarkers() const
//{
//	return m_patientdata.block<3,3>(0,0);
//}
//
//Eigen::MatrixXd patient_data::GetTraj() const
//{
//	return m_patientdata.block<2,3>(3,0);
//}
//
//Eigen::MatrixXd patient_data::GetTarget() const
//{
//	return m_patientdata.row(3);
//}
//
//Eigen::MatrixXd patient_data::GetEntry() const
//{
//	return m_patientdata.row(4);
//}
//
//void patient_data::SetPatientData(Eigen::MatrixXd x)
//{
//	//m_patientdata = x;
//}
