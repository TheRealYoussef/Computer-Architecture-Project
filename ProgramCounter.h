#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

#include "InstructionMemory.h"
#include "Object.h"

class ProgramCounter : public Object {
    
public:

    ProgramCounter();

    void execute();

    void setPC(int);

private:

    int PC;

    InstructionMemory *instructiomMemory;
};

#endif
