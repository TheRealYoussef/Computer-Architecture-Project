#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

#include "InstructionMemory.h"
#include "Jump.h"
#include "Buffer1.h"
#include "Mux2.h"

class ProgramCounter {
    
public:

    ProgramCounter();

    void execute();

    void setPC(int);

	void setInstructionMemory(InstructionMemory* im) {
		instructiomMemory = im;
	}

	void setJump(Jump* j) {
		jump = j;
	}

	void setBuffer1(Buffer1* b1) {
		buffer1 = b1;
	}

	void setBranchMux(Mux2* m2) {
		branchMux = m2;
	}

private:

    int PC;

    InstructionMemory *instructiomMemory;

	Jump* jump;

	Buffer1* buffer1;

	Mux2* branchMux;
};

#endif
