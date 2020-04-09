/**
 *                  Counter Line
 *                  While(Read un character -> Character is not end of file indicator)
 *                              if (The character that was read is equal to the new line)
 *                                            add to the content of the counter one
 */

#include <stdio.h>

int main(void) // The main function was defined, Where you will not enter arguments but return an integer type
{
	int c, nl;   // Two integer variables are declared, that is, they only store integer data

      	while((c = getchar()) != EOF)
		if (c == '\n')  /* The condition is evaluated and if it is true, that is, if (c == '\n')
				   is true then this will take the value of 1 (value of truth), therefore the
				   condition is met and whatever is inside the contidion is executed */
			nl++;
	printf("Numero total de linas que se ingresaron fueron: %d\n", nl);
	return (0);        // Seccessful exit
}
