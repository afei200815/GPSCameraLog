// GPSCameraLog.h : main header file for the GPSCameraLog DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#ifdef GPSCAMERALOGAPI
#else
#define GPSCAMERALOGAPI __declspec(dllimport)
#endif
// CGPSCameraLogApp
// See GPSCameraLog.cpp for the implementation of this class
//

class CGPSCameraLogApp : public CWinApp
{
public:
	CGPSCameraLogApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
