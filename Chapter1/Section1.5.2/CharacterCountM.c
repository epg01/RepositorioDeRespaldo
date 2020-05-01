/**
 *         Code Improved del programa CounterCharacter.c
 */

#include <stdio.h>   /* We don't need this library to use the getchar and putchar functions, but to printf*/

int main(void) // main function defined
{
	long int nc; // We declare the variable nc as only accepting data type long int, that is, integers

	for(nc = 0; getchar() != EOF; nc++)   /* The content that is in the for is called flow control I think. */
		;

	printf("El numero de caracteres contados es: %ld\n", nc);
	return (0); // Successful exit
}
