#include "StdAfx.h"
#include "GpsLogBase.h"


CGpsLogBase::CGpsLogBase(void)
{
}


CGpsLogBase::~CGpsLogBase(void)
{
	delete []m_pLng;m_pLng=NULL;
	delete []m_pLat;m_pLat=NULL;
	delete []m_pZ;m_pZ=NULL;
	delete []m_pOmega;m_pOmega=NULL;
	delete []m_pKappa;m_pKappa=NULL;
	delete []m_pPhi;m_pPhi=NULL;
}

void CGpsLogBase::GetLatLngZ( double* pLat,double* pLng,double* pZ )
{
	if (pLat!=NULL && pLng!=NULL && pZ!=NULL&& m_nCount>0)
	{
		memcpy(pLat,m_pLat,sizeof(double)*m_nCount);
		memcpy(pLng,m_pLng,sizeof(double)*m_nCount);
		memcpy(pZ,m_pZ,sizeof(double)*m_nCount);
	}
}

void CGpsLogBase::GetEO( double* pPhi,double* pOmega,double* pKappa )
{
	if (pPhi!=NULL && pOmega!=NULL && pKappa!=NULL&& m_nCount>0)
	{
		memcpy(pPhi,m_pPhi,sizeof(double)*m_nCount);
		memcpy(pOmega,m_pOmega,sizeof(double)*m_nCount);
		memcpy(pKappa,m_pKappa,sizeof(double)*m_nCount);
	}
}

void CGpsLogBase::InitRecord()
{
	if (m_nCount>0)
	{
		m_pLng = new double[m_nCount];
		m_pLat = new double[m_nCount];
		m_pZ = new double[m_nCount];
		m_pKappa = new double[m_nCount];
		m_pPhi = new double[m_nCount];
		m_pOmega = new double[m_nCount];
	}
}
