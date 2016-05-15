#ifndef ADDER_H
#define ADDER_H

#include "Mux2.h"

class Adder {

public:

	void setS1(int s) {
		s1 = s;
	}

	void setS2(int s) {
		s2 = s;
	}

	void execute() {
		branchMux->setI1(s1 + s2);
	}

private:

	int s1, s2;

	Mux2* branchMux;
};

#endif