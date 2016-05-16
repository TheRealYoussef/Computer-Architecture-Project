#include "InstructionMemory.h"

void InstructionMemory:: execute() {
	if (address < instructions.size())
		buffer1->setMipsInstruction(instructions[address]);
	else {
		MIPSInstruction temp;
		temp.setRType("nop", MIPSInstruction::ADD, 0);
		buffer1->setMipsInstruction(temp);
		++counter;
	}
	//add jump set
}

void InstructionMemory::setAddress(int a){
    address = a;
}
