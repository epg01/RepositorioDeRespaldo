/**
 *     *********************************************************************************************************************************
 *     *                Problemas resueltos del libro programming in C.                                                                *
 *     *                Exercise 1-12. Write a program that prints its input one word per line.                                        *
 *     *                                                                                                                               *
 *     *                Haremos esten ejercicios con tres formas posibles, una guardando todo en un vector, luego utilizando puntero   *
 *     *                (esto es para imprimirlo con la funcion printf) luego utilizaremos la funcion putchar como                     *
 *     *                con el metodo que hicimos en la Section 1.5.4 (con macros) y tambien lo haremos con la solucion que nos dejo   *
 *     *                El libro.                                                                                                      *
 *     *                                                                                                                               *
 *     *********************************************************************************************************************************
 */

//IMPORTANTE: UN ERROR QUE AUN NO HE PODIDO SOLUCIONAR A SIDO EL DE ESCRIBIR ALGO Y LUEGO ESCRIBIR EOF, CLARAMENTE HAY UN ERROR AHI

#include <stdio.h>    // le decimos al compilar que incluya  la libreria stdio.h para poder utilizar el valor EOF y la funcion printf

// Aqui iran los prototipos de las funciones
void MetodoConMacros(void);

int main(void)
{
        printf("Forma 2, el ejercicio que hice con macros\n");
	MetodoConMacros();
        printf("Forma 1, funcion Metodologia del libro\n");
}
// Utilice estas dos macros, para no ecribir todo estas condiciones en la sentencia del if.

#define IAMAWORD(x) (((x) != (' ')) && ((x) != ('\t')) && ((x) != ('\n')) && ((x) != ('\0')))
#define ESTOYFUERADEUNAPALABRA(y) (((y) == (' ')) || ((y) == ('\t')) || ((y) == ('\n')))

#define VALORPORDEFECTO  '\0'   /* Este valor lo tendra al iniciar el programa, para solucionar cierto errores
				   El cual consistia en: al escribir por ejemplo "    hola" daba un salto de linea, por el espacio en blanco
				   Con este valor por defecto solucione dicho error.*/
void MetodoConMacros(void)     // Se definio una funcion que no retorna ni recina nada.
{
	int c;                 // Esta variable tipo entera, sera el siguiente caracter de entrada (estara en el presente)
	int temp;              // Esta variable tipo entera, estara un paso atras de c, para evaluar si esta o no en una palabra.

 	temp = VALORPORDEFECTO;             // Inicializamos a la variable temp por defecto con la contante simbolica para solucionar el error antes dicho.
        while ((c = getchar()) != EOF)
	{
		if(IAMAWORD(temp) && ESTOYFUERADEUNAPALABRA(c))    /* Aqui pasa toda la magia, y no se imprimira una nueva linea hasta que temp este en una palabra
								      y c no sea parte de una palabra. */
			putchar('\n');
		else if (IAMAWORD(c))                              /* Con esta else if, se soluciono el problema de saltos de linea "agregados desde el teclado" */
			putchar(c);
		temp = c;                                          /* Temp estara un paso atras de C */
	}
	return ;
}

#define IN  0
#define OUT 1

void MetodoDelLibro(void)
{
	int c;
	int state;

	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if (ESTOYFUERADEUNAPALABRA(c))
		{
			state = OUT;
		}
		else if(state == OUT)
		{
			state = IN;

		}
	}
}
