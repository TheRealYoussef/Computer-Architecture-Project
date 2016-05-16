#include "CPU.h"
#include <exception>
#include <iostream>
using namespace std;

int main() {
	try {
		CPU c;
		c.execute();
	}
	catch (exception& e) {
		cerr << e.what();
	}
	return 0;
}