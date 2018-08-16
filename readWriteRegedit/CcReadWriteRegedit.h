#ifndef CC_READ_WRITE_REGEDIT
#define CC_READ_WRITE_REGEDIT
#include <Windows.h>
#include <string>
#include <vector>

//��дע���
//֧������REG_DWORD ��REF_SZ
class CcReadWriteRegedit
{
public:
	CcReadWriteRegedit();
	~CcReadWriteRegedit();


	//��ȡREG_DWORD���͵�ֵ
	bool getDWORDRegValue(
		HKEY keytype, const std::string& strurl,  const std::string& strkey, unsigned long& value);

	//���REG_SZ���͵�ֵ
	bool getSZRegValue(
		HKEY keytype, const std::string& strurl, const std::string& strkey, std::string& value);

	//��ȡREG_NULTI_SZ���͵�ֵ
	bool getMULTISZRegValue(
		HKEY keytype, const std::string& strurl, const std::string& strkey, std::vector<std::string>& value);

	//����һ���ӽ�
	bool creatRegKey(
		HKEY keytype, const std::string& strurl, const std::string& keyname
		);

	//����һ��REG_DWORD���͵�ֵ��
	bool setDWORDRegItem(
		HKEY keytype, const std::string& strurl, const std::string& name, const unsigned long& value);

	//����һ��REG_SZ���͵�ֵ��
	bool setSZRegItem(
		HKEY keytype, const std::string& strurl, const std::string& name, const std::string& value);

private:
	//wstring => string
	std::string ws2s(const std::wstring& ws);

	//string => wstring
	std::wstring s2ws(const std::string& s);

};


#endif //!CC_READ_WRITE_REGEDIT

