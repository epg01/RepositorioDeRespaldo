/**
 *     ***********************************************************************************************************
 *     * Programming in C.                                                                                       *
 *     *      Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the  *
 *     *      length of arbitrary long input lines, and as much as possible of the text.                         *
 *     *                                                                                                         *
 *     * Ejercicio Resuelto, solo modificando el Main un poco, tambien renombramos la variables max utilizamos   *
 *     * Por el ejercicio original al nombre NumberLessMaxile aunque no es el mejor nombre, pero vamos           *
 *     * En aprendizaje para un codigo mas limpio.                                                               *
 *     *                                                                                                         *
 *     ***********************************************************************************************************
 */

#include <stdio.h>

#define MAXLINE 5                           /* maximum input line length */

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

		if (len > NumberLessMaxline) {
			NumberLessMaxline = len;
			copy(longest, line);
		}
/* Algo muy sutil es que esta condicion tiene que despues de la condicion if (len > NumberLessMaxline) */
/* Cuando getchar encuentra el salto de linea, inicializamos la variable AccountatNumber... para su proximo conteo y guardamos el numero mas grande de AccountantNumber...
   Tambien inicializamos la variables NumberLessMaxline ¿saben por que?  */

                if ((AccountantNumberBiggerMaxline > StoredNumberBiggerMaxline) && (line[len - 1] == '\n'))
                        StoredNumberBiggerMaxline = AccountantNumberBiggerMaxline, AccountantNumberBiggerMaxline = NumberLessMaxline = 0;
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
