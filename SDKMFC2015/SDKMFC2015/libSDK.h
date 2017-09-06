#pragma once
#include "CSpatialAnalyzerSDK.h"
//class CSpatialAnalyzerSDK;

class libSDK : public CSpatialAnalyzerSDK {
public:
	libSDK();
	~libSDK();
	//File Operations
	//MP Task Overview
	//MP Subroutines
	//View Control
	//Construction Operations
	  void copyObject(CString colSource, CString nameSource, CString colDest, CString nameDest, BOOL overwrite);
	  void renamePoint(CString c1, CString o1, CString t1, CString c2, CString o2, CString t2, BOOL overwrite);
	  //Collections
	  void setOrConstructDefaultCollection(CString colName);
	  void deleteCollection(CString colName);
	  void getActiveCollectionName(char * buf, size_t sz);
	  //Points and Groups
	  void constructPointFitToPoints(CStringArray &arr, CString ptCol, CString ptObj, CString ptTarg);
	  void constructAPointInWorkingCoordinates(CString pCol, CString pObj, CString pTarg, double x, double y, double z);
	  void constructAPointAtLineMidPoint(CString lCol, CString lName, CString pCol, CString pObj, CString pTarg);
	  void constructAPointGroupFromPointNameRefList(CStringArray &ptNmRefList, CString ptCol, CString ptObj);
	  void constructAPointAtCircleCenter(CString cirCol, CString cirName, CString ptCol, CString ptObj, CString ptTarg);
	  //Lines
	  void constructLine2Points(CString lnCol, CString lnNm, CString fPtCol, CString fPtObj, CString fPtTarg, CString sPtCol, CString sPtObj, CString sPtTarg);
	  //Frames
	  void constructFrame(CString fCol, CString fName, double * T);
	  //Other MP Types
	   void getPointNameRefListRunTimeSelect(char * buf, size_t sz, CString msg);
	//Analysis Operations
	   void transformObjectsByDeltaAboutWorkingFrame(CStringArray &objs, double* T);
	//Reporting Operations
	//Excel Direct Connect
	//MS Office Reporting Operations
	//Process Flow Operations
	//Scalar Math Operations
	//Vector Math Operations
	//Instrument Operations
	//Cloud Viewer Operations
	//Variables
	//Utility Operations
		void setWorkingFrame(CString fCol, CString fName);
		void deleteObjects(CStringArray &objs);
	void getTest(char * buf, int sz, CString msg);
};

