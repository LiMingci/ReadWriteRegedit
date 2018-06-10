#ifndef CC_SOFTWARE_ENCIPHER
#define CC_SOFTWARE_ENCIPHER

#include "CcReadWriteRegedit.h"


class CcSoftWareEncipher
{
public:
	CcSoftWareEncipher(std::string name, unsigned long count);
	~CcSoftWareEncipher();

	void beginSoftWare();

	void endSoftWare();
private:
	unsigned long getSoftWareUseCount(const std::string& name);

	bool setSoftWareUseCount(const std::string& name, unsigned long count);

private:
	CcReadWriteRegedit      _readWriteReg;

	std::string             _softWareName;

	unsigned long           _useCount;

	unsigned long           _sumUseCount;

};

#endif // !CC_SOFTWARE_ENCIPHER



