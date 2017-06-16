#include "PositionAverage.h"
#include <Eigen/dense>


PositionAverage::PositionAverage(void)
{
}


PositionAverage::~PositionAverage(void)
{
}

std::tuple<double,double,double> PositionAverage::GetAverage() const
{
	return std::make_tuple<>( m_av1.GetAverage(), 
		m_av2.GetAverage(),
		m_av3.GetAverage() );
}

Eigen::Vector3d PositionAverage::GetAverageVector3d() const
{
    return Eigen::Vector3d(m_av1.GetAverage(), m_av2.GetAverage(), m_av3.GetAverage());
}

void PositionAverage::AddMeasurement(double x,double y,double z)
{
	m_av1.AddMeasurement(x);
	m_av2.AddMeasurement(y);
	m_av3.AddMeasurement(z);
}

int PositionAverage::count() const
{
	return m_av1.GetCount();
}