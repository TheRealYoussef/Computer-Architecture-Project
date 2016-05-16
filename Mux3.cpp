#include "Mux3.h"
#include "ALU.h"
#include "Buffer3.h"

void Mux3::setALU(ALU* a) {
	alu = a;
}

void Mux3::execute() {
	int out = (S == 2) ? I2 : (S == 1) ? I1 : I0;
	switch (idx)
	{
	case 0:
		alu->setSource1(out);
		break;
	case 1:
		alu->setSource2(out);
		break;
	default:
		buffer3->setTD(out);
	}
}

void Mux3::setBuffer3(Buffer3* b3) {
	buffer3 = b3;
}