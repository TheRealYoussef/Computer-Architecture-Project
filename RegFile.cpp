//
//  RegFile.cpp
//  Computer Architecture
//
//  Created by Heba Sakr on 5/4/16.
//  Copyright (c) 2016 Heba Sakr. All rights reserved.
//

#include "RegFile.h"
//int RegFile::sD,RegFile::tD, RegFile::imm;

RegFile:: RegFile(){
    
}
RegFile::~RegFile(){
    
}
void RegFile:: set(MIPSInstruction mips){
    tD =registers[mips.getTA()];
    sD =registers[mips.getSA()];
    writeRegister = mux2->getOut();
    writeData = finalMux2->getOut();
    alu -> setSource1(sD);
    aluMux->setI0(tD);
    
}

int RegFile:: getSD() const{
    return sD;
}
int RegFile:: getTD() const{
    return tD;
}
int RegFile:: getWR() const{
    return writeRegister;
}

int RegFile:: getImm() const{
    return instruction.getImm();
}

void RegFile:: setRegWrite(bool regW){
    regWrite = regW;
}

void RegFile:: setMux2(Mux2 *m2){
    mux2 = m2;
}
void RegFile:: setFinalMux2(Mux2* m2){
    finalMux2 = m2;
}
void RegFile:: setAluMux(Mux2* m2){
    aluMux = m2;
}
void RegFile::setALU(ALU* a){
    alu = a;
}

void RegFile:: setDataMemory(DataMemory *dm){
    dataMemory = dm;
}


