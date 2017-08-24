#include "stdafx.h"
#include "SA_PtName.h"


SA_PtName::SA_PtName(void)
{
	sColl = _T("");
	sGrp = _T("");
	sTarg = _T("");
	setColObjNameRef();
	setPntNameRef();
}


SA_PtName::~SA_PtName(void)
{
}

SA_PtName::SA_PtName(CString c, CString g, CString t, double X, double Y, double Z)
{
	sColl = c;
	sGrp = g;
	sTarg = t;
	x = X; y = Y; z = Z;
	setColObjNameRef();
	setPntNameRef();
};

void SA_PtName::setPntNameRef() {
	sPntNameRef = sColl + _T("::") + sGrp + _T("::") + sTarg;
}

void SA_PtName::setColObjNameRef(){
	sColObjName = sColl + _T("::") + sGrp + _T("::Point");
}

void SA_PtName::SetPtName(CString c, CString g, CString t)
{
	sColl = c;
	sGrp = g;
	sTarg = t;
	setColObjNameRef();
	setPntNameRef();
};

void SA_PtName::SetPtCoord(double X, double Y, double Z)
{
	x = X; y = Y; z = Z;
};

void SA_PtName::clear() {
	sColl = _T("");
	sGrp = _T("");
	sTarg = _T("");
	setColObjNameRef();
	setPntNameRef();
}
CString SA_PtName::GetPtName()
{
	return sColl + _T("::") + sGrp + _T("::") + sTarg;
};

BOOL SA_PtName::IsSet()
{
	BOOL ret = FALSE;
	if (sTarg.GetLength() > 0)
		ret = TRUE;
	return ret;
}
