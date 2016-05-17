#include "HazardDetection.h"
#include "ProgramCounter.h"
#include "Buffer2.h"

void HazardDetection::execute() {
	if (previousInstruction.getInstructionName() == MIPSInstruction::LW) {
		if (currentInstruction.getInstructionName() == MIPSInstruction::ADD || currentInstruction.getInstructionName() == MIPSInstruction::SUB || currentInstruction.getInstructionName() == MIPSInstruction::OR || currentInstruction.getInstructionName() == MIPSInstruction::XOR || currentInstruction.getInstructionName() == MIPSInstruction::SLT || currentInstruction.getInstructionName() == MIPSInstruction::BEQ || currentInstruction.getInstructionName() == MIPSInstruction::BNE || currentInstruction.getInstructionName() == MIPSInstruction::BLE) {
			if (previousInstruction.getTA() == currentInstruction.getSA() || previousInstruction.getTA() == currentInstruction.getTA()) {
				buffer2->setDontWrite2(1);
				programCounter->stall();
			}
			else
				buffer2->setDontWrite2(0);
		}
		else if (currentInstruction.getInstructionName() == MIPSInstruction::ADDI || currentInstruction.getInstructionName() == MIPSInstruction::LW) {
			if (previousInstruction.getTA() == currentInstruction.getSA()) {
				buffer2->setDontWrite2(1);
				programCounter->stall();
			}
			else
				buffer2->setDontWrite2(0);
		}
		else if (currentInstruction.getInstructionName() == MIPSInstruction::JR) {
			if (previousInstruction.getTA() == currentInstruction.getSA()) {
				buffer2->setDontWrite2(1);
				programCounter->stall();
			}
			else
				buffer2->setDontWrite2(0);
		}
		else
			buffer2->setDontWrite2(0);
	}
	else if (previousPreviousInstruction.getInstructionName() == MIPSInstruction::LW) {
		if (currentInstruction.getInstructionName() == MIPSInstruction::JR) {
			if (previousPreviousInstruction.getTA() == currentInstruction.getSA()) {
				buffer2->setDontWrite2(1);
				programCounter->stall();
			}
			else
				buffer2->setDontWrite2(0);
		}
		else
			buffer2->setDontWrite2(0);
	}
	else
		buffer2->setDontWrite2(0);
}