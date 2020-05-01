/**
 *        Ejercicios del libro programming C
 *        Write a program to print the value of EOF.
 *        Existen varias formas de resolver este ejercicio
 *        Empezaremos con la forma mas directa y otras no tan directas.
 */

#include <stdio.h>

void FormaNTD(void); // Prototipo de FormanNTD

int main(void)
{
	printf("El valor de EOF: %d\n", EOF);  // Como la funcion de gatchar esta en la libreria estandar de C OEF, tambien y es por eso que nos permitimos hacer esto.
}

// Otra forma no tan directa.

void FormaNTD(void)
{
	int c;

	printf(((c = getchar()) == EOF) ? "El valor de EOF es: %d\n" : "", c);  // Obtenemos el valor de EOF
}
