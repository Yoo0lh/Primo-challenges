#include "VM.h"

BYTE Opcode[] = {
	OPCODE_PRINT,
	OPCODE_COPY,
	OPCODE_DECRYPT,
	OPCODE_ZERO
};

int main() {

	VMDispatcher(Opcode, sizeof(Opcode));

	return (0);
}