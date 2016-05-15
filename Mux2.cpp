#include "Mux2.h"
#include "ProgramCounter.h"
#include "Buffer3.h"
#include "Mux3.h"
#include "DataMemory.h"
#include "RegFile.h"

void Mux2::setMux2_1(Mux2* m2) {
	mux2_1 = m2;
}

void Mux2::setProgramCounter(ProgramCounter* pc) {
	programCounter = pc;
}

void Mux2::setBuffer3(Buffer3* b3) {
	buffer3 = b3;
}

void Mux2::setMux3_2(Mux3* m3) {
	mux3_2 = m3;
}

void Mux2::setDataMemory(DataMemory* dm) {
	dataMemory = dm;
}

void Mux2::setRegFile(RegFile* rf) {
	regFile = rf;
}

void Mux2::execute() {
	int out = S ? I1 : I0;
	switch (idx)
	{
	case 0:
		mux2_1->setI0(out);
		break;
	case 1:
		programCounter->setPC(out);
		break;
	case 2:
		buffer3->setTaOrDa(out);
		break;
	case 3:
		mux3_2->setI0(out);
		break;
	case 4:
		dataMemory->setWriteData(out);
		break;
	default:
		regFile->setData(out);
		break;
	}
}