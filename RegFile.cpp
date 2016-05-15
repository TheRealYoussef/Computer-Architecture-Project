#include "RegFile.h"
#include "Buffer2.h"

void RegFile::setSA(int a) {
	sA = a;
}

void RegFile::setTA(int a) {
	tA = a;
}

void RegFile::execute() {
	buffer2->setSD(regs[sA]);
	buffer2->setTD(regs[tA]);
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