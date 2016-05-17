#ifndef BRANCH_PREDICTION_H
#define BRANCH_PREDICTION_H

#include "MIPSInstruction.h"
#include <map>
#include "Mux2.h"
#include "ConfirmedNextAddress.h"
#include "Buffer1.h"
#include "Buffer2.h"
#include "Jump.h"

class BranchPrediction {

public:

	void nextInstruction(const MIPSInstruction& instr, int pc) {
		if (instr.getInstructionName() == MIPSInstruction::BEQ || instr.getInstructionName() == MIPSInstruction::BNE || instr.getInstructionName() == MIPSInstruction::BLE) {
			if (btb.find(pc) == btb.end()) {
				btb[pc] = std::make_pair(instr.getImm(), 0);
				mux2_0->setS(0);
			}
			else {
				if (btb[pc].second == 0 || btb[pc].second == 1)
					mux2_0->setS(0);
				else {
					mux2_0->setI1(instr.getImm());
					mux2_0->setS(1);
				}
			}
		} else
			mux2_0->setS(0);
	}

	void confirmPrediction(int pc, bool taken) {
		this->pc = pc;
		this->taken = taken;
	}

	void execute() {
		if (btb.find(pc) != btb.end()) {
			int state = btb[pc].second;
			switch (state)
			{
			case 0:
				if (taken)
					state = 1;
				break;
			case 1:
				if (taken)
					state = 2;
				else
					state = 0;
				break;
			case 2:
				if (taken)
					state = 3;
				else
					state = 1;
				break;
			default:
				if (!taken)
					state = 2;
				break;
			}
			if ((btb[pc].second == 0 || btb[pc].second == 1) && taken) {
				confirmedNextAddress->setAddress(btb[pc].first);
				buffer1->setDontWrite3(1);
				buffer2->setDontWrite4(1);
				buffer1->setStop(true);
				jump->STOP();
			}
			else if ((btb[pc].second == 2 || btb[pc].second == 3) && !taken) {
				confirmedNextAddress->setAddress(pc + 1);
				buffer1->setDontWrite3(1);
				buffer2->setDontWrite4(1);
				buffer1->setStop(true);
				jump->STOP();
			}
			else {
				buffer1->setDontWrite3(0);
				buffer2->setDontWrite4(0);
				buffer1->setStop(false);
			}
			btb[pc].second = state;
		}
		else {
			buffer1->setDontWrite3(0);
			buffer2->setDontWrite4(0);
			buffer1->setStop(false);
		}
	}

	void setMux2_0(Mux2* m2) {
		mux2_0 = m2;
	}

	void setConfirmedNextAddress(ConfirmedNextAddress* next) {
		confirmedNextAddress = next;
	}

	void setBuffer1(Buffer1* b1) {
		buffer1 = b1;
	}

	void setBuffer2(Buffer2* b2) {
		buffer2 = b2;
	}

	void setJump(Jump* j) {
		jump = j;
	}

private:

	//pc, pair<branchPc, prediction>
	std::map<int, std::pair<int, int> > btb;

	int pc;

	bool taken;

	Mux2* mux2_0;

	ConfirmedNextAddress* confirmedNextAddress;
	
	Buffer1* buffer1;

	Buffer2* buffer2;

	Jump* jump;
};

#endif