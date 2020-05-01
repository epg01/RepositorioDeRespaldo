#define EOF -1    // Since "library" is not used in this function, then we need to define the EOF value and we do it with a symbolic constant.

/* The only thing that was done here was to reduce the code to a single line, without any further improvement to the getlinee used in the book. */

int getlinee(char s[], int lim)
{
	int i, c;

	for (i = 0;(i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return (i);
}
