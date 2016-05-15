#ifndef REG_FILE_H
#define REG_FILE_H

#include "MIPSInstruction.h"

class Buffer2;
class RegFile {

public:

	RegFile() {
		for (int i = 0; i < 32; ++i)
			regs[i] = 0;
	}

	void setSA(int);

	void setTA(int);

    void execute();

	void setAddress(int);

	void setData(int);

	void setRegWrite(bool);

	void setBuffer2(Buffer2* b2) {
		buffer2 = b2;
	}

private:

    int sA, tA, address;

	int regs[32];

    bool regWrite;

	Buffer2* buffer2;
};

#endif
