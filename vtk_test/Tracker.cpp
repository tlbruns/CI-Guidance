#include "Tracker.h"
#include <iostream>
#include <algorithm>

using std::cerr;
using std::list;
using std::vector;

NDIAuroraTracker::NDIAuroraTracker(int COMPort)
	: Tracker()
{
	m_bIsTracking = false;
	nBaudRate = 5,//115200bps
	nStopBits = 0,//1 bit (default)
	nParity   = 0,
	nDataBits = 0,//Data Bits deault is 8bits (0)
	nHardware = 1,
	m_bWireless = 0,
	m_bResetHardware = 1,
	m_nCOMPort = COMPort;	/* the current com port number */
	
	pCommandHandling = new CCommandHandling;
}


NDIAuroraTracker::~NDIAuroraTracker(void)
{
	std::cerr << "Cleaning up tracker..." << std::endl;
	//Close the COM port and clean up
	if (m_bIsTracking)
		pCommandHandling->nStopTracking();
	pCommandHandling->nCloseComPorts();
	delete ( pCommandHandling );
}

int
NDIAuroraTracker::InitializeSystem()
{
	/*
	 * close, then open the port
	 */
	cerr << "Initializing Tracker\n";
	pCommandHandling->nCloseComPorts();
	if (!pCommandHandling->nOpenComPort( m_nCOMPort ))
	{
		cerr << "NDI: COM Port could not be opened\n";
		return 0;
	} /* if */

	/*
	 * if we are supposed to reset, call the reset now
	 */
	if ( m_bResetHardware )
	{
		if (!pCommandHandling->nHardWareReset(m_bWireless))
		{
			return 0;
		}

	}/* if */

	/*
	 * set the System COM Port parameters, then the computers COM Port parameters.
	 * if that is successful, initialize the system
	 */
	if(pCommandHandling->nSetSystemComParms( nBaudRate, nDataBits, nParity, nStopBits, nHardware ))
	{
		if(pCommandHandling->nSetCompCommParms( nBaudRate, nDataBits, nParity, nStopBits, nHardware ))
		{
			if(pCommandHandling->nInitializeSystem())
			{
				/*
				 * get the system information
				 */
				if (!pCommandHandling->nGetSystemInfo())
				{
					cerr << "NDI: Info problem\n";
					return 0;
				} /* if */

				/* 
				 * Set firing rate if system type is Polaris or Polaris Accedo.
				 */
				if( pCommandHandling->m_dtSystemInformation.nTypeofSystem != AURORA_SYSTEM )
				{
					pCommandHandling->nSetFiringRate(); 
				}/* if */

				cerr << "NDI: Sytem successfully intialized\n";
			} /* if */
			else
			{
				cerr << "NDI: System could not be initialized\n";
				return 0;
			}/* else */
		}/* if */
	}//if
	else
	{
		cerr << "NDI: Com Port problem\n";
		return 0;
	}

	cerr << "NDI: Activating all ports\n";
	if (!pCommandHandling->nActivateAllPorts())
	{
		delete ( pCommandHandling );
		return 0;
	}

	m_ToolList.clear();
	for ( int i = 0; i < NO_HANDLES; i ++ )
	{
		if ( pCommandHandling->m_dtHandleInformation[i].HandleInfo.bInitialized > 0 &&
			pCommandHandling->m_dtHandleInformation[i].szToolType[1] != '8' ) {
			m_ToolList.push_back(i);
			cerr << "Tool handle detected: " << i << std::endl;
		}
	}
	cerr << "NDI: Number of tracked Tools " << m_ToolList.size() << "\n";

	return 1;
}

int
NDIAuroraTracker::StartTracking()
{
	if (m_bIsTracking) return 1;

	if (pCommandHandling->nStartTracking())
	{
		printf("NDI: Started Tracking\n");
		m_bIsTracking = true;
		return 1;
	}
	else 
	{
		printf("NDI: Could not Start Tracking\n");
		return 0;
	}
}

void
NDIAuroraTracker::StopTracking()
{
	/*
	 * if we are tracking, stop
	 */
	if ( m_bIsTracking ) {
		cerr << "Stopping tracking..." << std::endl;
		pCommandHandling->nStopTracking();
	}

	m_bIsTracking = false;
}

int 
NDIAuroraTracker::getNumberOfTools()
{
	return m_ToolList.size();
}

vector<ToolInformationStruct>
NDIAuroraTracker::GetTransformations()
{
	pCommandHandling->nGetTXTransforms(false);
	//int maxToolNumber = *std::max_element( m_ToolList.begin(), m_ToolList.end() );
	int maxToolNumber = 3;
	vector<ToolInformationStruct> transformations (maxToolNumber);

	list<int>::iterator it;
	size_t i = 0;
	for (it = m_ToolList.begin(); it != m_ToolList.end(); it++)
	{
		if (pCommandHandling->m_dtHandleInformation[*it].Xfrms.ulFlags == TRANSFORM_VALID) {
			ToolInformationStruct p;

			if (pCommandHandling->m_dtHandleInformation[*it].Xfrms.ulFlags == TRANSFORM_VALID &&
				!(pCommandHandling->m_dtHandleInformation[*it].Xfrms.fError == BAD_FLOAT)) {
					p.x = pCommandHandling->m_dtHandleInformation[*it].Xfrms.translation.x;
					p.y = pCommandHandling->m_dtHandleInformation[*it].Xfrms.translation.y;
					p.z = pCommandHandling->m_dtHandleInformation[*it].Xfrms.translation.z;
					p.q0 = pCommandHandling->m_dtHandleInformation[*it].Xfrms.rotation.q0;
					p.qx = pCommandHandling->m_dtHandleInformation[*it].Xfrms.rotation.qx;
					p.qy = pCommandHandling->m_dtHandleInformation[*it].Xfrms.rotation.qy;
					p.qz = pCommandHandling->m_dtHandleInformation[*it].Xfrms.rotation.qz;
					p.x1 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk1.x;
					p.y1 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk1.y;
					p.z1 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk1.z;
					p.x2 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk2.x;
					p.y2 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk2.y;
					p.z2 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk2.z;
					p.x3 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk3.x;
					p.y3 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk3.y;
					p.z3 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk3.z;
					p.x4 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk4.x;
					p.y4 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk4.y;
					p.z4 = pCommandHandling->m_dtHandleInformation[*it].Mrkrs.mk4.z;
			} else {
				p.x = 0;
				p.y = 0;
				p.z = 0;
				p.q0 = 1;
				p.qx = 0;
				p.qy = 0;
				p.qz = 0;
				p.x1 = 0;
				p.y1 = 0;
				p.z1 = 0;
				p.x2 = 0;
				p.y2 = 0;
				p.z2 = 0;
				p.x3 = 0;
				p.y3 = 0;
				p.z3 = 0;
				p.x4 = 0;
				p.y4 = 0;
				p.z4 = 0;
			}

			transformations[*it] = p;
		}
	}
	return transformations;
}

ToolInformationStruct
NDIAuroraTracker::GetTransformation(int toolNumber)
{
	pCommandHandling->nGetTXTransforms(false);

	ToolInformationStruct p;
	list<int>::iterator iter = std::find(m_ToolList.begin(), m_ToolList.end(), toolNumber);
	if (iter != m_ToolList.end()) {
		if (pCommandHandling->m_dtHandleInformation[*iter].Xfrms.ulFlags == TRANSFORM_VALID &&
			!(pCommandHandling->m_dtHandleInformation[*iter].Xfrms.fError == BAD_FLOAT)) {
			p.x = pCommandHandling->m_dtHandleInformation[*iter].Xfrms.translation.x;
			p.y = pCommandHandling->m_dtHandleInformation[*iter].Xfrms.translation.y;
			p.z = pCommandHandling->m_dtHandleInformation[*iter].Xfrms.translation.z;
			p.q0 = pCommandHandling->m_dtHandleInformation[*iter].Xfrms.rotation.q0;
			p.qx = pCommandHandling->m_dtHandleInformation[*iter].Xfrms.rotation.qx;
			p.qy = pCommandHandling->m_dtHandleInformation[*iter].Xfrms.rotation.qy;
			p.qz = pCommandHandling->m_dtHandleInformation[*iter].Xfrms.rotation.qz;
			p.x1 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk1.x;
			p.y1 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk1.y;
			p.z1 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk1.z;
			p.x2 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk2.x;
			p.y2 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk2.y;
			p.z2 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk2.z;
			p.x3 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk3.x;
			p.y3 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk3.y;
			p.z3 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk3.z;
			p.x4 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk4.x;
			p.y4 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk4.y;
			p.z4 = pCommandHandling->m_dtHandleInformation[*iter].Mrkrs.mk4.z;

		}
	    else {
			p.x = 0;
			p.y = 0;
			p.z = 0;
			p.q0 = 1;
			p.qx = 0;
			p.qy = 0;
			p.qz = 0;
			p.x1 = 0;
			p.y1 = 0;
			p.z1 = 0;
			p.x2 = 0;
			p.y2 = 0;
			p.z2 = 0;
			p.x3 = 0;
			p.y3 = 0;
			p.z3 = 0;
			p.x4 = 0;
			p.y4 = 0;
			p.z4 = 0;
		}
	} else {
			p.x = 0;
			p.y = 0;
			p.z = 0;
			p.q0 = 1;
			p.qx = 0;
			p.qy = 0;
			p.qz = 0;
			p.x1 = 0;
			p.y1 = 0;
			p.z1 = 0;
			p.x2 = 0;
			p.y2 = 0;
			p.z2 = 0;
			p.x3 = 0;
			p.y3 = 0;
			p.z3 = 0;
			p.x4 = 0;
			p.y4 = 0;
			p.z4 = 0;
	}
	return p;
}
