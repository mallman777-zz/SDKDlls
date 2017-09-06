// SDKMFC2015.h : main header file for the SDKMFC2015 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif


#ifdef SDKLIBRARY_EXPORTS  
#define SDKLIBRARY_API extern "C" __declspec(dllexport)   
#else  
#define SDKLIBRARY_API extern "C" __declspec(dllimport)   
#endif  

#include "resource.h"		// main symbols
//#include "CSpatialAnalyzerSDK.h"
#include <vector>
using namespace std;

// CSDKMFC2015App
// See SDKMFC2015.cpp for the implementation of this class
//

class CSDKMFC2015App : public CWinApp
{
public:
	CSDKMFC2015App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


SDKLIBRARY_API long connToSA();

//File Operations
//MP Task Overview
//MP Subroutines
//View Control
//Construction Operations
  SDKLIBRARY_API void copyObject(char* sColl, char * sName, char * destCol, char * destName, bool overwrite);
  SDKLIBRARY_API void renamePoint(char* c1, char* o1, char* t1, char* c2, char* o2, char* t2, bool overwrite);
  //Collections 
  SDKLIBRARY_API void setOrConstructDefaultCollection(char* colName);
  SDKLIBRARY_API void deleteCollection(char * colName);
  SDKLIBRARY_API void getActiveCollectionName(char * buf, size_t sz);
  //Points and Groups
  SDKLIBRARY_API void constructPointFitToPoints(char * buf, char * ptCol, char * ptObj, char * ptTarg);
  SDKLIBRARY_API void constructAPointInWorkingCoordinates(char * ptCol, char * ptObj, char * ptTarg, double x, double y, double z);
  SDKLIBRARY_API void constructAPointAtLineMidPoint(char * lCol, char * lName, char * ptCol, char * ptObj, char * ptTarg);
  SDKLIBRARY_API void constructAPointGroupFromPointNameRefList(char * buf, char * ptCol, char * ptObj);
  SDKLIBRARY_API void constructAPointAtCircleCenter(char * cirCol, char * cirName, char * ptCol, char * ptObj, char * ptTarg);
  //Lines
  SDKLIBRARY_API void constructLine2Points(char* lCol, char* lName, char* fPtCol, char* fPtObj, char* fPtTarg, char* sPtCol, char* sPtObj, char* sPtTarg);
  SDKLIBRARY_API void constructFrame(char* fCol, char* fName, double* T);
  //Other MP Types
  SDKLIBRARY_API void makePointNameRefListRuntimeSelect(char * buf, size_t sz, const char * msg);
	//Analysis Operations
  SDKLIBRARY_API void transformObjectsByDeltaAboutWorkingFrame(char * buf, double* T);
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
  SDKLIBRARY_API void setWorkingFrame(char* fCol, char* fName);
  SDKLIBRARY_API void displayMsg(char* msg);
SDKLIBRARY_API void test(char * buf, int sz);



