// SALibrary.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "SALibrary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CSALibraryApp

BEGIN_MESSAGE_MAP(CSALibraryApp, CWinApp)
END_MESSAGE_MAP()


// CSALibraryApp construction

CSALibraryApp::CSALibraryApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CSALibraryApp object

CSALibraryApp theApp;

const GUID CDECL _tlid = { 0x98C45D78, 0x47F0, 0x4A65, { 0xA1, 0x60, 0xD4, 0xAA, 0x94, 0x42, 0x4B, 0x94 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CSALibraryApp initialization

BOOL CSALibraryApp::InitInstance()
{
	CWinApp::InitInstance();

	// Register all OLE server (factories) as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();

	return TRUE;
}

// DllGetClassObject - Returns class factory

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}


// DllCanUnloadNow - Allows COM to unload DLL

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}


// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return S_OK;
}


// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return S_OK;
}

long connectToSA() {
	CSpatialAnalyzerSDK NrkSdk;
	if (!NrkSdk.CreateDispatch(_T("SpatialAnalyzerSDK.Application")))
	{
		AfxMessageBox(_T("Something Failed in OnCreate.  Hi!"));
		return -1;  // fail
	}
	long statCode;
	CString host = _T("localhost");
	statCode = NrkSdk.Connect(host);
	return statCode;
}