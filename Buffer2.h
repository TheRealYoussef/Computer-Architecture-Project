#ifndef BUFFER_2_H
#define BUFFER_2_H

#include "MIPSInstruction.h"
#include "Buffer3.h"
#include "Mux2.h"
#include "Mux3.h"
#include "Adder.h"

class Buffer2 {

public:

	void setMipsInstruction(const MIPSInstruction& instr) {
		mipsInstruction = instr;
	}

	void setPCPlus4(int pc) {
		pcPlus4 = pc;
	}

	void setSD(int s) {
		sD = s;
	}

	void setTD(int t) {
		tD = t;
	}

	void setTaOrDa(int td) {
		taOrDa = td;
	}

	void setBranch(int b) {
		branch = b;
	}

	void setMemWrite(int w) {
		memWrite = w;
	}

	void setMemToReg(int r) {
		memToReg = r;
	}

	void setAluSrc(int s) {
		aluSrc = s;
	}

	void setRegWrite(int w) {
		regWrite = w;
	}

	void execute() {
		buffer3->setMipsInstruction(mipsInstruction);
		buffer3->setTD(tD);
		buffer3->setTaOrDa(taOrDa);
		tdOrImmMux->setI0(tD);
		tdOrImmMux->setI1(mipsInstruction.getImm());
		tdOrImmMux->setS(aluSrc);
		source1Mux->setI0(sD);
		branchAdder->setS1(pcPlus4);
		branchAdder->setS2(mipsInstruction.getImm());
	}

	void setBuffer3(Buffer3* b3) {
		buffer3 = b3;
	}

	void setTDOrImmMux(Mux2* ti) {
		tdOrImmMux = ti;
	}

	void setSource1Mux(Mux3* s1) {
		source1Mux = s1;
	}

	void setBranchAdder(Adder* adder) {
		branchAdder = adder;
	}

private:

	MIPSInstruction mipsInstruction;

	int pcPlus4;

	int sD, tD, taOrDa;

	int branch, memWrite, memToReg, aluSrc, regWrite;

	Buffer3* buffer3;

	Mux2* tdOrImmMux;

	Mux3* source1Mux;

	Adder* branchAdder;
};

#endif