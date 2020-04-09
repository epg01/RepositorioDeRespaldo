/**
 *         While((Read a character) and test if -> character is not end-of-file indicator)
 *               output a character just read
 */

#include <stdio.h>  // It is not necessary to includethe stdio.h library since putchar and getchar belong to the standard library

int main(void) // A function called main was defined
{
	int c; // A variable was defined, and it is property is int

	while((c = getchar()) != EOF) //  A assignment can appear as part of a larger expression
		putchar(c);           // The character that i give you getchar in the previous expresion is printed
	return 0;                    // Successful exit
}
