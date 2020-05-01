/**
 *    Let is write a program to count the number of occurrences of each digit, of white space
 *    characters (blank, tab, newline), and of all other characters
 *
 */
#include <stdio.h>

// Two symbolic constants were defined

#define DIGIT 10             // The total amount that  array sotres
#define CERO  0              // The  initialization fot the array

#define SPACE(x) (((x) == (' ')) || ((x) == ('\n')) || ((x) == ('\t')))  // A macro was defined, so as not to put that group of logical operators in the first if statement


int main(void)   // A function main is defined.
{
	int c;        // This variable stores the next character entered by the getchar function
	int i;        // Indexing variable fot the array
	int nwhite;   // Conunter for spaces(blanks, tabs and newline)
	int nother;   // Counter fot the other characters
	int ndigit[DIGIT];      // An array with 10 memory cells was defined

	for (i = 0; i < 10; ++i)    // In this loop, all the array variables are initialized in cero
		ndigit[i] = CERO;

	nwhite = 0, nother = 0;       // The comma operator is used to initialize the counters to zero, another way to write nwhite = newline = 0;
	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')  // Here the magic happens, the sentence below, select the varialbe that has to do with the number and add one, all those variables are counter
			++ndigit[c - '0'];
		else if (SPACE(c))
			++nwhite;
		else
			++nother;
	}
	// The output of the while loop is printed here
	printf("digits =");
	for(i = 0; i < DIGIT; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space: %d, other: %d\n", nwhite, nother);
	return(0);  // Successful exit
}
