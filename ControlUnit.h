//
//  Decoder.h
//  ArchitectureProject
//
//  Created by Baher Mursi on 5/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __ArchitectureProject__ControlUnit__
#define __ArchitectureProject__ControlUnit__

#include <stdio.h>
#include "MIPSInstruction.h"
#include "RegFile.h"
#include "Mux2.h"
#include "DataMemory.h"
class ControlUnit{
    
    
public:
    ControlUnit();
  //  ControlUnit(int); //opcode
    ~ControlUnit();
    
    bool getJump();
    bool getRegDst();
    bool getBranch();
    bool getMemRead();
    bool getMemReg();
    bool getMemWrite();
    int  getAluOp();
    bool getAluSrc();
    bool getRegWrite();
    void setOpcode(int);
    void setRegMux(Mux2*);
    void setFinalMux(Mux2*);
    void setDataMemory(DataMemory*);
    void set(MIPSInstruction:: InstructionName);
   
    
private:
    DataMemory *dataMemory;
    Mux2 *regMux, *finalMux;
    RegFile *regs;
    bool jump, regDst, branch, memRead, memWrite, memReg, AluSrc, regWrite;
    int  AluOp;
    int opcode;
    
};
#endif /* defined(__ArchitectureProject__ControlUnit__) */
