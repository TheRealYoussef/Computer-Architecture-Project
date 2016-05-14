#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(const std::vector<MIPSInstruction> & instr){
	instructions = instr;
}

void InstructionMemory:: execute() {
	out = instructions[address];
}

void InstructionMemory::setAddress(int a){
    address = a;
}
