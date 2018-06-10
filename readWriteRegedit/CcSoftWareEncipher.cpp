#include "CcSoftWareEncipher.h"



CcSoftWareEncipher::CcSoftWareEncipher(std::string name, unsigned long count)
{
	_softWareName = name;
	_sumUseCount = count;
	_useCount = 0;
}


CcSoftWareEncipher::~CcSoftWareEncipher()
{
}

void CcSoftWareEncipher::beginSoftWare()
{
	_useCount = getSoftWareUseCount(_softWareName);
	if (_useCount > _sumUseCount)
	{
		exit(-1);
	}
}

void CcSoftWareEncipher::endSoftWare()
{
	setSoftWareUseCount(_softWareName, _useCount + 1);
}


unsigned long CcSoftWareEncipher::getSoftWareUseCount(const std::string& name)
{
	HKEY hkey = HKEY_CURRENT_USER;
	std::string str_url("Software");
	std::string str_item_name("UseCount");

	unsigned long value = 0;
	bool is_success = false;
	is_success = _readWriteReg.getDWORDRegValue(hkey, str_url + std::string("\\") + name, str_item_name, value);
	if (!is_success)
	{
		if (_readWriteReg.creatRegKey(hkey, str_url, name))
		{
			_readWriteReg.setDWORDRegItem(hkey, str_url + std::string("\\") + name, str_item_name, value);
		}

	}

	return value;

}

bool CcSoftWareEncipher::setSoftWareUseCount(const std::string& name, unsigned long count)
{
	HKEY hkey = HKEY_CURRENT_USER;
	std::string str_url("Software");
	std::string str_item_name("UseCount");

	bool is_success = _readWriteReg.setDWORDRegItem(hkey, str_url + std::string("\\") + name, str_item_name, count);

	return is_success;

}
