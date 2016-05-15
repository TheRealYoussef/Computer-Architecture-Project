#ifndef MUX_3_H
#define MUX_3_H

#include "ALU.h"

class Mux3 {
    
public:
    Mux3(int i) {
		idx = i;
    }
    
	void setI0(int i){
		I0 = i;
	}
    void setI1(int i){
        I1 = i;
    }

    void setI2(int i){
        I2 = i;
    }

    void setS(int i){
        S = i;
    }
    
	void setALU(ALU* a) {
		alu = a;
	}

	void execute() {
		int out = (S == 2) ? I2 : (S == 1) ? I1 : I0;
		switch (idx)
		{
		case 0:
			alu->setSource1(out);
			break;
		default:
			alu->setSource2(out);
			break;
		}
	}

private:

	int idx;

    int I0, I1, I2, S;

	ALU* alu;
};

#endif
