#ifndef MIPS_INSTRUCTION_H
#define MIPS_INSTRUCTION_H

class MIPSInstruction {

public:

	static const int NUMBER_OR_INSTRUCTIONS = 14;

	enum InstructionName { ADD, SUB, OR, XOR, SLT, JR, ADDI, BEQ, BNE, BLE, LW, SW, J, JAL };
	
	void setRType(InstructionName instruction, int sA, int tA = 0, int dA = 0) {
		instructionName = instruction;
		s = sA;
		t = tA;
		d = dA;
	}

	void setIType(InstructionName instruction, int sA, int tA, int imm) {
		instructionName = instruction;
		s = sA;
		t = tA;
		i = imm;
	}

	void setJType(InstructionName instruction, int imm) {
		instructionName = instruction;
		i = imm;
	}

	InstructionName getInstructionName() const {
		return instructionName;
	}

	int getSA() const {
		return s;
	}

	int getTA() const {
		return t;
	}

	int getDA() const {
		return d;
	}

	int getImm() const {
		return i;
	}

private:

	InstructionName instructionName;

	int s, t, d, i;
};

#endif