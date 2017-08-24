#pragma once
#include "SA_PtName.h"

class SA_Frame
{
public:
	CString sColl;
	CString sTarg;
	CString sCollObjName;

	double x; double y; double z;
	double Rx; double Ry; double Rz;
	SA_Frame();
	~SA_Frame();

	SA_Frame(CString c, CString t);

	void setCollObjName();

	void SetFrameName(CString c, CString t)
	{
		sColl = c;
		sTarg = t;
		setCollObjName();
	};

	void SetFrameOrient(double rX, double rY, double rZ) {
		Rx = rX; Ry = rY; Rz = rZ;
	}

	void SetFrameCoord(double X, double Y, double Z)
	{
		x = X; y = Y; z = Z;
	};

	CString GetFrameName()
	{
		return sColl + _T("::")  + sTarg;
	};

	void clear() {
		sColl = _T("");
		sTarg = _T("");
		setCollObjName();
	}

	BOOL IsSet()
	{
		BOOL ret = FALSE;
		if (sTarg.GetLength() > 0)
			ret = TRUE;
		return ret;
	}
};

