#pragma once
#include "MovingAverage.h"

#include <tuple>

class PositionAverage
{
public:
	PositionAverage(void);
	~PositionAverage(void);
	std::tuple<double,double,double>	GetAverage() const;
	void AddMeasurement(double,double,double);
	int count() const;

private:
	MovingAverage	m_av1;
	MovingAverage	m_av2;
	MovingAverage	m_av3;
};

