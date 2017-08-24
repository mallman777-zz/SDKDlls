// SALibrary.h : main header file for the SALibrary DLL
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

class CSpatialAnalyzerSDK;

// CSALibraryApp
// See SALibrary.cpp for the implementation of this class
//

class CSALibraryApp : public CWinApp
{
public:
	CSALibraryApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

MATHLIBRARY_API long connectToSA();
