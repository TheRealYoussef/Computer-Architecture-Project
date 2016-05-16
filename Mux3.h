#ifndef MUX_3_H
#define MUX_3_H

class ALU;
class Buffer3;
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
    
	void setALU(ALU* a);

	void execute();

	void setBuffer3(Buffer3*);

private:

	int idx;

    int I0, I1, I2, S;

	ALU* alu;

	Buffer3* buffer3;
};

#endif
