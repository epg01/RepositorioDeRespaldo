/**
 *   *********************************************************************************************
 *   * Ejercicio 1-19 programmin in C                                                            *
 *   *     Write a function reverse(s) that reverses the character string s. Use it to           *
 *   *     write a program that reverses its input a line at a time.                             *
 *   * Se modificó el programa inicial solo un poco, se eliminó la funcion copy( ) ya que no la  *
 *   * Necesitábamos, se creó una función llamada reserver( )  para invertir el array            *
 *   * Se utilizó la aritmetica trivial de punteros para resolver este ejercicio                 *
 *   * Ya que es la misma que utilizar la aritmética de vectores.                                *
 *   *                                                                                           *
 *   *********************************************************************************************
 *
 */
#include <stdio.h>

#define MAXLINE 1000

// Se crea dos variables externas, esto es para facilidad, pero se pude haber obviado.

char Reserve[MAXLINE];
char Line[MAXLINE];

// Se declararon dos funciones, que comunmente se denominan prototipo de funcion.

int getlinee(char s[], int maxline);
void reserver(char from[], char to[], int line);

int main(void)
{
        int Len;

        while (Len = getlinee(Line, MAXLINE))
	{
		if (Len){                               // Ésta condición es fundamental para poder imprimir una línea ya que verifica la existencia de ésta.
			reserver(Line, Reserve, Len);   // Se utilizó la función reserver, para invertir el orden del array Line, y lo guardamos en el arrat Reserver.
			printf("%s", Reserve);
		}
	}

        return(0);
}

// ésta función ya esta mas que discutida en ejercicios anteriores.
int getlinee(char s[], int lim)
{
	int i, c;
	for(i = 0; (i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		s[i] = c;
	if (c == '\n')
		s[i] = c;
	s[i] = '\0';
	return(i);
}

/* Se utilizó la aritmética de punteros para poder hacer éste ejercicio pero se pude haber obivido y haberlo echo con array, pero no me gusta xD*/
void reserver(char from[], char to[], int Lim)
{
	char *p;             // Se declaro un apuntador a char.
	p = from + (Lim - 1);        // Luego este puntero apuntara al character que no sea ni salto de linea ni valor nulo
                                     // Aquí estamos aceptando que un usuario halla copiado todo perfecto sin un EOF antes que un salto de línea.
	while(--Lim >= 0)            // Éste while copiará todo el array desde el ultimo caracter visible hasta el primero.
		*to++ = *p, p--;
// En estas dos líneas agregamos los correspondientes salo de línea y el terminador nulo que tiene todo string.
        *to++ = '\n';
	*to = '\0';
}
