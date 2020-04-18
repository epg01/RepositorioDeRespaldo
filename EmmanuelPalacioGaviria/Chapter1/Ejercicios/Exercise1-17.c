/**
 *           ***********************************************************************************
 *           *  Problema 1-17                                                                  *
 *           *                                                                                 *
 *           *     Write a program to print all input lines that are longer than 80 character  *
 *           *                                                                                 *
 *           *     Este ejercicio era muy facil, ya que la condicíon que pedian era trivial,   *
 *           *     No se hizo uno de la función copy y se eliminarón ciertas condicíones       *
 *           *     esenciales del programa original.                                           *
 *           ***********************************************************************************
 */

#include <stdio.h>

#define MAXLINE    1000     /* Máxima linia de entrada */
#define CONDICIONG 80       /* Condicíon del ejercicio 1-17. */

// Se declaró la función fundamental para agregar los caracteres al array con un tamaña igual a MAXLINE

int getlinee(char line[], int maxline);    // Esto quiere decir que getlinee recibe dos argumentos uno tipo char y el otro tipo maxline y retorna un tipo int, mas no se
                                           // a definido la funcion ya que se hace en la linea 36.

// Print the longest input line
int main(void)        // se definie una funcion main que no recibe argumentos pero retorna un tipo int
{
	int Len;                      // Current line length
	char Line[MAXLINE];           // Current input line

	while ((Len = getlinee(Line, MAXLINE)) > 0)
		if (Len > CONDICIONG)               // Condicíon del ejercicio 1-17.
			printf("%s", Line);         // Función que me imprime una linea con mas de 80 caracteres.
	return(0);                                  // Salida exitosa
}

/* getline: read a line into s; return longth */
int getlinee(char s[],int lim)          // Se define una función getlinee.
{
        int c;          // Guarda el siguiente caracter que retorna la funcion getlinee
	int i;         // Con esta variable tipo int recorremos el array de tamaño MAXLINE

        for (i = 0; (i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		s[i] = c;
        if (c == '\n')
                s[i] = c, i++;       // Se utilizo el operador coma, descrito en el capitulo 2
        s[i] = '\0';                 // Esto es fundamental ya que sin este valor no imprimiríamos la cadena de caracteres

// NOTA: UNA CADENA DE CARACTERES SIEMPRE TIENE UN TERMINADOR QUE EN ESTE CASO ES EL TERMINADOR '\0'
        return i;
}
