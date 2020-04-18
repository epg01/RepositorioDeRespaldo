/**
 *       ************************************************************************************************
 *       *   Exercise 16 of the programming in C (k&D).                                                 *
 *       *                                                                                              *
 *       *       Revise the main routine of the longest-line program so it will correctly print the     *
 *       *       length of arbitrary long input lines, and as much as possible of the text.             *
 *       *                                                                                              *
 *       ************************************************************************************************
 */

// Se include la librería stdio.h para poder utilizar la contante simbólica EOF y la funcion
// printf() -> con esta funcion imprimimos texto

#include <stdio.h>

// Se definen una contante simbólica que se utiliza a lo largo del programa.

#define MAXLINE 1000            // Número máximo de caracteres.

// Se declaran dos funciones importantes, getlinee y copy.
// Comúnmente llamdas funciones prototipo.
/* Se dice que se declaran éstas funciones por que se les ésta asignando la propiedad o tipo de naturaleza a las funciones
   es decir que tipo de argumentos recibirá dichas funciones y que tipo de dato retornará. */
// Nota: Aun no hemos definidos las funciones.

int getlinee(char S[], int MaxLine);       /* Se le dice al compilador que getline recibe dos argumentos el primero tipo char y el segunto tipo int y
					      retorna un int.  */
void copy(char To[], char From []);        // Declaramos una funcion llamada copy, que recibe dos argumentos tipo char y no retorna ningun valor.

int main(void)   // Se define una declara y se define una funcion llamda main.
{
	// Se declaran 4 varaibles tipo int y se definen dos (los vectores).

	int LenGetline;                // Guardará el número de caracteres almancenado en el vector StoredLine.
	int MaxLength;                 // Guardará el maximo número de caracteres que se almacene en StoredLine, es decir el máximo longitud de una línea vista hasta ahora
	char StoredLine[MAXLINE];       // Almacenará los caracteres proporcionados por la función getline.
	char StoredLongesht[MAXLINE];   // Almacenará la línea mas larga vista por el momento.

	// Inicializamos la variables MaxLength en cero ya que ésta al inicio no aun no se ha escrito ninguna palabra por el momento.

	MaxLength = 0;
	while((LenGetline = getlinee(StoredLine, MAXLINE)) > 0)
		if (LenGetline > MaxLength){
			MaxLength = LenGetline;
			copy(StoredLongesht, StoredLine);    // En realidad no se esta psando una copia, ni los valores de StoredLine, lo que se pasa 
                                                             // realmente a la función es un apuntador a esos vectores, se vera en el capítulo 5
		}
	// Ésta condicion es fundamental con éste verificamos por lo menos que un usuario escribío un caracteres, ya sea que fuese un salto de linea.

	if (MaxLength > 0)
		printf("%s", StoredLongesht);

// Nota: return es simplemente una sentencia, no una funcion aunque parezce ya que podemos escribir return 0; he igualmente va a complar
	return(0);
}

// Ésta función almacena caracteres al array StoredLine
int getlinee(char s[], int lim)       // Se difinio la función getline, se le almacenamos contendio a la memoria.
{
	int c;        // Guardará el siguiente caracter retornado por gatchar.
	int i;        // Con esta variable tipo int recorrerá el array

	for(i = 0;(i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); i++)
		s[i] = c;                                                             // En esta sentencia llenamos el array, con el caracter almacenado en c.

	// Esta sentencia es importante, ya que analiza si c es un salto de linea para poder ingresarlo en el array, ya que el for no lo hace-
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';            // Cuarquier sting, tiene que terner un terminador y el terminador de un string es el caracter '\0'.
	return(i);              // Retorna la cantidad de caracteres ingresados al array, incluido el termandor.
}

// Ésta funcion copia el contenido del array StoredLine  al array StoredLongesht
void copy(char to[], char from[])      // Se definió una funcion llamda copy.
{
// Nota los parámetros de la funcicón aunque esta escrito como un array, en realdiad es un puntero o apuntador y almacenan la primera celda del array
	while(*to++ = *from++)        // Ésta condición copia todo el contenido incluyendo el terminador a lo que apunta el punter to, que en este caso es 
		;                     // El vector StoredLongesht. el cual para poder imprimirlo con el formato %s en la función printf (que es fundamental)
                                      // INCLUIT EL TERMNADOR.
}
