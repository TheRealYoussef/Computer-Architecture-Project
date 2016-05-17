#ifndef HAZARD_DETECTION_H
#define HAZARD_DETECTION_H

#include "MIPSInstruction.h"

class Buffer2;
class ProgramCounter;
class HazardDetection {

public:

	void setBuffer2(Buffer2* b2) {
		buffer2 = b2;
	}

	void setProgramCounter(ProgramCounter* pc) {
		programCounter = pc;
	}

	void setCurrentInstruction(const MIPSInstruction& instr) {
		currentInstruction = instr;
	}

	void setPreviousInstruction(const MIPSInstruction& instr) {
		previousInstruction = instr;
	}

	void setPreviousPreviousInstruction(const MIPSInstruction& instr) {
		previousPreviousInstruction = instr;
	}

	void execute();

private:

	MIPSInstruction currentInstruction, previousInstruction, previousPreviousInstruction;

	Buffer2* buffer2;

	ProgramCounter* programCounter;
};

#endif