#include "StdAfx.h"
#include "GPSLogFactory.h"
#include "C5DMark2GPSLog.h"

GPSLogFactory::GPSLogFactory(void)
{
}


GPSLogFactory::~GPSLogFactory(void)
{
}

CGpsLogBase* GPSLogFactory::CreateGPSLog(CGpsLogBase::enum_GPS_LOG logType )
{
	CGpsLogBase* pLog = NULL;
	switch(logType)
	{
	case CGpsLogBase::enum_CANNON_5DMARK2:
		pLog = new C5DMark2GPSLog;
		break;
	}

	return pLog;
}
