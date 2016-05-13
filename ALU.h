//
//  ALU.h
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/11/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __ComputerArchitecture__ALU__
#define __ComputerArchitecture__ALU__

#include <stdio.h>
#include "MIPSInstruction.h"
#include "DataMemory.h"
#include "Mux2.h"
class ALU{
    
public:
    ALU();
    ~ALU();
    void execute();
    int getAlutResult();
    void setSource1(int);
    void setMux2(Mux2*);
    void setFinalMux(Mux2*);
    void setInstruction(MIPSInstruction::InstructionName);
    void setDataMemory(DataMemory*);
private:
    DataMemory *dataMemory;
    Mux2 *mux2, *finalMux;
    MIPSInstruction::InstructionName instruction;
    int source1, source2, zero, result;
    
};
#endif /* defined(__ComputerArchitecture__ALU__) */
