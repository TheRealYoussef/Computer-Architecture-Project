//
//  DataMemory.h
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/11/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __ComputerArchitecture__DataMemory__
#define __ComputerArchitecture__DataMemory__

#include <stdio.h>
#include "Mux2.h"

class DataMemory{
    
public:
    DataMemory();
    ~DataMemory();
    void execute();
    void setWriteData(int);
    void setAddress(int);
    void setMemWrite(int);
    void setMemRead(int);
    void setFinalMux(Mux2*);
    
private:
    int memory[16]{0};
    int writeData, readData, address, memWrite, memRead;
    Mux2 *finalMux;

};
#endif /* defined(__ComputerArchitecture__DataMemory__) */
