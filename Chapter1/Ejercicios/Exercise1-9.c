/**
 *  *******************************************************************************************************
 *  * Ejercicio del libro progamming in C                                                                 *
 *  *                                                                                                     *
 *  * Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or      *
 *  *               more blanks by a single blank                                                         *
 *  *******************************************************************************************************
 */

#define EOF -1

int main(void)
{

	int Character, StoredCharacterBack = EOF;

	while ((Character = getchar()) != EOF)
	{
		if ((StoredCharacterBack == ' ' || StoredCharacterBack == '\t') && !(Character == ' ' || Character == '\t'))
			putchar(Character);
		else if (!(Character == ' ' || Character == '\t') && !(StoredCharacterBack == ' ' || StoredCharacterBack == '\t'))
			putchar(Character);

		if (!(StoredCharacterBack == ' ' || StoredCharacterBack == '\t') && (Character == ' ' || Character == '\t'))
			putchar(' ');

		StoredCharacterBack = Character;
	}
	return (0);
}
