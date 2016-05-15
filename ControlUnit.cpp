#include "ControlUnit.h"

void ControlUnit::set(MIPSInstruction:: InstructionName instr){
	instructionName = instr;
}

void ControlUnit::execute() {
	bool regDst = (instructionName == MIPSInstruction::ADD || instructionName == MIPSInstruction::SUB || instructionName == MIPSInstruction::XOR || instructionName == MIPSInstruction::SLT || instructionName == MIPSInstruction::JR || instructionName == MIPSInstruction::OR);
	bool branch = (instructionName == MIPSInstruction::BLE || instructionName == MIPSInstruction::BEQ || instructionName == MIPSInstruction::BNE);
	bool memToReg = (instructionName == MIPSInstruction::LW || instructionName == MIPSInstruction::SW);
	bool memWrite = (instructionName == MIPSInstruction::SW);
	bool aluSrc = (instructionName == MIPSInstruction::ADDI || instructionName == MIPSInstruction::LW || instructionName == MIPSInstruction::SW || instructionName == MIPSInstruction::BLE || instructionName == MIPSInstruction::BEQ || instructionName == MIPSInstruction::BNE);
	bool regWrite = !(instructionName == MIPSInstruction::J || instructionName == MIPSInstruction::BLE || instructionName == MIPSInstruction::JR || instructionName == MIPSInstruction::SW || instructionName == MIPSInstruction::BEQ || instructionName == MIPSInstruction::BNE);
	taOrDaMux->setS(regDst);
	buffer2->setBranch(branch);
	buffer2->setMemToReg(memToReg);
	buffer2->setMemWrite(memWrite);
	buffer2->setAluSrc(aluSrc);
	buffer2->setRegWrite(regWrite);
}