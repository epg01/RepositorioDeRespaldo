/**
 *    This function works as follows
 *
 *    Read a Character
 *          While(Character is not end-of-file indicator)
 *                   output the character just read
 *                   read a character
 */

#include <stdio.h> // Tells the compiler that it includes the <stdio.h> libraty

int main(void)     // A function is defined that does not receive any paramter, but retunr an integer data type
{
	int c;     // C must be declared large enough to contain any value that getchar can return(including EOF)

	c = getchar();   // Waiting for character input, when this input is entered each call to getchar will enter the next character to variable C.
	while (c != EOF){    // The loop cycle will be broken until you end the file in this case it is (C + d)
		putchar(c);   // The next character that is placed in the terminal will ve printed every time puchar is called
		c = getchar(); // Go back and ask for the next character that was copied in the terminal
	}
	return (0);  // Successful return
}
