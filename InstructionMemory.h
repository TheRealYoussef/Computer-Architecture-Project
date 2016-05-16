#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>
#include "MIPSInstruction.h"
#include "Buffer1.h"
#include "Jump.h"

class InstructionMemory {

public:

	void setInstructions(const std::vector<MIPSInstruction>& inst) {
		instructions = inst;
	}

    void setAddress(int);

    void execute();

	void setJump(Jump* j) {
		jump = j;
	}

	void setBuffer1(Buffer1* b1) {
		buffer1 = b1;
	}

	bool stop() {
		return counter == 3;
	}

private:
    
    std::vector<MIPSInstruction> instructions;

	int address;
	
	Buffer1* buffer1;

	Jump* jump;

	int counter;
};

#endif
