#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>
#include "MIPSInstruction.h"
#include "Object.h"

class InstructionMemory : public Object {

public:

    InstructionMemory(const std::vector<MIPSInstruction>&);

    void setAddress(int);

    void execute();

private:
    
    std::vector<MIPSInstruction> instructions;

	int address;
	
	MIPSInstruction out;
};
#endif /* defined(__ComputerArchitecture__InstructionMemory__) */
