#ifndef _RC4_H_
#define _RC4_H_

#include <windows.h>

typedef struct _RC4_CONTEXT{
	DWORD	i;
	DWORD	j;
	BYTE	s[256];
} RC4_CONTEXT, * PRC4_CONTEXT;

VOID RC4Init(PRC4_CONTEXT Context, LPCSTR Key, SIZE_T Length);
VOID RC4Cipher(PRC4_CONTEXT Context, LPCSTR Input, PCHAR Output, SIZE_T Length);

#endif