#pragma once
#include "GpsLogBase.h"
class GPSCAMERALOGAPI  GPSLogFactory
{
public:
	GPSLogFactory(void);
	~GPSLogFactory(void);
public:
	CGpsLogBase* CreateGPSLog(CGpsLogBase::enum_GPS_LOG logType);
};

