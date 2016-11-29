#pragma once
class MovingAverage
{
public:
	MovingAverage(void);
	~MovingAverage(void);
	double AddMeasurement(double);
	double GetAverage() const;
	int GetCount() const;

private:
	double m_average;
	int    m_count;
};

