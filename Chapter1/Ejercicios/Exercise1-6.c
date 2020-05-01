/**
 *      Ejercicio del libro Programming C.
 *      Verify that the expression (getchar( ) != EOF) is 0 or 1
 *      Varias formas de resolver el ejercicio y conceptos nuevos.
 */

#include <stdio.h> // No necesitamos esta libreria para utilizar getchar y putchar ya que la libreria estandar lo proporciona

void Veracidad(void);

int main(void)  // Se definio la funcion main, en donde no recibe argumentos por tanto su parametro es void y retonar un entero
{
	int c;  // Declaramos a la varialbe como tipo entero.

	c = (getchar() != EOF);  /* Definimos a la variable c como 0 o 1 dependiendo si getchar es o no es fin de archivo,/
				    un operador logico evalua 1 o 0 dependiendo el valor de verdad o falcedad de la expresion */
	if(c == 1)
		putchar(c);   /* Lo interesante de esto es putchar cuando c es 1 o 0 putchar imprimira un caracer que no es imprimible
				 esto me hace pensar que el valor de veracidad de la expresion no es el valor 49 o 50 en el lenguaje de juego maquina,
				 que ene ste caso es el codigo ansii */
	else
		putchar(c);
	putchar('\n');
	return (0);
}

// Solucion al problema antes dicho es utilizar la funcion printf, haremos el codigo mas reducido.

void Veracidad(void)
{
	int c;

	printf((c = (getchar() != EOF)) ? "%d\n" : "%d\n", c, c);  /* Esto es hermoso YA QUE el primer argumento y no parametro
								      (ya que son diferentes los conceptos) se aceptan expresiones, esto no es nada intuitivo. */
}

// Otra solucion que si es intuitiva es la siguiente.

void VeracidadForma1(void)
{
	printf("valor de veracidad de la expresion (getchar() != EOF): %d\n", getchar() != EOF);
}
