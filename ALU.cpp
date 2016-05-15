#include "ALU.h"

void ALU:: execute() {
	int result, zero;
	if (instruction == MIPSInstruction::XOR)
		result = source1 ^ source2;
	else if (instruction == MIPSInstruction::OR)
		result = source1 | source2;
	else if (instruction == MIPSInstruction::BEQ)
		zero = source1 == source2;
	else if (instruction == MIPSInstruction::BNE)
		zero = source1 != source2;
	else if (instruction == MIPSInstruction::BLE)
		zero = source1 <= source2;
	else if (instruction == MIPSInstruction::SUB)
		result = source1 - source2;
	else if (instruction == MIPSInstruction::SLT)
		result = source1 < source2;
	else
		result = source1 + source2;
	buffer3->setALUOut(result);
	mux2_0->setS(zero && branch);
}

void ALU::setInstruction(MIPSInstruction::InstructionName inst) {
    instruction = inst;
}

void ALU::setSource1(int s) {
	source1 = s;
}

void ALU::setSource2(int s) {
	source2 = s;
}

void ALU::setBranch(int b) {
	branch = b;
}

void ALU::setMux2_0(Mux2* m2) {
	mux2_0 = m2;
}

void ALU::setBuffer3(Buffer3* b3) {
	buffer3 = b3;
}