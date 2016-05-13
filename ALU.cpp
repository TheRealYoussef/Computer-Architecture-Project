//
//  ALU.cpp
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/11/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "ALU.h"

ALU::ALU(){
    
}
ALU::~ALU(){
    
}

//Add more functions
void ALU:: execute(){
    if (instruction == MIPSInstruction::XOR)
        result = source1 ^ source2;
    else
        if (instruction == MIPSInstruction::BLE)
            zero = (source1 <= source2);
        else
            if (instruction == MIPSInstruction::SLT)
                result = (source1 < source2);
            else
                result = source1 + source2;
    
    dataMemory -> setAddress(result);
    finalMux -> setI0(result);
    
}

void ALU::setMux2(Mux2 *m2){
    mux2 = m2;
}

void ALU::setFinalMux(Mux2 *m)
{
    finalMux = m;
}
void ALU::setInstruction(MIPSInstruction::InstructionName inst){
    instruction = inst;
}

int ALU:: getAlutResult(){
    return result;
}
void ALU::setSource1(int s){
    source1 = s;
    source2 = mux2->getOut();
}

void ALU:: setDataMemory(DataMemory *dm){
    dataMemory = dm;
}