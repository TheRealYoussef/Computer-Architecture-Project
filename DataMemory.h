#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include "Object.h"

class DataMemory : public Object {
    
public:

    void execute();

    void setWriteData(int);

    void setAddress(int);

    void setMemWrite(int);

private:

    int memory[16]{0};

    int writeData, readData, address, memWrite;
};

#endif
