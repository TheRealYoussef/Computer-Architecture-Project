//
//  DataMemory.cpp
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/11/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "DataMemory.h"
DataMemory:: DataMemory(){
    
}
DataMemory:: ~DataMemory(){
    
}

void DataMemory::execute(){
    finalMux ->setI1(readData);
}

void DataMemory::setWriteData(int wr){
    writeData = wr;
}
void DataMemory::setAddress(int a){
    address = a;
}
void DataMemory::setMemWrite(int mw){
    memWrite = mw;
    
}
void DataMemory::setMemRead(int mr){
    memRead = mr;
    
}

void DataMemory::setFinalMux(Mux2* m2){
    finalMux = m2;
}