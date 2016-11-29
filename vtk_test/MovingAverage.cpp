#include "MovingAverage.h"


MovingAverage::MovingAverage(void) :
	m_average(0),
	m_count(0)
{
}


MovingAverage::~MovingAverage(void)
{
}


double MovingAverage::AddMeasurement(double x)
{
	m_average = (x + double(m_count)*m_average)/(double(m_count)+1.0);
	m_count++;
	return m_average;
}

double MovingAverage::GetAverage() const
{
	return m_average;
}

int MovingAverage::GetCount() const
{
	return m_count;
}