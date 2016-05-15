#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

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

private:

    int memory[16];

    int writeData, readData, address, memWrite;
};

#endif
