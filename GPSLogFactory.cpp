#include "StdAfx.h"
#include "GPSCameraLog.h"
#include "C5DMark2GPSLog.h"

GPSLogFactory::GPSLogFactory(void)
{
}


GPSLogFactory::~GPSLogFactory(void)
{
}

CGpsLogBase* GPSLogFactory::CreateGPSLog(enum_GPS_LOG logType )
{
	CGpsLogBase* pLog = NULL;
	switch(logType)
	{
	case enum_CANNON_5DMARK2:
		pLog = new C5DMark2GPSLog;
		break;
	}

	return pLog;
}
