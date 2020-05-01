#include <stdio.h>

// In C, all function arguments are passed "by value". This means that the called function is give he values of its aguments in tempory
// variables rather that the originals  Citado del libro programmin in C de K&D

// It usually leads to more compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized
// local variables in the called routine
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n)
		p = p * base;
	return(p);
}
