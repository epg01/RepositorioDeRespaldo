/**
 *         The fourth in our series of useful programs counts lines, words, and characters
 *         This will be our structure.
 *
 *         *****************************************************************************************************
 *         *        Two symbolic constants will be defined, so they tell me if getchar                         *
 *         *        is in a word or not.                                                                       *
 *         *        While(Read next Character -> Character is not end of file indicator)                       *
 *         *             if (The character that was read is output of a word)                                  *
 *         *                          There will be a temporary variable where the getchar state is stored     *
 *         *                          (i.e if it is inside a word, its state is 1, 0 if it is outside of it)   *
 *         *             else if(The state of the variable is zero)                                            *
 *         *                          So that's where we count a word and initialize the variable              *
 *         *                          initialize the variable with a state of 1.                               *
 *         *                                                                                                   *
 *         *****************************************************************************************************
 */
#include <stdio.h>  /* When compiling, We ask that you include the symbolic constant EOF
		        and the printf function, since they belong to this library. */

// Two symbolic constants were defined

#define IN  1       // Will indicate that the getchar function is in a word
#define OUT 0       // Wiil indicate that the getchar function is no a word

int main(void)     // A function called main is defined
{
	// Declaration of variables integer type

	int c;        //  This integer variable will sotre the next character sent by the getchar function
	int state;    //  Wil save the state of the getchar function (either that it is in one word or not)
	int nc;       //  Counter for characters that were typed on the keyboard
	int nl;       //  Will store the number of lines written
	int nw;       //  Will store the number of word written

	state = OUT;        // At first it's not in word
	nc = nl = nw = 0;   // The counters were started, so as not to possibly contain garbage content

	while ((c = getchar()) != EOF){
		nc++;

		if (c == '\n')
			nl++;

		if (c == '\n' || c == '\t' || c == ' ')
			state = OUT;

		else if (state == OUT){
			state = IN;
			nw++;
		}
	}
	printf("Numero de caracteres: %d\nNumero de lineas: %d\nNumeros de palabras: %d\n", nc, nl, nw);
	return(0);   // Successful exit.
}
