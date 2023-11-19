/*

*/

#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;
using uint32 = unsigned int;

struct memory {
	static constexpr uint32 MAX_MEM = 1024 * 64;
	Byte Data[MAX_MEM];

	void Initialise() {
		for (uint32 i = 0; i < MAX_MEM; i++) {
			Data[i] = 0;
		}
	}
};

struct cpu_6502 {
	
	// program counter and stack pointer
	Word pcounter, spointer; 

	Byte accumulator, irx, iry;

	// processor status flags
	Byte carry : 1;
	Byte zero : 1;
	Byte interrupt : 1;
	Byte decimal : 1;
	Byte breakc : 1;
	Byte overflow : 1;
	Byte negative : 1;

	// https://www.c64-wiki.com/wiki/Reset_(Process)
	//Reset Vector Address is Hex-Code FFFC
	void Resetcpu(memory& mem) {
		pcounter = 0xFFFC;
		// the first stack access happens at 0x0100
		spointer = 0x0100;
		carry = zero = interrupt = decimal = breakc = overflow = negative = 0;
		accumulator = irx = iry = 0;
		mem.Initialise();
	}
};

int main() {
	memory mem;
	cpu_6502 cpu;
	cpu.Resetcpu(mem);
	return 0;
}