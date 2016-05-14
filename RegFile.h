#ifndef REG_FILE_H
#define REG_FILE_H

#include "MIPSInstruction.h"
#include "Object.h"

class RegFile : public Object {

public:

    void set(MIPSInstruction mips);

	void setAddress(int);

	void setData(int);

	void setRegWrite(bool);

private:

    int sD, tD, address;

	int regs[32] = { 0 };

    bool regWrite;  
};

#endif
