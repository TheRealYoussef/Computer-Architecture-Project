#ifndef CPU_H
#define CPU_H

#include "ProgramCounter.h"
#include "ALU.h"

class CPU {

public:

	CPU();

	void execute();

private:

	Mux2 mux2_0, mux2_1, mux2_2, mux2_3, mux2_4, mux2_5;

	Mux3 mux3_0, mux3_1, mux3_2;

	ProgramCounter programCounter;

	InstructionMemory instructionMemory;

	Buffer1 buffer1;

	Buffer2 buffer2;

	Buffer3 buffer3;

	Buffer4 buffer4;

	RegFile regFile;

	ControlUnit controlUnit;

	ForwardingUnit forwardingUnit;

	ALU alu;

	DataMemory dataMemory;

	Adder adder;
};

#endif