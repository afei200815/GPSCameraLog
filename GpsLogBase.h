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

