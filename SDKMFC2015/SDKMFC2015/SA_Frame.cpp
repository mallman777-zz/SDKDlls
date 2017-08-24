#include "stdafx.h"
#include "SA_Frame.h"


SA_Frame::SA_Frame()
{
	sColl = _T("");
	sTarg = _T("");
	setCollObjName();
}

SA_Frame::SA_Frame(CString c, CString t) {
	sColl = c;
	sTarg = t;
	setCollObjName();
}

SA_Frame::~SA_Frame()
{
}

void SA_Frame::setCollObjName() {
	sCollObjName = sColl + _T("::") + sTarg + _T("::Frame");
}
