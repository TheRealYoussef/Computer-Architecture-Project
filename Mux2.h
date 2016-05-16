#ifndef MUX_2_H
#define MUX_2_H

#include "Mux3.h"

class ProgramCounter;
class Buffer2;
class DataMemory;
class RegFile;
class Mux2 {
    
public:

	Mux2(int i) {
		idx = i;
	}

    void setI0(int i){
        I0 = i;
    }

	void setI1(int i){
		I1 = i;
	}

	void setS(int i){
		S = i;
	}

	void execute();

	void setMux2_1(Mux2*);

	void setProgramCounter(ProgramCounter*);

	void setBuffer2(Buffer2*);

	void setMux3_1(Mux3*);

	void setDataMemory(DataMemory*);

	void setRegFile(RegFile*);

private:

	int idx;

	int I0, I1, S;

	Mux2* mux2_1;

	ProgramCounter* programCounter;

	Buffer2* buffer2;

	Mux3* mux3_1;

	DataMemory* dataMemory;

	RegFile* regFile;
};

#endif
