/**
 *    *************************************************************************************************************************************************
 *    * Ejercicio del libro programmin in C de R&K                                                                                                    *
 *    *  Exercise 1-14. Write a program to print a histogram of the frequencies of different characters                                               *
 *    *  in its input.                                                                                                                                *
 *    *Esta solucion sera diferente a las demas, ya que tratamos a main como una funcion que llama a otra funcion y guarda sus retornos para          *
 *    *Utilizarlos en otras funcion, utilizaremos las propiedades de declarar variables Externas, no de definiras, ya que                             *
 *    *Son dos pinches conceptos distintos                                                                                                            *
 *    *                                                                                                                                               *
 *    *                   Estructura de la funcion main                                                                                               *
 *    *                        While (caracter no sea igual al indicador de final de linea)                                                           *
 *    *                                      Se pasa el caracter a una funcion, en donde esta lo almacenara en un array.                              *
 *    *                        Luego se llama a una funcion para encontrar el valor mas grande que esta en el array.                                  *
 *    *                        Imprimimos el histograma llamando a dicha funcion que nos haga este trabajo                                            *
 *    *************************************************************************************************************************************************
 */

// NOTA: INTENTAMOS CONTAR PALABRAS DE UNA MANERA MAS AVANZADA, ESTOS CONOCIMIENTOS ESTAM EN EL CAPITULO 4.
// Y en esta ocacion vamos a utilizar el poder de las variables externar, es decir no vamos a pasarle algumentos a ninguna funcion.

#include <stdio.h>

// Se define dos constante simbolica.

#define ALLOCSIZE 97     // Tamaña del vector
#define DEFAULT -2      // Esta constante aparece en la impresion del histograma vertical

// AGREGADO A ULTIMO MINUTO PARA UNA MEJOR ESTETICA

#define CharacterEspacio 32

// Se declaran tres variables externas y se definen, se consideran externas por que estan fuera de una funcion.
// ¿Por que se declaran y se definen? las variables externas son las unicas variables que son inicializadas. las demas es deicr las que estan en funciones
// no se inicilizan, por tanto pueden contener contenido basura.

int storedV[ALLOCSIZE];  // Almacenara la cantidad de caracteres que se repite y los guardara como un contador para cada carecter.
                           // Vimos una de las utilidades de los array (nota: un array no es una varaibles ¿por que?)
int M;                     // Gardara el mayor numero que se repita en el input
int c;                     // Guardara el siguiente caracter que nos retorne getchar, ¿por que escogimos int y no char?

// Se define una macro, con la intencion se saber si getchar esta o no en un espacio, tabulador o salto de linea.

#define ISPACE(x) (((x) == ('\n')) || ((x) == ('\t')) || ((x) == (' ')))

// Aqui se definen los prototipos a utilizar.

void printHV(void);
int searchM(void);
void AlmacenarV();

// Funcion agragada a ultimo minuto, para darle un mejor estilo, esta funcion dibuja la base :D.

void Base(void);

// La funcion main solo servira para llamar y retornar funcion
int main(void)
{
        while((c = getchar()) != EOF)
                AlmacenarV();          // Esta funcion almacena y cuenta los caracteres que se repiten en el input
        M = searchM();               // Esta funcion busca el mayor numero.
        printHV();                   // Esta funcion imprimi el histograma vertical hecho en la segunda parte del ejercicio 13, con un pinche for hpp!
	Base();                      // Funcion echa a ultimo momento para hacer la base del histograma.
}

// Esta funcion almacenara todos los caracteres imprimibles del codigo ascii, y el array cervira de contador tambien.
void AlmacenarV()
{
	if (ISPACE(c))
		return;                // Esto es importante ya que con este no contamos caracteres de espacio en blanco ni tabuladores ni salto de linea
	else if(c >= ' ' && c <= '~')
		storedV[c - ' '] += 1;   // Donde la celda 0 se refiera a espacio, la celda 1 al signo de admiracion y asi sucesivamente, cada celda
	                                 // Se refiere  a un caracter imprimible del codigo ascii y cada vez que se almacena se suma 1 a la celda correspondiente.
	                                // Es decir si escribimo cinco veces el caracter (!) la celda 1 trendra el valor de 5
}

// Esta funcion sirve para hallar el mayor numero que se encuentre almacenado en el array, este numero se utilizara en la condicion para imprimir.
int searchM(void)
{
	int temp1;
	int i;

	storedV[95] = DEFAULT, storedV[96] = DEFAULT;
	for (i = 1, temp1 = 0; storedV[i] != DEFAULT;  ++i)
		if (storedV[i] > temp1)
			temp1 = storedV[i];
	return (temp1);
}

// Funcion que imprime el histograma vertical
void printHV(void)
{
	int *puntero;                 // Puntero que apuntara al vector sotredV
	int *ValueM;                // Puntero que apuntara a la variable M
	int *retorno;
	puntero = storedV, retorno = storedV;
	ValueM = &M;

	// Aunque se puede utulizar el for, este while es mucho mas natural, por que nos da la manera de saber la condicion mas importante es valor de M
	// A diferencia del for que colocamos en el ejercicio anterior, es un for no natural, por asi decirlo.
	while (*ValueM)
	{
		if (*puntero == *ValueM)
			putchar('*'), puntero++;
		if (!(*puntero - *ValueM) && (*puntero != DEFAULT))
			putchar('*'), puntero++;
		if ((*puntero > *ValueM) && (*puntero != DEFAULT))
			putchar('*'), puntero++;
		else if (*puntero != DEFAULT)
			putchar('_'), puntero++;
		if ((*puntero == DEFAULT) || (*puntero == DEFAULT))
			putchar('\n'), puntero = retorno, *ValueM -= 1;
	}
}

// Funcion para hacer el histograma con una mejor estetica

void Base(void)
{
	int i;            // Esta variable i imprimire todos los caractedes visibles del codigo ascii.
	int count;        // Con essta variable que es un "contador" imprimira la el caracter (_) para simular una base.

	count = i = CharacterEspacio;
	while(i < 127)
	{
		if (count == 127)                       // Este if es la condicion para imprimir el caracter (_)
			putchar('\n'), count++;
		if (count < 127)                        // Esta funcion nos imprime los caracteres imprimibles del coddigo acsii.
			putchar('_'), count++;
		else
			putchar(i), i++;
	}
	putchar('\n');

}
