#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include "MIPSInstruction.h"
#include "Object.h"

class ControlUnit : public Object {

public:

    void set(MIPSInstruction::InstructionName);

	void execute();

private:

    bool jump, regDst, branch, memRead, memWrite, memReg, AluSrc, regWrite;
    int  AluOp;
    int opcode;
};
#endif
