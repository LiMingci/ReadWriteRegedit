#ifndef CC_READ_WRITE_REGEDIT
#define CC_READ_WRITE_REGEDIT
#include <Windows.h>
#include <string>
#include <vector>

//读写注册表
//支持类型REG_DWORD 、REF_SZ
class CcReadWriteRegedit
{
public:
	CcReadWriteRegedit();
	~CcReadWriteRegedit();


	//获取REG_DWORD类型的值
	bool getDWORDRegValue(
		HKEY keytype, const std::string& strurl,  const std::string& strkey, unsigned long& value);

	//获得REG_SZ类型的值
	bool getSZRegValue(
		HKEY keytype, const std::string& strurl, const std::string& strkey, std::string& value);

	//获取REG_NULTI_SZ类型的值
	bool getMULTISZRegValue(
		HKEY keytype, const std::string& strurl, const std::string& strkey, std::vector<std::string>& value);

	//创建一个子健
	bool creatRegKey(
		HKEY keytype, const std::string& strurl, const std::string& keyname
		);

	//创建一个REG_DWORD类型的值项
	bool setDWORDRegItem(
		HKEY keytype, const std::string& strurl, const std::string& name, const unsigned long& value);

	//创建一个REG_SZ类型的值项
	bool setSZRegItem(
		HKEY keytype, const std::string& strurl, const std::string& name, const std::string& value);

private:
	//wstring => string
	std::string ws2s(const std::wstring& ws);

	//string => wstring
	std::wstring s2ws(const std::string& s);

};


#endif //!CC_READ_WRITE_REGEDIT

