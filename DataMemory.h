#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include "Buffer4.h"

class DataMemory {
    
public:

	DataMemory() {
		for (int i = 0; i < 16; ++i)
			memory[i] = 0;
	}

    void execute();

    void setWriteData(int);

    void setAddress(int);

    void setMemWrite(int);

	void setBuffer4(Buffer4* b4) {
		buffer4 = b4;
	}

private:

    int memory[16];

    int writeData, address, memWrite;

	Buffer4* buffer4;
};

#endif
