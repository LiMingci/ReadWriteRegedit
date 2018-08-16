#include <Windows.h>
#include <string>
#include <iostream>

#include "CCSoftWareEncipher.h"

int main(int argc, char* argv[])
{
	CcSoftWareEncipher software_encipher("TestReg", 6);
	software_encipher.beginSoftWare();

	Sleep(10000);
	std::cout << ">>>>>>>>" << std::endl;

	software_encipher.endSoftWare();

	return 0;
}