/**
 *
 *
 *
 *
 *
 *
 */

#include <stdio.h>

// Prototype of the power() function

int power(int a, int b);
int powerM(int a, int b);

int main(void)    // A main function is defined that receives no argument
{
	// In these three calls of the printf function, the power function is also called

	printf("El resultado es: %d\n", powerM(2,3));
	printf("El resultado es: %d\n", powerM(1,3));
	printf("El resultado es: %d\n", powerM(-2,3));

	return(0);    // Successful exit
}
// A power function is defined that receives and returns certain types of data

int power(int m, int n)
{
	// Two values are defined and declared.

        int Base  = m;
	int Exponente = n;

	while(Exponente > 1)
	        Base = Base * m, Exponente--;
	return (Base);      // Return the value of the Base, that is, the result we need
}

// Another way to do the exercise to further simplify the code is as follows.

int powerM(m, n)    // Another wey to define a funcion.
	int m, n;
{
	int Base;

	// Another way to use the for function

	for(Base = m; --n > 0;)
		Base = Base * m;
	return (Base);    // Return the value of the Base, that is, the result we need.
}
