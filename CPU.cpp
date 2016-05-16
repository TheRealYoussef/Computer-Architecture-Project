#include "CPU.h"
#include "MIPSParser.h"

CPU::CPU() : mux2_0(0), mux2_1(1), mux2_2(2), mux2_3(3), mux2_4(4), mux2_5(5), mux3_0(0), mux3_1(1), mux3_2(2) {
	mux2_0.setMux2_1(&mux2_1);
	mux2_0.setProgramCounter(&programCounter);
	//mux2_1.setProgramCounter(&programCounter);
	programCounter.setInstructionMemory(&instructionMemory);
	programCounter.setBuffer1(&buffer1);
	programCounter.setBranchMux(&mux2_0);
	instructionMemory.setBuffer1(&buffer1);
	buffer1.setBuffer2(&buffer2);
	buffer1.setControlUnit(&controlUnit);
	buffer1.setRegFile(&regFile);
	buffer1.setTAOrDAMux(&mux2_2);
	controlUnit.setBuffer2(&buffer2);
	controlUnit.setTAOrDAMux(&mux2_2);
	regFile.setBuffer2(&buffer2);
	mux2_2.setBuffer2(&buffer2);
	buffer2.setBranchAdder(&adder);
	buffer2.setBuffer3(&buffer3);
	buffer2.setForwardingUnit(&forwardingUnit);
	buffer2.setSource1Mux(&mux3_0);
	buffer2.setTDOrImmMux(&mux2_3);
	buffer2.setALU(&alu);
	buffer2.setMux3_2(&mux3_2);
	mux2_3.setMux3_1(&mux3_1);
	mux3_0.setALU(&alu);
	mux3_1.setALU(&alu);
	mux3_2.setBuffer3(&buffer3);
	adder.setBranchMux(&mux2_0);
	alu.setBuffer3(&buffer3);
	alu.setMux2_0(&mux2_0);
	forwardingUnit.setBuffer3(&buffer3);
	forwardingUnit.setMux3_0(&mux3_0);
	forwardingUnit.setMux3_1(&mux3_1);
	forwardingUnit.setMux3_2(&mux3_2);
	buffer3.setBuffer4(&buffer4);
	buffer3.setDataMemory(&dataMemory);
	buffer3.setDataMemoryMux(&mux2_4);
	buffer3.setForwardingUnit(&forwardingUnit);
	buffer3.setSource1Mux(&mux3_0);
	buffer3.setSource2Mux(&mux3_1);
	buffer3.setMux3_2(&mux3_2);
	mux2_4.setDataMemory(&dataMemory);
	dataMemory.setBuffer4(&buffer4);
	buffer4.setDataMemoryMux(&mux2_4);
	buffer4.setFinalMux(&mux2_5);
	buffer4.setForwardingUnit(&forwardingUnit);
	buffer4.setRegFile(&regFile);
	buffer4.setSource1Mux(&mux3_0);
	buffer4.setSource2Mux(&mux3_1);
	buffer4.setMux3_2(&mux3_2);
	mux2_5.setRegFile(&regFile);
	MIPSParser parser;
	parser.parse("test.txt");
	instructionMemory.setInstructions(parser.getInstructions());
}

void CPU::execute() {
	while (true) {
		buffer4.execute();
		mux2_5.execute();
		regFile.write();
		buffer3.execute();
		mux2_4.execute();
		dataMemory.execute();
		buffer2.execute();
		adder.execute();
		forwardingUnit.execute();
		mux2_3.execute();
		mux3_0.execute();
		mux3_1.execute();
		alu.execute();
		mux3_2.execute();
		buffer1.execute();
		controlUnit.execute();
		mux2_2.execute();
		regFile.read();
		programCounter.execute();
		mux2_0.execute();
		//mux2_1.execute();
		instructionMemory.execute();
	}
}