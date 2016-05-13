//
//  RegFile.h
//  Computer Architecture
//
//  Created by Heba Sakr on 5/4/16.
//  Copyright (c) 2016 Heba Sakr. All rights reserved.
//

#ifndef __Computer_Architecture__RegFile__
#define __Computer_Architecture__RegFile__

#include <stdio.h>
#include "MIPSInstruction.h"
#include <array>
#include "Mux2.h"
#include "ALU.h"
#include "DataMemory.h"
using namespace std;
class RegFile{
public:
    RegFile();
    ~RegFile();
    int getSD() const;
    int getTD() const;
    int getWR() const;
    int getImm() const;
    void setRegWrite(bool);
    void set(MIPSInstruction mips);
    void setMux2(Mux2*);
    void setAluMux(Mux2*);
    void setALU(ALU*);
    void setFinalMux2(Mux2*);
    void setDataMemory(DataMemory*);
    
private:
    DataMemory *dataMemory;
    int sD,tD, writeRegister,opcode, writeData;
    array<int,16> registers;
    MIPSInstruction instruction;
    bool regWrite;
    Mux2 *mux2, *finalMux2, *aluMux;
    ALU *alu;
    
    
    
};

#endif /* defined(__Computer_Architecture__RegFile__) */
