//
//  InstructionMemory.cpp
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/11/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "InstructionMemory.h"
InstructionMemory:: InstructionMemory(std::vector<MIPSInstruction> Instr){
    
}
InstructionMemory::~InstructionMemory(){
    
}
void InstructionMemory:: execute(){
    regFile -> set(Instructions[ address ]);
    regMux -> setI0(Instructions[ address ].getTA());
    regMux -> setI1(Instructions[ address ].getDA());
    ctrlUnit -> set(Instructions[ address ].getInstructionName());
    aluMux -> setI1(Instructions[ address ].getImm());
    alu -> setInstruction(Instructions[ address ].getInstructionName());
    branchAdder1 = address + 1 + Instructions[ address ].getImm();
    
    branchAdder2 = branchAdder1;
    
}
void InstructionMemory::setAddress(int a){
    address = a;
}
void InstructionMemory:: setAdderMux(Mux2* m){
    adderMux = m;
}
