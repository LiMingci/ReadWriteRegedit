#include <iostream>

#include "CcReadWriteRegedit.h"



CcReadWriteRegedit::CcReadWriteRegedit()
{
}


CcReadWriteRegedit::~CcReadWriteRegedit()
{
}

bool CcReadWriteRegedit::getDWORDRegValue(
	HKEY keytype, const std::string& strurl, const std::string& strkey, unsigned long& value)
{
	std::wstring wstrurl = s2ws(strurl);
	std::wstring wstrkey = s2ws(strkey);
	HKEY  hKeyResult = NULL;
	bool is_success = false;
	if (ERROR_SUCCESS == ::RegOpenKeyEx(keytype, wstrurl.c_str(), 0, KEY_QUERY_VALUE, &hKeyResult))
	{
		DWORD dw_type = REG_DWORD;
		DWORD dw_size = sizeof(DWORD);
		if (ERROR_SUCCESS == ::RegQueryValueEx(hKeyResult, wstrkey.c_str(), 0, &dw_type, (LPBYTE)&value, &dw_size))
		{
			is_success = true;
		}
		else
		{
			std::cerr << "read regedit fail" << std::endl;
		}
	}
	::RegCloseKey(hKeyResult);
	return is_success;
}

bool CcReadWriteRegedit::getSZRegValue(
	HKEY keytype, const std::string& strurl, const std::string& strkey, std::string& value)
{
	std::wstring wstrurl = s2ws(strurl);
	std::wstring wstrkey = s2ws(strkey);
	HKEY  hKeyResult = NULL;
	bool is_success = false;
	if (ERROR_SUCCESS == ::RegOpenKeyEx(keytype, wstrurl.c_str(), 0, KEY_QUERY_VALUE, &hKeyResult))
	{
		DWORD sz_type = REG_SZ;
		DWORD sz_size = NULL;
		
		if (ERROR_SUCCESS == ::RegQueryValueEx(hKeyResult, wstrkey.c_str(), 0, &sz_type, NULL, &sz_size))
		{
			wchar_t* sz_value = new wchar_t[sz_size];
			if (ERROR_SUCCESS == ::RegQueryValueEx(hKeyResult, wstrkey.c_str(), 0, &sz_type, (LPBYTE)sz_value, &sz_size))
			{
				std::wstring wstrValue(sz_value);
				value = ws2s(wstrValue);
				is_success = true;
			}
			delete[] sz_value;
			
		}
		else
		{
			std::cerr << "read regedit fail" << std::endl;
		}
	}
	::RegCloseKey(hKeyResult);

	return is_success;
}

bool CcReadWriteRegedit::getMULTISZRegValue(
	HKEY keytype, const std::string& strurl, const std::string& strkey, std::vector<std::string>& value)
{
	std::cout << "no support this type" << std::endl;
	return false;
}

bool CcReadWriteRegedit::creatRegKey(
	HKEY keytype, const std::string& strurl, const std::string& keyname)
{
	std::wstring wstrurl = s2ws(strurl);
	std::wstring wkeyname = s2ws(keyname);
	HKEY  hKeyResult = NULL;
	HKEY  hKeyCreat = NULL;
	bool is_success = false;
	DWORD dwValue = 6;

	if (ERROR_SUCCESS == ::RegOpenKeyEx(keytype, wstrurl.c_str(), 0, KEY_SET_VALUE, &hKeyResult))
	{
		if (ERROR_SUCCESS == ::RegCreateKey(hKeyResult, wkeyname.c_str(), &hKeyCreat))
		{
			//::RegSetValueEx(hKeyCreat, wkeyname.c_str(), 0, REG_DWORD, (CONST BYTE*)&dwValue, sizeof(DWORD));
			is_success = true;
		}
	}

	::RegCloseKey(hKeyResult);
	return is_success;

}

bool CcReadWriteRegedit::setDWORDRegItem(
	HKEY keytype, const std::string& strurl, const std::string& name, const unsigned long& value)
{
	std::wstring wstrurl = s2ws(strurl);
	std::wstring wkeyname = s2ws(name);
	HKEY  hKeyResult = NULL;

	bool is_success = false;
	if (ERROR_SUCCESS == ::RegOpenKeyEx(keytype, wstrurl.c_str(), 0, KEY_SET_VALUE, &hKeyResult))
	{
		if (ERROR_SUCCESS == ::RegSetValueEx(hKeyResult, wkeyname.c_str(), 0, REG_DWORD, (CONST BYTE*)&value, sizeof(unsigned long)))
		{
			is_success = true;
		}
	}

	::RegCloseKey(hKeyResult);
	return is_success;
}

bool CcReadWriteRegedit::setSZRegItem(
	HKEY keytype, const std::string& strurl, const std::string& name, const std::string& value)
{
	std::wstring wstrurl = s2ws(strurl);
	std::wstring wkeyname = s2ws(name);
	std::wstring wvalue = s2ws(value);
	HKEY  hKeyResult = NULL;
	unsigned long len = wvalue.size() * sizeof(wchar_t) + 1;

	bool is_success = false;
	if (ERROR_SUCCESS == ::RegOpenKeyEx(keytype, wstrurl.c_str(), 0, KEY_SET_VALUE, &hKeyResult))
	{
		if (ERROR_SUCCESS == ::RegSetValueEx(hKeyResult, wkeyname.c_str(), 0, REG_SZ, (CONST BYTE*)wvalue.c_str(), len))
		{
			is_success = true;
		}
	}

	::RegCloseKey(hKeyResult);
	return is_success;
}



std::string CcReadWriteRegedit::ws2s(const std::wstring& ws)
{
	//std::string curLocale = setlocale(LC_ALL, "");
	//const wchar_t* _Source = ws.c_str();
	//size_t _Dsize = wcstombs(NULL, _Source, 0) + 1;
	//char *_Dest = new char[_Dsize];
	//memset(_Dest, 0, _Dsize);
	//wcstombs(_Dest, _Source, _Dsize);
	//std::string result = _Dest;
	//delete[]_Dest;
	//setlocale(LC_ALL, curLocale.c_str());
	//return result;


	std::string str(ws.length(), ' ');
	std::copy(ws.begin(), ws.end(), str.begin());
	return str.data();

}





std::wstring CcReadWriteRegedit::s2ws(const std::string& s)
{
	//std::string curLocale = setlocale(LC_ALL, "");
	//const char* _Source = s.c_str();
	//size_t _Dsize = mbstowcs(NULL, _Source, 0) + 1;
	//wchar_t *_Dest = new wchar_t[_Dsize];
	//wmemset(_Dest, 0, _Dsize);
	//mbstowcs(_Dest, _Source, _Dsize);
	//std::wstring result = _Dest;
	//delete[]_Dest;
	//setlocale(LC_ALL, curLocale.c_str());
	//return result;

	std::wstring wstr(s.length(), L' ');
	std::copy(s.begin(), s.end(), wstr.begin());
	return wstr.data();
}