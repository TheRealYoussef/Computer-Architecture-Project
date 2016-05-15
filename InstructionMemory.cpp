#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(const std::vector<MIPSInstruction> & instr){
	instructions = instr;
}

void InstructionMemory:: execute() {
	buffer1->setMipsInstruction(instructions[address]);
	//add jump set
}

void InstructionMemory::setAddress(int a){
    address = a;
}
