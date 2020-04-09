/**
 *                Ejercicios del libro programming C
 *                Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each
 *                               backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
 *                               unambiguous way
 */

#include <stdio.h>  // Aunque no necesitamos esta libreria para poder utulizar putchar o getchar, la necesitamos para utilizar la constante simbolica EOF

int main(void)    // Se definio una funcion main, en donde retorna valores tipo int y no recibe argumentos, ya que el parametro es void
{
	int c;    // Se declaro una variable de tipo int, es decir guarda valores enteros.

	while((c = getchar()) != EOF)
	{
		if (c == '\t'){
			putchar('\\');
			putchar('t');
		}
		else if(c == '\\'){
			putchar('\\');
			putchar('\\');
		}
		else if (c == '\b'){
			putchar('\\');
			putchar('b');
		}
		else
			putchar(c);
	}
	return (0);  // Retorno exitoso. 
}
