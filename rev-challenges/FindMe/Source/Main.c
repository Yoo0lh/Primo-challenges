#include "RC4.h"
#include <stdio.h>

BYTE Flag[] = { 0x98, 0xc2, 0xd8, 0xb8, 0x0e, 0xa1, 0xb1, 0xd9, 0x9d, 0x65, 0x57, 0xb8, 0xd6, 0x3c, 0xd7, 0x7a, 0x2b };

VOID Decrypt(PRC4_CONTEXT Context) {
	BYTE Key[] = { 0x87, 0x94, 0x78, 0x57, 0x48};

	RC4Init(Context, Key, sizeof(Key));
	RC4Cipher(Context, Flag, Flag, sizeof(Flag));
}

int main() {
	RC4_CONTEXT Context = { 0 };

	Decrypt(&Context);

	puts("[-_0] Trust me, there's nothing here.");
	return (0);
}