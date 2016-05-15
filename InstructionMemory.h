#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>
#include "MIPSInstruction.h"
#include "Buffer1.h"
#include "Jump.h"

class InstructionMemory {

public:

    InstructionMemory(const std::vector<MIPSInstruction>&);

    void setAddress(int);

    void execute();

	void setJump(Jump* j) {
		jump = j;
	}

	void setBuffer1(Buffer1* b1) {
		buffer1 = b1;
	}

private:
    
    std::vector<MIPSInstruction> instructions;

	int address;
	
	Buffer1* buffer1;

	Jump* jump;
};

#endif
