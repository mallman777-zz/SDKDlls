#pragma once
#include <vector>
using namespace std;
class interpret
{
public:
	interpret();
	~interpret();

	double getTxtToFloat(CWnd *p);
	void setFloatToTxt(double val, CWnd *p);
	int getTxtToInt(CWnd *p);
	void setIntToTxt(int val, CWnd *p);
	void setComboBox(CString val, CWnd *p);
	CString getComboBox(CWnd *p);
	CString getTxtToString(CWnd *p);
	CStringA getTxtToCStringA(CWnd *p);
	void setStringToTxt(CString val, CWnd *p);
	char* convertCStringAToCharStar(CStringA str);
	char* convertCStringToCharStar(CString str);
	void convertCStringToCharStar(char * p, int sz, CString str);
	char FAR * convertCStringAToCharFarStar(CStringA str);
	char FAR * convertCStringToCharFarStar(CString str);
	CString convertCharStartToCString(const char * str);
	void copyCStringArrayToBuffer(char *p, int sz, CStringArray& arr);
	void copyBufferToCStringArray(CStringArray& arr, char * buf);

	CStringA testCStringAtoCharStarConversion(CStringA str);
	CStringA testCStringAtoCharFarStarConversion(CStringA str);
	CString testCStringToCharStarConversion(CString str);
	vector<CString> tokenize(CString str);
	vector<CString> tokenize(CString str, CString c);

private:
	bool strValid(CString msg);
};

