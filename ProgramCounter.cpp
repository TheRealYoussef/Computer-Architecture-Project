//
//  ProgramCounter.cpp
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/12/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "ProgramCounter.h"

ProgramCounter:: ProgramCounter(){
}
ProgramCounter:: ~ProgramCounter(){
}
void ProgramCounter:: execute(){
    instructiomMemory -> setAddress(PC);
    ++PC;
    adderMux -> setI0(PC);
}
void ProgramCounter:: setPC(int counter){
    PC = counter;
}
int ProgramCounter:: getPC() const{
    return PC;
}
void ProgramCounter:: setAdderMux(Mux2* m){
    adderMux = m;
}
