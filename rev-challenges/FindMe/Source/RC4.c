#include "RC4.h"


VOID RC4Init(PRC4_CONTEXT Context, LPCSTR Key, SIZE_T Length)
{
	DWORD	i;
	DWORD	j;
	BYTE	temp;

	if (Context == NULL || Key == NULL)
		return;

	Context->i = 0;
	Context->j = 0;

	for (i = 0; i < 256; i++)
	{
		Context->s[i] = i;
	}

	for (i = 0, j = 0; i < 256; i++)
	{
		j = (j + Context->s[i] + Key[i % Length]) % 256;

		temp = Context->s[i];
		Context->s[i] = Context->s[j];
		Context->s[j] = temp;
	}
}

VOID RC4Cipher(PRC4_CONTEXT Context, LPCSTR Input, PCHAR Output, SIZE_T Length) {
	BYTE Temp;

	DWORD i = Context->i;
	DWORD j = Context->j;
	PBYTE s = Context->s;

	while (Length > 0)
	{
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		Temp = s[i];
		s[i] = s[j];
		s[j] = Temp;

		if (Input != NULL && Output != NULL)
		{
			*Output = *Input ^ s[(s[i] + s[j]) % 256];

			Input++;
			Output++;
		}

		Length--;
	}

	Context->i = i;
	Context->j = j;
}