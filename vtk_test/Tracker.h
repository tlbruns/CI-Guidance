#pragma once
#include "CommandHandling.h"

#include <list>
#include <vector>
#include <map>

typedef struct ToolInformationStruct
{
    float   x;
    float   y;
    float   z;
	float   q0;
    float   qx;
    float   qy;
    float   qz;
	float   x1;  // marker positions (assumes 4 marker target)
	float   y1;
	float   z1;
	float   x2;
	float   y2;
	float   z2;
	float   x3;
	float   y3;
	float   z3;
	float   x4;
	float   y4;
	float   z4;

} ToolInformation;

class Tracker
{

public:
	Tracker(void) {}
	virtual ~Tracker(void) = 0 {}

	virtual std::vector<ToolInformationStruct> GetTransformations() = 0;
	virtual ToolInformationStruct GetTransformation(int toolNumber) = 0;
	virtual int getNumberOfTools() = 0;
	std::string getName() const { return m_name; }
	void setName(std::string name) { m_name = name; }

	virtual int InitializeSystem() = 0;
	virtual int StartTracking() = 0;
	virtual void StopTracking() = 0;

private:
	std::string m_name;
};

class NDIAuroraTracker : public Tracker
{

public:
	NDIAuroraTracker(int COMPort);
	~NDIAuroraTracker(void);

	std::vector<ToolInformationStruct> GetTransformations();
	ToolInformationStruct GetTransformation(int toolNumber);
	int getNumberOfTools();

	//implementations of the virtual slots above in the interface class
	int InitializeSystem();
	int StartTracking();
	void StopTracking();

private:
	CCommandHandling *pCommandHandling;

	int	nBaudRate,
		nStopBits,
		nParity,
		nDataBits,
		nHardware,
		m_nCOMPort;

	bool m_bWireless,
		 m_bIsTracking,
		 m_bResetHardware;

	//holds the indices of active tools
	std::list<int> m_ToolList;
};

typedef std::map<std::string, Tracker*> TrackerMap;