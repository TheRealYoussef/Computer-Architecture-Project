#ifndef ALU_H
#define ALU_H

#include "MIPSInstruction.h"
#include "Mux2.h"
#include "Buffer3.h"

class ALU {

public:

    void execute();

	void setSource1(int);

	void setSource2(int);

    void setInstruction(MIPSInstruction::InstructionName);

	void setBranch(int);

	void setMux2_0(Mux2*);

	void setBuffer3(Buffer3*);

private:

	int source1, source2;

	MIPSInstruction::InstructionName instruction;

	int branch;

	Mux2* mux2_0;

	Buffer3* buffer3;
};

#endif