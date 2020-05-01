/**
 *    *****************************************************************************************************************************
 *    * Let's write a power function(m ,n) to raise an integer m to a positive integer n.                                         *
 *    *                                                                                                                           *
 *    *            Progam Structure                                                                                               *
 *    *            While(the exponent is greater that or equal to one)                                                            *
 *    *                  A mathematical operation is performed to save the base result                                            *
 *    *****************************************************************************************************************************
 */

#include <stdio.h>

// The prototype was declared, but it is incorrect to say that the prototype of a certain function was defined.
/* That is to say:

   Why do you says that power is a function that expects two int argument and return an int, this declaration,
   which is called a function prototype has to agree with the definition and uses of power. cita del libro programmin in C de K&D

   And this makes sense because if we remember to declare that it is to give the properties to something, in this line
   We are giving the properties to the power function. */
int power(int m, int n);

int main(void)
{
	int i;

	for(i = 0; i < 10 ; ++i)
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
	return(0);
}

/* power: raise base to n-th power; n >= 0 */

int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; 1 <= n; ++i)
		p = p * base;
	return (p);
}

// power: raise base to n-th power; n >= 0
/*          (old - style version )*/
int powerOLD(base, n)
	int base, n;
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; i++)
		p = p * base;
	return (p);
}
