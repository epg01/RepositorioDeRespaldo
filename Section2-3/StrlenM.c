#include <stdio.h>

int Strlen(char s[])
{
	int i;

	i = 0;
	while (s[i])
		i++;

	return (i);
}

int StrlenP(char s[])
{
	int i;

	i = 0;
	while (*s++)
		i++;

	return (i);
}
