/**
 *               ************************************************************************************************************************************
 *               *     While(Read next Character -> Character is not end of file indicator)                                                         *
 *               *          if (if the variable temp is in a word and if the variable 'c' is a line, space or tab break (c is not inside a word))   *
 *               *                    count the word that is currently temp)                                                                        *
 *               *                                                                                                                                  *
 *               ************************************************************************************************************************************
 */

#include <stdio.h> /* With this library we can use the value of EOF
		      (which is a symbolic constant) and the printf function */

// These macros were defined with these expressions, so as not to have such a long condition

#define VERELFUTURO(x)  (((x) != (' ')) && ((x) != ('\t')) && ((x) != ('\n')) && ((x) != ('\0')))
#define VALORACTUAL(d)  (((c) == (' ')) || ((c) == ('\t')) || ((c) == ('\n')))

#define VALUEI '\0'  // to initial the temporary variable.

int main(void)  // A function called man is defined
{
	int c;   // This integer variable will sotre the next character sent by the getchar function
	int nw;  // Will store the number of word written
	int nc;  // Counter for characters that were typed on the keyboard
	int nl;  // Will store the number of lines written
	int temp = VALUEI;  // we define the variable temp with its respective symbolic constant

	nw = (nc = (nl = 0));   /* This is not a special case, we can see that an assignment is an
				   Expression with a value, and that assignments are assigned from
				   right to left*/

	while((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;
		if (VALORACTUAL(c) && VERELFUTURO(temp))  /* For this condition to be met, the variable temp must be in a word
							     and c must be a line break, tabular or space */
			nw++;
		temp = c;
	}
	if (VERELFUTURO(temp) && (c == EOF))
	    nw++;
	printf("\nNumero de palabras contadas es: %d\nNumero de caracteres es: %d\nNumero de lineas es: %d\n", nw, nc, nl);
	return(0);  // Successful  exit.
}
