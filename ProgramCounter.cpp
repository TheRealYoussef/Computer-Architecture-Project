#include "ProgramCounter.h"

ProgramCounter:: ProgramCounter() : PC(0) {}

void ProgramCounter:: execute(){
    instructiomMemory -> setAddress(PC);
}

void ProgramCounter:: setPC(int counter){
    PC = counter;
}
