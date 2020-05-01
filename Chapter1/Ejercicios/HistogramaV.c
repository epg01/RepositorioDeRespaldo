/**
 *     *****************************************************************************************************
 *     *          Segunda parte del ejercicio 13 hacer un histograma horizontal, se hizo con un solo for   *
 *     *          ingresamos el codigo que hicimos para contar palabras.                                   *
 *     *          Luego hicismo dos funciones, una que nos haya la mayor longitud de una palabra, que sera *
 *     *          utilizada en la ultima funcion.                                                          *
 *     *          la ultima funcion nos imprime el histograma horizontal                                   *
 *     *****************************************************************************************************
 */

#include <stdio.h>
// Se definieron ciertas contantes simbolicas.

#define ALLOCSIZE 1000             // Esta sera el tamaño del vector que almacenara en cada celda la longitud de una palabra
#define VALUEDEFAULT '\0'          // Esta sera para utilizar de manera correcta el macro
#define DEFAULT -2                /* Para guardar esos dos valores por defecto en la penultima y ultima posicion de array.
				     Este se hace para poder utilizar un solo for en vez de dos. */

int storedC[ALLOCSIZE];            // Se asigno el tamaño al array.

//Se crearon dos macros,  no explicare su funcion ya que se explico en ejercicio anteriores, revisar ejercios anteriores

#define IAMAWORD(x) (((x) != ('\n')) && ((x) != ('\t')) && ((x) != (' ')) && ((x) != ('\0')))
#define NOTWORD(y) (((y) == ('\n')) || ((y) == (' ')) || ((y) == ('\t')))

// Agregamos los prototipos de las funciones a utilizar

void printHV(int *s, int M);
int searchM(int s[]);

int main(void)
{
	int c;        // Guardara el valor entregado por getchar
	int temp;     // guardara el valor anterior a getchar
	int count;    // Esta varable almacenara las longitudes de las palabas
	int i;        // Con este variale nos moveremos atravez del array
	int M;        // Guardara el mayor numero retornado por la funcion searchM

	// Inicializmo las variables.

	i = 0, count = 0, temp = VALUEDEFAULT;

	// Aqui sucede toda la magia de contar y asignar a cada celda del array la longitud de cada palabra
	// Hay que tener en cuanta que ignorara espacios tabuladores y saltos de linea :D.

	while((c = getchar()) != EOF)
	{
		if (IAMAWORD(temp) && NOTWORD(c))
			storedC[i++] = count, count = 0;
		else if(IAMAWORD(c))
			count++;
		temp = c;
	}
	// Esto es importante por que aqui en esta sentencia utilizando el operador coma asignamos la penultima y ultima posicion del array los valores por defecto, para poder REPITO utilizar un solo for en vez de dos.

	storedC[i++] = DEFAULT, storedC[i] = DEFAULT;
	M = searchM(storedC);    // Llamamos a la funcion searchM que retorna el longitud mas grande del array
	printHV(storedC, M);     // Luego de retornar la longitud de la palabra mas larga, pasamos a impimirlo
	return(0);               // Salida exitosa.
}
// Aqui empueza la magia de imprimir el histograma horizontal, con esta funcion retornamos la longitud mas larga.
int searchM(int s[])
{
	// Declaramos pero no definimos estas variables.
	int temp1;
	int temp2;
	int i,j;

	// Inicializmos los valores y procedemos con este for hallar la longitud mas larga.
	for(i = 0, j = 1, temp2 = 0; s[i]; j += 1, i = j + 1)
	{
		if (s[i] > s[j])
			temp1 = s[i];
		else
			temp1 = s[j];
		if (temp2 < temp1)
			temp2 = temp1;
	}
	// Se retorna la longitud mas larga.
	return(temp2);
}
// Aqui sucede la magia de imprimir el histograma de manera horizontal

void printHV(int *s, int M)
{
	// Declaramos las variables a utulizar.
	int i;           // Este se utilizo solo por estetica, pudimos haber copiado simplemente s[0] en vez de s[i]
	int *temp = s;    // Apuntamos  a la primera celda del array, esto bien se pude hacer echo sin punteros.
	int *temp2;      // este puntero es importante por que sete apuntara a la condicion inicial del for.

	// AQUI SUCEDE LA MAGIA DE IMPRIMIR.
	// Nota es dicil esplicar estas condiciones por si solas, necesitaria una pizarra para explicar bien las condiciones de frontera.
	for(i = 0, temp2 = &M ; *temp2; )  // Como podemos observar la condicion principal es el numero mas grande
	{
		if(s[i] == *temp2)
			putchar('*'), s++;
		if(!(s[i] - *temp2))
			putchar('*'), s++;
		if (s[i] >= *temp2 && (s[i] != DEFAULT))
			putchar('*'), s++;
		else if (s[i] && (s[i] != DEFAULT))
			putchar('_'), s++;
		if((s[i] == DEFAULT) || (s[i] == DEFAULT))
			putchar('\n'), s = temp, *temp2 -= 1, i = 0;
	}
}
