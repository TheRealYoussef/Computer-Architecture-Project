//
//  InstructionMemory.h
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/11/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __ComputerArchitecture__InstructionMemory__
#define __ComputerArchitecture__InstructionMemory__

#include <stdio.h>
#include <vector>
#include "MIPSInstruction.h"
#include "ControlUnit.h"
#include "RegFile.h"
#include "ALU.h"
#include "Mux2.h"
class InstructionMemory{
    
    
public:
    InstructionMemory(std::vector<MIPSInstruction>);
    ~InstructionMemory();
    void setAddress(int);
    void setAdderMux(Mux2*);
    void execute();
private:
    
    std::vector<MIPSInstruction> Instructions;
    int address, branchAdder1, branchAdder2;
    Mux2 *mux,*regMux, *aluMux, *adderMux;
    ControlUnit *ctrlUnit;
    RegFile *regFile;
    ALU *alu;
    
};
#endif /* defined(__ComputerArchitecture__InstructionMemory__) */
