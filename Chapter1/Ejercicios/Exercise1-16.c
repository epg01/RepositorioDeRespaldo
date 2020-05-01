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

// Se definen dos contantes simbólicas que se utiliza a lo largo del programa.

#define MAXLINE 1000                  // Número máximo de caracteres.
#define NUMBERMAXLINE 2               // Este numero de relacion con el numero de caracteres de reserva que podemos crear.

// Se declaran dos funciones importantes, getlinee y copy.
// Comúnmente llamdas funciones prototipo.
/* Se dice que se declaran éstas funciones por que se les ésta asignando la propiedad o tipo de naturaleza a las funciones
   es decir que tipo de argumentos recibirá dichas funciones y que tipo de dato retornará. */
// Nota: Aun no hemos definidos las funciones.

int getlinee(char S[],char T[], int MaxLine);     /* Se le dice al compilador que getline recibe dos argumentos el primero tipo char y el segunto tipo int y
						     retorna un int.  */
void copy(char To[], char From [], int N);        // Declaramos una funcion llamada copy, que recibe dos argumentos tipo char y no retorna ningun valor.

// Se declaran dos variables externar de tipo int, recordemos que estas ya estan previamente inicializadas.

int count;
int count1;

int main(void)
{
// Se declaran 4 varaibles tipo int y se definen dos (los vectores).

	int LenGetline;               // Guardará el número de caracteres almancenado en el vector StoredLine.
	int MaxLength;                // Guardará el maximo número de caracteres que se almacene en StoredLine, es decir el máximo longitud de una línea vista hasta ahora
	char StoredLine[MAXLINE + 1];   // Almacenará los caracteres proporcionados por la función getline.
	char StoredLongesht[MAXLINE];  // Almacenará la línea mas larga vista por el momento.
	char StoredReserver[MAXLINE];  // Éste vector almacenará los caracteres que se rebacen en el segundo vector.
	char ReserverLongesht[MAXLINE];   // Almacenara la linea ma larga vista por el momento por el segundo vector.

	// Inicializamos la variables MaxLength en cero ya que ésta al inicio no aun no se ha escrito ninguna palabra por el momento.

	MaxLength = 0;
	while((LenGetline = getlinee(StoredLine, StoredReserver,(NUMBERMAXLINE)*MAXLINE)) > 0)
	{
		if (LenGetline > MaxLength){
			MaxLength = LenGetline;
			copy(StoredLongesht, StoredLine, count);  // En realidad no se esta psando una copia, ni los valores de StoredLine, lo que se pasa 
			                                          // realmente a la función es un apuntador a esos vectores, se vera en el capítulo 5
			if (*StoredReserver)                      // Si existe un elemento en SotredReserver entonces hará lo mismo que hace el copy anterior
				copy(ReserverLongesht, StoredReserver, count1);
		}
	}

// Ésta condicion es fundamental con éste verificamos por lo menos que un usuario escribío un caracteres, ya sea que fuese un salto de linea.

	if (MaxLength > 0){
		printf("Maxima linea escrita:\n");
		printf("%s", StoredLongesht);
	}
	if (MaxLength >= MAXLINE)
		printf("%s", ReserverLongesht);
	if (MaxLength >= MAXLINE){
		printf("Maxima longitud que hubiera imprimido:\n%s\n", StoredLongesht);
		printf("Maxima longitud de la cadena que se escribio: %d\n", MaxLength);
	}

// Nota: return es simplemente una sentencia, no una funcion aunque parezce ya que podemos escribir return 0; he igualmente va a complar

	return(0);
}

// Ésta función almacena caracteres al array StoredLine
int getlinee(char StoredFase1[], char StoredFase2[],int lim)   // Se difinio la función getline, se le almacenamos contendio a la memoria.
{
	int c;          // Guardará el siguiente caracter retornado por gatchar.
	int i;           // Con esta variable tipo int recorrerá el array

	for(i = 0, count = 0, count1 = 0;(i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); i++)
	{
		if(count < (lim/NUMBERMAXLINE))
			StoredFase1[count++] = c;
		else
			StoredFase2[count1] = c, count1++;
	}

	if(count)
		StoredFase1[count]  ='\0';
	if ((c == '\n') && ((count) < ((lim/NUMBERMAXLINE) - 1)))
		StoredFase1[count++] = c, StoredFase1[count] = '\0';
	else if ((c == '\n') && ((i + count) >= (lim/NUMBERMAXLINE)))
		StoredFase2[count1++] = c, StoredFase2[count1] = '\0';
	if ((c != '\n') && (count < ((lim/NUMBERMAXLINE) - 1)))
		StoredFase1[count] = '\0';
	else if ((c != '\n') &&  ((i + count) >= (lim/NUMBERMAXLINE)))
		StoredFase2[count1] = '\0';
	return (count1 + count);
}

// Ésta funcion copia el contenido del array StoredLine  al array StoredLongesht
void copy(char to[], char from[], int count)    // Se definió una funcion llamda copy.
{
	int inicio = 0;
	while((inicio <= count) && (to[inicio] = from[inicio]))   // Esta condicion incluira el terminador nulo para poder que se imprima en el priintf
		inicio++;
}
