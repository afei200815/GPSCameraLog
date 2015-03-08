#include "StdAfx.h"
#include "C5DMark2GPSLog.h"
C5DMark2GPSLog::C5DMark2GPSLog(void)
{
}


C5DMark2GPSLog::~C5DMark2GPSLog(void)
{
}

BOOL C5DMark2GPSLog::LoadGPSLog( BSTR bstrLog )
{
	string strLog = _bstr_t(bstrLog);
	if (_access(strLog.c_str(),0) == -1)
	{
		return FALSE;
	}

	m_nCount = GetLineCount(bstrLog);
	InitRecord();

	//实验用的文件重复了两次记录，所以把数量减半
	m_nCount /= 2;

	FILE* pSrc = fopen(strLog.c_str(),"r");
	if (NULL == pSrc)
	{
		return FALSE;
	}
	int nNum;
	char strTmp[30];
	for (int i = 0;i < m_nCount; i++)
	{
		// 1 星期5 09:05:43 97.9623639 24.6968069 792.736 7.9 -.3  4.1 
		fscanf(pSrc,"%d",&nNum);//1
		fscanf(pSrc,"%s",&strTmp);//星期5
		fscanf(pSrc,"%s",&strTmp);//09：。。
		fscanf(pSrc,"%lf",&m_pLng[i]);
		fscanf(pSrc,"%lf",&m_pLat[i]);
		fscanf(pSrc,"%lf",&m_pZ[i]);
		fscanf(pSrc,"%lf",&m_pOmega[i]);//旁向倾角，roll
		fscanf(pSrc,"%lf",&m_pPhi[i]);//航向倾角,pitch
		fscanf(pSrc,"%lf",&m_pKappa[i]);//相片旋角,heading
	}
	fclose(pSrc);
	return TRUE;
}

int C5DMark2GPSLog::GetLineCount( BSTR bstrLog )
{
	string strLog = _bstr_t(bstrLog);
	ifstream fileIn(bstrLog);
	if (fileIn.fail())
	{
		return 0;
	}
	char tmp[200];
	int nCnt = 0;
	while(!fileIn.eof())
	{
		fileIn.getline(tmp,200);
		nCnt++;
	}
	return nCnt;
}
