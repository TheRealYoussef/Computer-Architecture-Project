#include "InstructionMemory.h"
#include "BranchPrediction.h"
#include <iostream>

void InstructionMemory:: execute() {
	if (address < instructions.size()) {
		buffer1->setMipsInstruction(instructions[address]);
		std::cout << instructions[address].getLine() << std::endl;
		branchPrediction->nextInstruction(instructions[address], address);
	}
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
