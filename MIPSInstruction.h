#ifndef MIPS_INSTRUCTION_H
#define MIPS_INSTRUCTION_H

class MIPSInstruction {

public:

	static const int NUMBER_OR_INSTRUCTIONS = 16;

	enum InstructionName { ADD, SUB, OR, XOR, SLT, JR, ADDI, BEQ, BNE, BLE, LW, SW, J, JAL, JUMP_PROCEDURE, RETURN_PROCEDURE };
	
	void setRType(const std::string& l, InstructionName instruction, int sA, int tA = 0, int dA = 0) {
		line = l;
		instructionName = instruction;
		s = sA;
		t = tA;
		d = dA;
	}

	void setIType(const std::string& l, InstructionName instruction, int sA, int tA, int imm) {
		line = l;
		instructionName = instruction;
		s = sA;
		t = tA;
		i = imm;
	}

	void setJType(const std::string& l, InstructionName instruction, int imm = 0) {
		line = l;
		instructionName = instruction;
		i = imm;
	}

	std::string getLine() const {
		return line;
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

	std::string line;
};

#endif