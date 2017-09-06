#pragma once
#include "stdafx.h"
#include "libSDK.h"
//#include "CSpatialAnalyzerSDK.h"
#include "SDKHelper.h"
#include "interpret.h"

libSDK::libSDK()
{
}

libSDK::~libSDK()
{
}

//File Operations
//MP Task Overview
//MP Subroutines
//View Control
//Construction Operations
  void libSDK::copyObject(CString colSource, CString nameSource, CString colDest, CString nameDest, BOOL overwrite) {
	SetStep(_T("Copy Object"));
	SetCollectionObjectNameArg(_T("Source Object"), colSource, nameSource);
	SetCollectionObjectNameArg(_T("New Object Name"), colDest, nameDest);
	SetBoolArg(_T("Overwrite if exists?"), overwrite);
	ExecuteStep();
}
  void libSDK::renamePoint(CString c1, CString o1, CString t1, CString c2, CString o2, CString t2, BOOL overwrite) {
	  SetStep(_T("Rename Point"));
	  SetPointNameArg(_T("Original Point Name"), c1, o1, t1);
	  SetPointNameArg(_T("New Point Name"), c2, o2, t2);
	  SetBoolArg(_T("Overwrite if exists?"), overwrite);
	  ExecuteStep();
  }
  //Collections
  void libSDK::setOrConstructDefaultCollection(CString colName) {
	  SetStep(_T("Set (or construct) default collection"));
	  SetCollectionNameArg(_T("Collection Name"), colName);
	  ExecuteStep();
  }
  void libSDK::deleteCollection(CString colName) {
	  SetStep(_T("Delete Collection"));
	  SetCollectionNameArg(_T("Name of Collection to Delete"), colName);
	  ExecuteStep();
  }
  void libSDK::getActiveCollectionName(char * buf, size_t sz) {
	  SetStep(_T("Get Active Collection Name"));
	  ExecuteStep();
	  BSTR sValue = NULL;
	  GetCollectionNameArg(_T("Currently Active Collection Name"), &sValue);
	  CString name = sValue;
	  ::SysFreeString(sValue);
	  interpret interp;
	  interp.convertCStringToCharStar(buf, sz, name);
  }
  //Points and Groups
  void libSDK::constructPointFitToPoints(CStringArray &arr, CString ptCol, CString ptObj, CString ptTarg) {
	  SetStep(_T("Construct Point (Fit to Points)"));
	  SDKHelper helper(*this);
	  helper.SetPointNameRefListArgHelper(_T("Point Names"), arr);
	  SetPointNameArg(_T("Resulting Point Name"), ptCol, ptObj, ptTarg);
	  ExecuteStep();
  }
  void libSDK::constructAPointInWorkingCoordinates(CString pCol, CString pObj, CString pTarg, double x, double y, double z) {
	  SetStep(_T("Construct a Point in Working Coordinates"));
	  SetPointNameArg(_T("Point Name"), pCol, pObj, pTarg);
	  SetVectorArg(_T("Working Coordinates"), x, y, z);
	  ExecuteStep();
  }
  void libSDK::constructAPointAtLineMidPoint(CString lCol, CString lName, CString pCol, CString pObj, CString pTarg) {
	  SetStep(_T("Construct a Point at line MidPoint"));
	  SetCollectionObjectNameArg(_T("Line Name"), lCol, lName);
	  SetPointNameArg(_T("Point Name"), pCol, pObj, pTarg);
	  ExecuteStep();
  }
  void libSDK::constructAPointGroupFromPointNameRefList(CStringArray &ptNmRefList, CString ptCol, CString ptObj) {
	  SetStep(_T("Construct Point Group from Point Name Ref List"));
	  SDKHelper helper(*this);
	  helper.SetPointNameRefListArgHelper(_T("Point Name List"), ptNmRefList);
	  SetCollectionObjectNameArg(_T("Group Name"), ptCol, ptObj);
	  ExecuteStep();
  }
  void libSDK::constructAPointAtCircleCenter(CString cirCol, CString cirName, CString ptCol, CString ptObj, CString ptTarg) {
	  SetStep(_T("Construct a Point at Circle Center"));
	  SetCollectionObjectNameArg(_T("Circle Name"), cirCol, cirName);
	  SetPointNameArg(_T("Point Name"), ptCol, ptObj, ptTarg);
	  ExecuteStep();
  }
  //Lines
  void libSDK::constructLine2Points(CString lnCol, CString lnNm, CString fPtCol, CString fPtObj, CString fPtTarg, CString sPtCol, CString sPtObj, CString sPtTarg) {
		SetStep(_T("Construct Line 2 Points"));
		SetCollectionObjectNameArg(_T("Line Name"), lnCol, lnNm);
		SetPointNameArg(_T("First Point"), fPtCol, fPtObj, fPtTarg);
		SetPointNameArg(_T("Second Point"), sPtCol, sPtObj, sPtTarg);
		ExecuteStep();
      }
  //Frames
  void libSDK::constructFrame(CString fCol, CString fName, double * T) {
		const int numRows = 4;
		const int numCols = 4;
		double TT[numRows][numCols];
		for (int i = 0; i != numRows; ++i) {
			for (int j = 0; j != numCols; ++j)
				TT[i][j] = T[i*numRows + j];
		}
		SetStep(_T("Construct Frame"));
		SetCollectionObjectNameArg(_T("New Frame Name"), fCol, fName);
		SDKHelper helper(*this);
		helper.SetTransformArgHelper(_T("Transform in Working Coordinates"), TT);
		ExecuteStep();
	}
  //Other MP Types
    void libSDK::getPointNameRefListRunTimeSelect(char * buf, size_t sz, CString msg) {
	  SetStep(_T("Make a Point Name Ref List - Runtime Select"));
	  SetStringArg(_T("User Prompt"), msg);
	  ExecuteStep();
	  CStringArray ptNameList;
	  SDKHelper helper(*this);
	  helper.GetPointNameRefListArgHelper(_T("Resultant Point Name List"), ptNameList);
	  interpret  interp;
	  interp.copyCStringArrayToBuffer(buf, sz, ptNameList);
      }
//Analysis Operations
	void libSDK::transformObjectsByDeltaAboutWorkingFrame(CStringArray &objs, double* T) {
		const int numRows = 4;
		const int numCols = 4;
		double TT[numRows][numCols];
		for (int i = 0; i != numRows; ++i) {
			for (int j = 0; j != numCols; ++j)
				TT[i][j] = T[i*numRows + j];
		}
		SetStep(_T("Transform Objects by Delta (About Working Frame)"));
		SDKHelper helper(*this);
		helper.SetCollectionObjectNameRefListArgHelper(_T("Objects to Transform"), objs);
		helper.SetTransformArgHelper(_T("Delta Transform"), TT);
		ExecuteStep();
	}
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
	void libSDK::setWorkingFrame(CString fCol, CString fName) {
		SetStep(_T("Set Working Frame"));
		SetCollectionObjectNameArg(_T("New Working Frame Name"), fCol, fName);
		ExecuteStep();
	}
void libSDK::getTest(char * buf, int sz, CString msg) {
	SetStep(_T("Make a Point Name Ref List - Runtime Select"));
	SetStringArg(_T("User Prompt"), msg);
	ExecuteStep();
	CStringArray ptNameList;
	SDKHelper helper(*this);
	helper.GetPointNameRefListArgHelper(_T("Resultant Point Name List"), ptNameList);
	interpret  interp;
	//interp.convertCStringToCharStar(buf, sz, ptNameList.GetAt(0));
	//buf = interp.convertCStringToCharStar(ptNameList.GetAt(0));
	interp.copyCStringArrayToBuffer(buf, sz, ptNameList);
}