#pragma once
#include <comutil.h>
#include "io.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#define GPSCAMERALOGAPI __declspec(dllexport)
class GPSCAMERALOGAPI CGpsLogBase
{
public:
	typedef enum _tagGPSLog
	{
		enum_CANNON_5DMARK2 = 0,
	}enum_GPS_LOG;
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

