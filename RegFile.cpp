#include "RegFile.h"
#include "Buffer2.h"

void RegFile::setSA(int a) {
	sA = a;
}

void RegFile::setTA(int a) {
	tA = a;
}

void RegFile::read() {
	buffer2->setSD(regs[sA]);
	buffer2->setTD(regs[tA]);
}

void RegFile::write() {
	if (address > 0 && address < 32 && regWrite)
		regs[address] = data;
}

void RegFile::setAddress(int a) {
	address = a;
}

void RegFile::setData(int d) {
	data = d;
}

void RegFile::setRegWrite(bool rw) {
	regWrite = rw;
}