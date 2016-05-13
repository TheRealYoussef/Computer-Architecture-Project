//
//  Decoder.cpp
//  ArchitectureProject
//
//  Created by Baher Mursi on 5/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "ControlUnit.h"

ControlUnit:: ControlUnit(){
}

ControlUnit:: ~ControlUnit(){
}

//Add the full controls

void ControlUnit:: set(MIPSInstruction:: InstructionName InstType){
    jump=(InstType==MIPSInstruction::J || InstType==MIPSInstruction::JAL || InstType==MIPSInstruction::JR)? 1:0;
    regDst=(InstType==MIPSInstruction::ADD || InstType==MIPSInstruction:: XOR ||InstType==MIPSInstruction::SLT||InstType==MIPSInstruction::JR)?1:0;
    branch= (InstType==MIPSInstruction::BLE)?1:0;
    memRead=(InstType==MIPSInstruction::LW)?1:0;
    memReg=(InstType==MIPSInstruction::LW || InstType==MIPSInstruction:: SW)?1:0;
    memWrite=(InstType==MIPSInstruction:: SW)?1:0;
    AluSrc=(InstType==MIPSInstruction:: ADDI||InstType==MIPSInstruction::LW||InstType==MIPSInstruction::SW||InstType==MIPSInstruction::BLE)?1:0;
    regWrite=(InstType==MIPSInstruction::J ||InstType==MIPSInstruction::BLE||InstType==MIPSInstruction::JAL)?0:1;
    
    regs -> setRegWrite(regWrite);
    regMux -> setS(regDst);
    finalMux -> setS(memReg);
    dataMemory -> setMemRead(memRead);
    dataMemory -> setMemWrite(memWrite);
    
}

void ControlUnit:: setRegMux(Mux2 *m2){
    regMux = m2;
}

void ControlUnit:: setFinalMux(Mux2 *m2){
    finalMux = m2;
}
void ControlUnit::setDataMemory(DataMemory* dm){
    dataMemory = dm;
}
void ControlUnit:: setOpcode(int op){
    opcode = op;
}

bool ControlUnit::  getJump(){
    return jump;
}
bool ControlUnit::  getRegDst(){
    return regDst;
}
bool ControlUnit:: getBranch(){
    return branch;
}
bool ControlUnit:: getMemRead(){
    return memRead;
}
bool ControlUnit:: getMemReg(){
    return memReg;
}
bool ControlUnit:: getMemWrite(){
    return memWrite;
}
int ControlUnit:: getAluOp(){
    return AluOp;
}
bool ControlUnit:: getAluSrc(){
    return AluSrc;
}
bool ControlUnit:: getRegWrite(){
    return regWrite;
}