#pragma once
#include "gpscameralog.h"
class GPSCAMERALOGAPI C5DMark2GPSLog :
	public CGpsLogBase
{
public:
	C5DMark2GPSLog(void);
	~C5DMark2GPSLog(void);
public:
	BOOL LoadGPSLog(BSTR bstrLog) override;
protected:
	int GetLineCount(BSTR bstrLog);
};

