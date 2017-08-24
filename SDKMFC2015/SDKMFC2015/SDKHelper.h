#pragma once
#include <vector>
#include "SA_PtName.h"
#include "interpret.h"
#include "SA_Frame.h"
using namespace std;

//class CSpatialAnalyzerSDK;
class libSDK;

class SDKHelper
{
public:
	//SDKHelper(CSpatialAnalyzerSDK& sdkInterface);
	SDKHelper(libSDK& libSDKInterface);
	virtual ~SDKHelper(void);

	virtual bool GetMPStepMessagesHelper(CStringArray& messagesOut);
	virtual bool GetTransformArgHelper(const CString& argName, double matrixOut[][4]);
	virtual bool SetTransformArgHelper(const CString& argName, const double matrixIn[][4]);
	virtual bool GetWorldTransformArgHelper(const CString& argName, double matrixOut[][4], double& scale);
	virtual bool SetWorldTransformArgHelper(const CString& argName, const double matrixIn[][4], const double& scale);

	virtual void DebugMatrix(const double T[][4]);
	virtual bool SetCollectionObjectNameRefListArgHelper(const CString& argName, const CStringArray& objects);
	virtual bool GetCollectionObjectNameRefListArgHelper(const CString& argName, CStringArray& objectListOut);
	virtual bool SetPointNameRefListArgHelper(const CString& argName, const CStringArray& points);
	virtual bool GetPointNameRefListArgHelper(const CString& argName, CStringArray& pointListOut);
	virtual bool SetVectorNameRefListArgHelper(const CString& argName, const CStringArray& vectors);
	virtual bool GetVectorNameRefListArgHelper(const CString& argName, CStringArray& vectorListOut);
	virtual bool SetCollectionVectorGroupNameRefListArgHelper(const CString& argName, const CStringArray& objects);
	virtual bool GetCollectionVectorGroupNameRefListArgHelper(const CString& argName, CStringArray& objectListOut);
	virtual bool SetCollectionGroupNameRefListArgHelper(const CString& argName, const CStringArray& groups);
	virtual bool GetCollectionGroupNameRefListArgHelper(const CString& argName, CStringArray& groupListOut);
	virtual bool SetColInstIdRefListArgHelper(const CString& argName, const CStringArray& objects);
	virtual bool GetColInstIdRefListArgHelper(const CString& argName, CStringArray& objectListOut);
	virtual bool SetStringRefListArgHelper(const CString& argName, const CStringArray& stringList);
	virtual bool GetStringRefListArgHelper(const CString& argName, CStringArray& stringListOut);

	virtual bool GetDoubleArrayArgHelper(const CString & argName, long & arraySize, double arrayOut[]);
	virtual bool SetDoubleArrayArgHelper(const CString & argName, const long arraySize, const double arrayIn[]);

	vector<SA_PtName> getPointsRunTimeSelect(CString msg);
	SA_Frame getFrameRunTimeSelect(CString msg);
	vector<SA_PtName> copyPoints(vector<SA_PtName> &pts, CString tmacName);
	SA_Frame copyFrame(SA_Frame f);
	void showPoints(CStringArray &pntNameList, bool show);
	long transformObjectByWorldTOperator(CString colObjName, double T[][4]);
	void getFrameFrameRelationship(SA_Frame f1, SA_Frame f2);

protected:
	//CSpatialAnalyzerSDK& m_interface;
	libSDK& m_interface;

private:
	interpret interp;
};
