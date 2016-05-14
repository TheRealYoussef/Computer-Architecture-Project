#ifndef ALU_H
#define ALU_H

#include "MIPSInstruction.h"
#include "Object.h"
class ALU : public Object {

public:

    void execute();

    int getAlutResult();

	void setSource1(int);

	void setSource2(int);

    void setInstruction(MIPSInstruction::InstructionName);

private:

	int source1, source2, zero, result;

	MIPSInstruction::InstructionName instruction;
};

#endif