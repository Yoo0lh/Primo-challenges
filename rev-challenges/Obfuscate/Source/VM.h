#ifndef _VM_H_
#define _VM_H_

#include <Windows.h>
#include <stdio.h>

typedef VOID(*HANDLER_TYPE)();

typedef enum {
	OPCODE_PRINT	= 0x2A,
	OPCODE_COPY		= 0x5D,
	OPCODE_DECRYPT	= 0x3C,
	OPCODE_ZERO		= 0x18

} VM_INSTRUCTIONS;

VOID VMPrint();
VOID VMCopy();
VOID VMZero();
VOID VMDecrypt();
VOID VMDispatcher(PBYTE Instructions, SIZE_T InstructionsLength);

#endif // !_VM_H_
