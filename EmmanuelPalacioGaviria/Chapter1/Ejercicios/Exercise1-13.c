/**
 *      *********************************************************************************************
 *      *           Exercise 1-13. Write a program to print a histogram of the lengths of words     *
 *      *           in its input. It is easy to draw the histogram with the bars horizontal;        *
 *      *           a vertical orientation is more challenging.                                     *
 *      *                                                                                           *
 *      *           Estructura del programa:                                                        *
 *      *           Cojimos la estructura del programa contar palabras -> la solucion del libro     *
 *      *           Se tuvo que modificar (la modificacion fue por parte de mi persona)             *
 *      *           y lo unico que agregamos fue un contador y una funcion que nos imprimera el     *
 *      *           histograma.                                                                     *
 *      *                                                                                           *
 *      *********************************************************************************************
 */

#include <stdio.h>   // Le decimos al compilador que incluya la libreria stdio.h

#define OUT 0        // Indicador para decir que getchar esta fuera de una palabra
#define IN  1        // Indicador para decir que getchar esta dentro de una palabra

// Definimos una macro, para desasernos de los espacios, saltos de linea y tabuladores, ya que solo nos interese las palabras

#define ISPACE(x) (((x) == (' ')) || ((x) == ('\n')) || ((x) == ('\t')))

// Esta el prototipo de la funcion esta funcion imprimir, nos imprimira el diagrama

void imprimirH(int *count);

int main(void)  // Se definio una funcion llamada main, esta funcion es especial ya que con esta se inicia nuestro programa
{
	int c;   // Almacenaremos en esta variable tipo entero el siguiente caracter entregado por getchar.
	int state;   // Esta variable tipo entero, sera nuestro verificadot si getchar estar o no en una palabra.
	int count;  // Sera nuestro contador de caracteres de una palabra.

	/* Aqui inicializamos las variables. ADVERTENCIA: tenemos que distribuir inteligentemente el contador
	   Para que cuenta solo los caracteres que estan dentro de una  palabra */

	count = 0;
	state = OUT;
	while((c = getchar()) != EOF)
	{
		if(ISPACE(c))   /* Verificamos si c es un espacio, con este if nos aseguramos de ignorar los
				   Espacios en blanco execivos. */
		{
     			if(state == IN)
				imprimirH(&count);  /* Aqui llamos a nuestra funcion, y el argumento por valor
						      Sera un apuntador a esa variable count, ya que le estamos
						      Pasando una direccion y no el valor almecenado. */
			state = OUT;               /* Es un indicador que no estamos en una palabra */
		}
		else if (state == OUT)
		{
			state = IN;
			count++;      /*Este count aqui es fundamenta ya que sin este nos tragariamos La primera palabra. */
		}
		else
			count++;      /* Este else es necesaria ya que con este contamos el resto de las Palabras*/
     	}
}
/* Aqui comienza nuestra funcion imprimirH que no retorna nada y su unico parametro es un punetero ya que estamos
   Manejando direcciones de memoria y no copias. */

void imprimirH(int *count)
{
	/* Esta condicion if else en necesaria para imprimir correctamente la base y que este bien espaciada */

	if (*count >= 0 && *count <= 9)
		printf("%d  |", *count);
	else
		printf("%d |", *count);

	/* Este for es para imprimir de manera horizontal el histograma, es arterisco es necesaria para ingresar
	   Al valor almecanado al que apunta el puntero y este se modificara ya que repito no pasomos una copia. */

	for (; *count > 0; (*count)--)
		putchar('*');
	putchar('\n');
}
