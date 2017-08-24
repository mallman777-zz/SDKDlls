#pragma once
class SA_PtName
{
public:
	CString sColl;
	CString sGrp;
	CString sTarg;
	CString sPntNameRef;
	CString sColObjName;
	double x;
	double y;
	double z;

	SA_PtName(void);
	~SA_PtName(void);
	SA_PtName(CString c, CString g, CString t, double X, double Y, double Z);

	void setPntNameRef();
	void setColObjNameRef();

	void SetPtName(CString c, CString g, CString t);
	void SetPtCoord(double X, double Y, double Z);
	void clear();
	CString GetPtName();
	BOOL IsSet();
};

