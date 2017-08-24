#include "stdafx.h"
#include "interpret.h"
#include <iostream>  
#include <stdlib.h>  
#include <string>  

#include "atlbase.h"  
#include "atlstr.h"  
#include "comutil.h"  

using namespace std;


interpret::interpret()
{
}

interpret::~interpret()
{
}

void interpret::setComboBox(CString val, CWnd *p) {
	p->SetWindowTextW(val);
}
CString interpret::getComboBox(CWnd *p) {
	CString val;
	p->GetWindowTextW(val);
	return val;
}

double interpret::getTxtToFloat(CWnd *p) throw(int) {
	CString val;
	p->GetWindowTextW(val);
	if (strValid(val)) {
		return _tstof((LPCTSTR)val);
	}
	else {
		throw 1;
	}
}

void interpret::setFloatToTxt(double val, CWnd *p) {
	CString valStr;
	valStr.Format(_T("%0.2f"), val);
	p->SetWindowTextW(valStr);
}

int interpret::getTxtToInt(CWnd *p) throw(int) {
	CString val;
	p->GetWindowTextW(val);
	if (strValid(val)) {
		return _tstoi((LPCTSTR)val);
	}
	else {
		throw 1;
	}
}

void interpret::setIntToTxt(int val, CWnd *p) {
	CString valStr;
	valStr.Format(_T("%d"), val);
	p->SetWindowTextW(valStr);
}

CString interpret::getTxtToString(CWnd *p) {
	CString val;
	p->GetWindowTextW(val);
	return val;
}

CStringA interpret::getTxtToCStringA(CWnd *p) {
	CStringA val = "Fuck Off";
	return val;
}

void interpret::setStringToTxt(CString val, CWnd *p) {
	p->SetWindowTextW(val);
}
bool interpret::strValid(CString msg) {
	int el = 0;
	const int numEl = msg.GetLength();
	if (numEl != 0) {
		for (int i = 0; i != numEl; ++i) {
			el = msg.GetAt(i);
			// checking ascii table values to see if element is not a digit, hyphen, or period.
			if (((el < 48) || (el > 57)) & ((el != 45) & (el != 46))) {
				AfxMessageBox(_T("interpret::strValid String Not Valid"));
				return false;
			}
		}
		return true;
	}
	AfxMessageBox(_T("interpret::strValid String Empty"));
	return false;
}

char* interpret::convertCStringAToCharStar(CStringA myStr) {
	const size_t newSize = (myStr.GetLength() + 1);
	char * outStr = new char[newSize];
	strcpy_s(outStr, newSize, myStr);
	return outStr;
}

char* interpret::convertCStringToCharStar(CString myStr) {
	const size_t newSize = (myStr.GetLength() + 1) * 2;
	char * outStr = new char[newSize];
	size_t convertedCharSw = 0;
	wcstombs_s(&convertedCharSw, outStr, newSize, myStr, _TRUNCATE);
	
	return outStr;
}

void interpret::convertCStringToCharStar(char * p, int sz, CString myStr) {
	const size_t newSize = (myStr.GetLength() + 1) * 2;
	size_t convertedCharSw = 0;
	if (newSize <= sz) {
		wcstombs_s(&convertedCharSw, p, newSize, myStr, _TRUNCATE);
	}
	else {
		wcstombs_s(&convertedCharSw, p, sz, myStr, _TRUNCATE);
	}
}

CString interpret::convertCharStartToCString(const char * str) {
	CString res(str);
	return res;
}

char FAR * interpret::convertCStringAToCharFarStar(CStringA str) {
	const size_t newSize = (str.GetLength() + 1);
	char FAR * outStr = new char[newSize];
	strcpy_s(outStr, newSize, str);
	return outStr;
}

char FAR * interpret::convertCStringToCharFarStar(CString str) {
	const size_t newSize = (str.GetLength() + 1) * 2;
	char FAR * outStr = new char[newSize];
	size_t convertedCharSw = 0;
	wcstombs_s(&convertedCharSw, outStr, newSize, str, _TRUNCATE);
	return outStr;
}

void interpret::copyCStringArrayToBuffer(char *p, int sz, CStringArray& arr) {
	const size_t arrSize = arr.GetCount();
	CString flattenedStr;
	for (int i = 0; i != arrSize; ++i) {
		if (i < (arrSize - 1)) {
			flattenedStr += arr.GetAt(i) + _T(",");
		}
		else {
			flattenedStr += arr.GetAt(i);
		}
	}
	convertCStringToCharStar(p, sz, flattenedStr);
}

void interpret::copyBufferToCStringArray(CStringArray& arr, char * buf) {
	CString s = convertCharStartToCString(buf);
	CString token = _T(",");
	vector<CString> sList = tokenize(s, token);
	for (int i = 0; i != sList.size(); ++i) {
		arr.Add(sList[i]);
	}
}

CStringA interpret::testCStringAtoCharStarConversion(CStringA str) {
	char * localStr = convertCStringAToCharStar(str);
	CStringA outStr(localStr);
	return outStr;
}

CStringA interpret::testCStringAtoCharFarStarConversion(CStringA str) {
	char FAR * localStr = convertCStringAToCharStar(str);
	CStringA outStr(localStr);
	return outStr;
}

CString interpret::testCStringToCharStarConversion(CString str) {
	char * localStr = convertCStringToCharStar(str);
	CString outStr(localStr);
	return outStr;
}

vector<CString> interpret::tokenize(CString str) {
	vector<CString> out;
	int nTokenPos = 0;
	CString strToken = str.Tokenize(_T("::"), nTokenPos);
	while (!strToken.IsEmpty()){
		out.push_back(strToken);
		strToken = str.Tokenize(_T("::"), nTokenPos);
	}
	return out;
}

vector<CString> interpret::tokenize(CString str, CString c) {
	vector<CString> out;
	int nTokenPos = 0;
	CString strToken = str.Tokenize(c, nTokenPos);
	while (!strToken.IsEmpty()) {
		out.push_back(strToken);
		strToken = str.Tokenize(c, nTokenPos);
	}
	return out;
}


