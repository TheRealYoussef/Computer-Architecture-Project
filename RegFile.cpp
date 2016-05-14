#include "RegFile.h"

void RegFile:: set(MIPSInstruction mips){
    tD = regs[mips.getTA()];
    sD = regs[mips.getSA()];
}

void RegFile::setAddress(int a) {
	address = a;
}

void RegFile::setData(int d) {
	if (address != 0 && regWrite)
		regs[address] = d;
}

void RegFile::setRegWrite(bool rw) {
	regWrite = rw;
}