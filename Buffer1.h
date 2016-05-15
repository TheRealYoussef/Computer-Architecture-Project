#ifndef BUFFER_1_H
#define BUFFER_1_H

#include "MIPSInstruction.h"
#include "Buffer2.h"
#include "ControlUnit.h"
#include "Mux2.h"
#include "RegFile.h"

class Buffer1 {

public:

	void setMipsInstruction(const MIPSInstruction& instr) {
		mipsInstruction = instr;
	}

	void setPCPlus4(int pc) {
		pcPlus4 = pc;
	}

	void execute() {
		buffer2->setMipsInstruction(mipsInstruction);
		buffer2->setPCPlus4(pcPlus4);
		controlUnit->set(mipsInstruction.getInstructionName());
		taOrDaMux->setI0(mipsInstruction.getTA());
		taOrDaMux->setI1(mipsInstruction.getDA());
		regFile->setSA(mipsInstruction.getSA());
		regFile->setTA(mipsInstruction.getTA());
	}

	void setBuffer2(Buffer2* b2) {
		buffer2 = b2;
	}

	void setControlUnit(ControlUnit* cu) {
		controlUnit = cu;
	}

	void setTAOrDAMux(Mux2* td) {
		taOrDaMux = td;
	}

	void setRegFile(RegFile* rf) {
		regFile = rf;
	}

private:

	MIPSInstruction mipsInstruction;

	int pcPlus4;

	Buffer2* buffer2;

	ControlUnit* controlUnit;

	Mux2* taOrDaMux;

	RegFile* regFile;
};

#endif