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
	double* m_pLng;//����
	double* m_pLat;//γ��
	double* m_pZ;//����
	double* m_pPhi;//�������pitch
	double* m_pOmega;//�������roll
	double* m_pKappa;//��ƫ��heading
	UINT m_nCount;
protected:
	void InitRecord();
public:
	virtual BOOL LoadGPSLog(BSTR bstrLog) = 0;//����GPS��¼�ļ�
	virtual UINT GetCount() {return m_nCount;}//�õ���¼������
	void GetLatLngZ(double* pLat,double* pLng,double* pZ);//�õ���¼�ľ�γ�ȣ�������Ҫʵ�ָ������������
	void GetEO(double* pPhi,double* pOmega,double* pKappa);//�õ���¼����̬��
};

class GPSCAMERALOGAPI  GPSLogFactory
{
public:
	GPSLogFactory(void);
	~GPSLogFactory(void);
public:
	CGpsLogBase* CreateGPSLog(enum_GPS_LOG logType);
};