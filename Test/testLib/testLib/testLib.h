// testLib.h : main header file for the testLib DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CtestLibApp
// See testLib.cpp for the implementation of this class
//

class CtestLibApp : public CWinApp
{
public:
	CtestLibApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
