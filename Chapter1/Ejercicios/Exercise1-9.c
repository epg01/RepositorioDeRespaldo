/**
 *           Ejercicio 1-9 del libro Pogramming C
 *           Write a program to copy its input to its output, replacing each string of one or
 *           more blanks by a single blank.
 */

#include <stdio.h>   // Le decimos al compilador que incluya la libreria stdio.h pero no la necesitamos.
                     // Solo lo necesitamos si vamos a utilizar la funcion printf.
void versionDos(void); // Prototipo.
void versionTres(void);

int main(void)      // Se definio una funcion main que no recibe argumentos pero retorna un tipo entero
{
	int c;      // Variable que guardara el siguiente caracter de entrada (ira al futuro)
	int p;      // Variable que almacenara tambien un caracter (se quedara en el pasado)

	while((c = getchar()) != EOF) /* En esta evaluacion primero almecenamos el valor que nos retorne getchar
					 en la variable c, luego while verifica el valos de falcedad o verdad de la condicion */
	{
		if((c == ' ') && (p == ' '))  /* Preguntamos si hay espacios de sobra, ya que solo necesitamos 
					     imprimir un solo espacio */
			continue;         /* Esta expresion continue hace lo siguiente: cuando la condicion 
					     se cumpla el continue hara que se retorne al cilo while
					     es decir, c toma el siguiente caracter y se vuelve a evaluar la condicion
					     y con esto hemos resolvivo nuestro problema. */
		p = c;                    // En esta expresion de asignamiento c le pasa una copia del contenido a p
		putchar(c);               // Imprime los caracteres de entrada a la salida en este caso la pantalla.
	}
	printf("Se va a comenzar a ejecutar la funcion numero dos\n");
	versionDos();
	printf("Se va a comenzar a ejecutar la funcion numero tres\n");
	versionTres();
	return (0);  // Salida exitosa.
}

// Supongamos que no sabemos nada sobre continue. Aqui la cuestion es que utilizamos dos while, un codigo no tan eficiente.
void versionDos(void)
{
	int c;

	while((c = getchar()) != EOF)
	{
		if (c == ' '){
			while((c = getchar()) == ' ')
				;
			putchar(' ');
		}
		putchar(c);
 	}
}
// Que tal si intentamos hacer el codigo con un solo ciclo, veamos como se hace.

#define NULO 0  // Definimos una constante simbolica que solo lo puede utilizar la funcion versionTres

void versionTres(void)  // Se definio una funcion versionTres (nota: las funciones son variables externas)
{
	int c, temp;   // Funcionan casi igual como en el primer ejercicio.

	while((c = getchar()) != EOF)
	{
		if (c == ' ')   // C al encontrar el primer espacio en blanco lo guardara en una variable temporal (sera el pasado)
			temp = c;   // Al pasar por esta sentencia, se sale del if y vuelve a repetir el ciclo
		else if(c != ' ' && temp == ' '){   /* cuando la variable c encuentra un caracter que no es espacio
						       entonces es aqui donde imprime un espacio, el espacio que necesitamos */
			putchar(' ');               // Es en esta sentencia conde hacemos la reduccion de espacios en uno solo
			putchar(c);                 /* Tenemos que imprimir el contenido de C, ya que si no hacemos esto, nos tragariamos
						       simpre la primera palabra despues de los espacios */
			temp = NULO;                /* Cambiamos el valor de temp, ya que si no hacemos esto en la siguiente repeticion del ciclo
						       volvere a ejercutarse este else if, y no queremos eso. */
		}
		else
			putchar(c);               // Imprimimos el resto de caracteres que no son espacios.
	}
}
