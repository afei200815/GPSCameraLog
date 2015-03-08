// GPSCameraLog.h : main header file for the GPSCameraLog DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <comutil.h>
#include "io.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
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

typedef enum _tagGPSLog
{
	enum_CANNON_5DMARK2 = 0,
}enum_GPS_LOG;
class GPSCAMERALOGAPI CGpsLogBase
{
public:
	CGpsLogBase(void);
	~CGpsLogBase(void);
protected:
	double* m_pLng;//经度
	double* m_pLat;//纬度
	double* m_pZ;//海拔
	double* m_pPhi;//航向倾角pitch
	double* m_pOmega;//旁向倾角roll
	double* m_pKappa;//旋偏角heading
	UINT m_nCount;
protected:
	void InitRecord();
public:
	virtual BOOL LoadGPSLog(BSTR bstrLog) = 0;//加载GPS记录文件
	virtual UINT GetCount() {return m_nCount;}//得到记录的数量
	void GetLatLngZ(double* pLat,double* pLng,double* pZ);//得到记录的经纬度，数组需要实现根据数量申请好
	void GetEO(double* pPhi,double* pOmega,double* pKappa);//得到记录的姿态角
};

class GPSCAMERALOGAPI  GPSLogFactory
{
public:
	GPSLogFactory(void);
	~GPSLogFactory(void);
public:
	CGpsLogBase* CreateGPSLog(enum_GPS_LOG logType);
};