#include <stdio.h>

#define MAXLINE 3                           /* maximum input line length */

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */

main()
{
	int len;                            /* current line length */
	char line[MAXLINE];                 /* current input line */
	char longest[MAXLINE];              /* longest line saved here */
	int AccountantNumberBiggerMaxline;
	int StoredNumberBiggerMaxline;
	int NumberLessMaxline;

	NumberLessMaxline = AccountantNumberBiggerMaxline = StoredNumberBiggerMaxline = 0;
	while ((len = getlinee(line, MAXLINE)) > 0)
	{
		if (line[len - 1] != '\n')
			AccountantNumberBiggerMaxline += len;
		else if (AccountantNumberBiggerMaxline)
			AccountantNumberBiggerMaxline += len;

/* Cuando getchar encuentra el salto de linea, inicializamos la variable AccountatNumber... para su proximo conteo y guardamos el numero mas garnde de AccountantNumber... */

		if ((AccountantNumberBiggerMaxline > StoredNumberBiggerMaxline) && (line[len - 1] == '\n'))
			StoredNumberBiggerMaxline = AccountantNumberBiggerMaxline, AccountantNumberBiggerMaxline = 0;

		if (len > NumberLessMaxline) {
			NumberLessMaxline = len;
			copy(longest, line);
		}
	}
	if (StoredNumberBiggerMaxline > 0)
		printf("%s\nLongitud de la linea mas larga copiada: %d\n", longest, StoredNumberBiggerMaxline);
	else if (NumberLessMaxline > 0)
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */
int getlinee(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
