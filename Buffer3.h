#ifndef BUFFER_3_H
#define BUFFER_3_H

#include "MIPSInstruction.h"
#include "Buffer4.h"
#include "Mux2.h"
#include "DataMemory.h"
#include "Mux3.h"
#include "ForwardingUnit.h"

class Buffer3 {

public:

	Buffer3() : regWrite(0), memWrite(0) {}

	void setMipsInstruction(const MIPSInstruction& instr) {
		mipsInstruction = instr;
	}

	void setALUOut(int out) {
		aluOut = out;
	}

	void setTD(int t) {
		tD = t;
	}

	void setTaOrDa(int td) {
		taOrDa = td;
	}

	void setMemWrite(int w) {
		memWrite = w;
	}

	void setMemToReg(int r) {
		memToReg = r;
	}

	void setRegWrite(int w) {
		regWrite = w;
	}

	void setDataMemoryMuxSelection(int s) {
		dataMemoryMuxSelection = s;
	}

	void execute() {
		buffer4->setMIPSInstruction(mipsInstruction);
		buffer4->setALUOut(aluOut);
		buffer4->setTAOrDA(taOrDa);
		buffer4->setRegWrite(regWrite);
		buffer4->setTD(tD);
		buffer4->setMemToReg(memToReg);
		dataMemoryMux->setI0(tD);
		dataMemoryMux->setS(dataMemoryMuxSelection);
		dataMemory->setAddress(aluOut);
		dataMemory->setMemWrite(memWrite);
		source1Mux->setI1(aluOut);
		source2Mux->setI1(aluOut);
		forwardingUnit->setPreviousInstruction(mipsInstruction);
		forwardingUnit->setPreviousRegWrite(regWrite);
		mux3_2->setI1(aluOut);
	}

	void setBuffer4(Buffer4* b4) {
		buffer4 = b4;
	}

	void setDataMemoryMux(Mux2* m2) {
		dataMemoryMux = m2;
	}

	void setDataMemory(DataMemory* dm) {
		dataMemory = dm;
	}

	void setSource1Mux(Mux3* m3) {
		source1Mux = m3;
	}

	void setSource2Mux(Mux3* m3) {
		source2Mux = m3;
	}

	void setForwardingUnit(ForwardingUnit* fu) {
		forwardingUnit = fu;
	}

	void setMux3_2(Mux3* m3) {
		mux3_2 = m3;
	}

private:

	MIPSInstruction mipsInstruction;

	int aluOut, tD, taOrDa;

	int memWrite, memToReg, regWrite, dataMemoryMuxSelection;

	Buffer4* buffer4;

	Mux2* dataMemoryMux;

	DataMemory* dataMemory;

	Mux3* source1Mux;

	Mux3* source2Mux;

	ForwardingUnit* forwardingUnit;

	Mux3* mux3_2;
};

#endif