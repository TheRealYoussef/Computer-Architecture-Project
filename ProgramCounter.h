//
//  ProgramCounter.h
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/12/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __ComputerArchitecture__ProgramCounter__
#define __ComputerArchitecture__ProgramCounter__

#include <stdio.h>
#include "InstructionMemory.h"

class ProgramCounter{
    
public:
    ProgramCounter();
    ~ProgramCounter();
    void execute();
    void setPC(int);
    int getPC() const;
    void setAdderMux(Mux2*);
private:
    int PC;
    InstructionMemory *instructiomMemory;
    Mux2 *adderMux;
};

#endif /* defined(__ComputerArchitecture__ProgramCounter__) */
