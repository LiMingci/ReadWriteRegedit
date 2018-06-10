#include <Windows.h>
#include <string>
#include <iostream>

#include "CCSoftWareEncipher.h"



int main(int argc, char* argv[])
{
	//CcReadWriteRegedit read_write_reg;

	//std::string soft_name("TestReg");

	//std::string value;
	//bool is_sucess = read_write_reg.getSZRegValur(hkey, str_url, str_key, value);
	//std::cout << "is_sucess = " << is_sucess << std::endl;
	//std::cout << "value = " << value << std::endl;

	//bool is_sucess = read_write_reg.creatRegKey(hkey, str_url, str_key);
	//std::cout << "is_sucess = " << is_sucess << std::endl;

	//is_sucess = read_write_reg.setDWORDRegItem(hkey, str_url + std::string("\\") + str_key, std::string("name"), 6);
	//std::cout << "is_sucess = " << is_sucess << std::endl;

	//bool is_sucess = read_write_reg.setSZRegItem(hkey, str_url + std::string("\\") + str_key, std::string("strname"), std::string("chinese"));
	//std::cout << "is_sucess = " << is_sucess << std::endl;

	//unsigned long value;
	//bool is_sucess = read_write_reg.getDWORDRegValue(hkey, str_url + std::string("\\") + str_key, std::string("name"), value);
	//std::cout << "is_sucess = " << is_sucess << std::endl;
	//std::cout << "value = " << value << std::endl;

	//bool is_success = false;
	//unsigned long value = 0;
	//value = read_write_reg.getSoftWareUseCount(soft_name);

	//std::cout << "SoftWare Use Count : " << value << std::endl;

	//Sleep(10000);

	//read_write_reg.setSoftWareUseCount(soft_name, value + 1);

	CcSoftWareEncipher software_encipher("TestReg", 6);
	software_encipher.beginSoftWare();

	Sleep(10000);
	std::cout << ">>>>>>>>" << std::endl;

	software_encipher.endSoftWare();

	return 0;
}