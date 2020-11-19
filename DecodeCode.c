#include "DecodeCode.h"


mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = 0;
	instr.immediate = 0;
	instr.rd = 0;
	instr.rt = 0;
	instr.rs = 0;
	instr.opcode = 0;

	int mask = 1;
	int adder = 1;
	for(int i=0; i<32; i++){
		if (i<6){
			if (mask&value){
				instr.funct+=adder;
				instr.immediate += mask;
			}
		}
		else if(i<11){
			if (mask&value){
				instr.immediate += mask;

			}
		}
		else if(i<16){
			if (mask&value){
				instr.rd+= adder;
				instr.immediate += mask;
			}
		}
		else if(i<21){
			if (mask&value){
				instr.rt+=adder;
			}
		}
		else if(i<26){
			if (mask&value){
				instr.rs+=adder;
			}
		}
		else{
			if (mask&value){
				instr.opcode+=adder;
			}
		}
		mask<<=1;
		adder<<=1;
		if (i==5 ||i==10||i==15||i==20||i==25){
			adder =1;
		}

	}

	/*if(instr.opcode !=0){
		instr.immediate = -1;
	}*/




	return instr;
}


