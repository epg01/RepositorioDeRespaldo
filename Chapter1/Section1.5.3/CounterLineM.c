#include <stdio.h> // The compiler will include this library, this happens in the preproccessing I thin.

int main(void)  // A main function was declared.
{
	int c, nl;   // Two variables of type integer (int) were declared

	for(nl = 0; (c = getchar()) != EOF; )  /* You can see that in this example and in the previous one,
						  the while and the for are the same, simply that in the for
					          the increment control is in a single line */
		if(c == '\n')
			nl++;

	printf("El numero de lineas es: %d\n", nl);
	return (0);  // Succuessful exit
}
