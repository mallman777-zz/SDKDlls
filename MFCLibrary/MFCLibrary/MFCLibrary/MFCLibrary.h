// MFCLibrary.h : main header file for the MFCLibrary DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#ifdef MATHLIBRARY_EXPORTS  
#define MATHLIBRARY_API extern "C" __declspec(dllexport)   
#else  
#define MATHLIBRARY_API extern "C" __declspec(dllimport)   
#endif  

#include "resource.h"		// main symbols
#include "CSpatialAnalyzerSDK.h"

//class CSpatialAnalyzerSDK;

// CMFCLibraryApp
// See MFCLibrary.cpp for the implementation of this class
//

class CMFCLibraryApp : public CWinApp
{
public:
	CMFCLibraryApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

 class myClass : public CSpatialAnalyzerSDK {

};




class localMath {
public:
	double localAdder(double x, double y);
	double localMultiplier(double x, double y);
};

MATHLIBRARY_API double newAdd(double a, double b);

// Returns a * b  
MATHLIBRARY_API double Multiply(double a, double b);

// Returns a + (a * b)  
MATHLIBRARY_API double AddMultiply(double a, double b);

MATHLIBRARY_API long connectToSA();
