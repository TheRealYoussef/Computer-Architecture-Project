#include "DataMemory.h"

void DataMemory::execute() {
	if (memWrite)
		memory[address] = writeData;
	if (address < 16)
		readData = memory[address];
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