/**
 *                    Program to count the input characters.
 *                    While(Read a character and if that character is not end of file indicator)
 *                            Count that character
 */

#include <stdio.h> // Tells the compiler that includes the stdio.h library

int main(void) // A function called main is defined, Which receives no arguments but returns an integer type
{
	long int nc;     /* A long int type is declared, which is the same if we simply weite long, this
			    is to contain a larger value that the maximun range accepted by int
			    (since long es a quialifier that increases that range) */

	nc  = 0;         /*  The variable nc was initialized, since if it is not initialized it will contain
			     garbage content and errors will appear, either soon afted compilation 
			     or in the correct number of counted character, it is not the one that appears in nc*/

	while(getchar() != EOF)
		nc++;     /* It is a unaty operator that increments what the variable nc stores by 1,
			     therefore it is the same as writing nc = nc + 1 */
	printf("El numero total de caracteres que escribio en el teclado es, sin incluir claro esta el valos EOF: %ld\n", nc);
	return (0);       // successful exit
}
/*Things to keep in mind, when declaring a variable of type long int,
we have to put in the pirntf the qualifier% ld, and remember that printf
does not print by itself line breaks. */
