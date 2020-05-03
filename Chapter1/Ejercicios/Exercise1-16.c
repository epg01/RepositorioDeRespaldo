/**
 *     ***********************************************************************************************************
 *     * Programming in C.                                                                                       *
 *     *      Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the  *
 *     *      length of arbitrary long input lines, and as much as possible of the text.                         *
 *     *                                                                                                         *
 *     * Ejercicio Resuelto, solo modificando el Main un poco, tambien renombramos la variables max utilizamos   *
 *     * Por el ejercicio original al nombre NumberLessMaxile aunque no es el mejor nombre, pero vamos           *
 *     * En aprendizaje para un codigo mas limpio.                                                               *
 *     *                                                                                                         *
 *     ***********************************************************************************************************
 */

/* Inlcuimos la librería stdio.h -> Aun no entiendo bien las funcionalidades de esta librería 
   pero sé que esta librería define la entrada y salida de funciones, tipos y macros. (Tengo que profundizar más en esto.)*/

#include <stdio.h>

/* Sé define una contante simbolica, ya que es una mala practica enterrar número mágicos*/

#define NUMBERMAXIMUMCHARACTERES 5

/* Sé declaran dos funciones, ya que especifica el tipo de argumentos que le llegan y el tipo de dato que retornará la función 
   nota: aun no hemos definido la funcion, como se declaran las funciones es optativo en los parámetros asignar un nombre de variable al tipo de dato, pero esto
          es una mala practica ya que da poca documentación o informacion al programa. */

int getlinee(char StoredCharacter[], int SizeArray);    /* En donde como hemos dicho pudimos hacer escrito int getline(char [], int) ya que no estamos
							  definiendo a la función si no declarandola, inclusive tambien se pude hacer escrito
						          getline(char [], int) si no se coloca el tipo de dato el compilador asumirá que será de tipo int*/
void copy(char LargestLineSeeSoFar[], char StoresLineLongest[]);
// Nota: Las funciones que se declaran, comunmente arriva de la funcion principal (main), se denomina comunmnete función prototipo (function prototype)

int main (void) // Sé definio una función y estoy seguro que también se declara.
{
	int SizeLineCurrent;
	char StoredCharacter[NUMBERMAXIMUMCHARACTERES];
	char LargestLineSoSeeFar[NUMBERMAXIMUMCHARACTERES];
	int MaximumLineSeeSoFar;
	int AccountantOverflowNUMBERMAXIMUMCHARACTERES;
	int StoredAccountant;
	char TemporaryCharacterStorage[NUMBERMAXIMUMCHARACTERES];

	StoredAccountant = AccountantOverflowNUMBERMAXIMUMCHARACTERES = MaximumLineSeeSoFar = 0;
	while ((SizeLineCurrent = getlinee(StoredCharacter, NUMBERMAXIMUMCHARACTERES)))
	{

/* Esta condición es importante, ya que verifica si hay un desbordamiento, es decir si aún hay caracteres que hacen parte de una línea y no han sido almacenamos en
   su totalidad por el vector, ya que tiene un tamaña fijo (finito). Lo importante de esta condición if-else-if, es que incluimos en el conteo el final de línea,
   ya que por definición es un carácter visible ("es decir se cuenta") ya que el carácter terminador \0 no se incluye en el conteo.*/

		if (SizeLineCurrent == (NUMBERMAXIMUMCHARACTERES - 1) && !(StoredCharacter[SizeLineCurrent - 1] == '\n'))
			AccountantOverflowNUMBERMAXIMUMCHARACTERES += SizeLineCurrent;
		else if ((StoredCharacter[SizeLineCurrent - 1] == '\n') && (AccountantOverflowNUMBERMAXIMUMCHARACTERES))
			AccountantOverflowNUMBERMAXIMUMCHARACTERES += SizeLineCurrent;

// Tiene que ser mayor igual las dos últimas variables por si no hay desbordamiento, copiar cantidad de caracteres menores a dichos desbordamientos.

		if ((SizeLineCurrent > MaximumLineSeeSoFar) && (AccountantOverflowNUMBERMAXIMUMCHARACTERES >= StoredAccountant)){
			MaximumLineSeeSoFar = SizeLineCurrent;
			copy(LargestLineSoSeeFar, StoredCharacter);
		}

// Con estos dos if solucione los problemas que tenia con la salida del programa

		if ((AccountantOverflowNUMBERMAXIMUMCHARACTERES <= SizeLineCurrent)  && (MaximumLineSeeSoFar <= SizeLineCurrent))
			copy(TemporaryCharacterStorage, StoredCharacter);

                if ((StoredAccountant > 0)  && (AccountantOverflowNUMBERMAXIMUMCHARACTERES >= StoredAccountant))
                        copy(LargestLineSoSeeFar, TemporaryCharacterStorage);

/* La condición almacena los caracteres contados hasta ahora (la máxima cantidad). */

		if ((AccountantOverflowNUMBERMAXIMUMCHARACTERES > StoredAccountant))
			StoredAccountant = AccountantOverflowNUMBERMAXIMUMCHARACTERES;

/* Cuando se llega al salto de línea, carácter nuevo línea, inicializamos las variables a sus valores iniciales para su nuevo y seguro conteo. */

		if (AccountantOverflowNUMBERMAXIMUMCHARACTERES && (!(StoredCharacter[SizeLineCurrent - 1] != '\n')))
			AccountantOverflowNUMBERMAXIMUMCHARACTERES = MaximumLineSeeSoFar = 0;
	}

/* La condición if-else verifica si hubo un desbordamiento he imprime la línea más larga que el array pudo almacenar. */

	if (StoredAccountant >= NUMBERMAXIMUMCHARACTERES)
		printf("%s\n!Advertencia hubo un desbordamiento! Longitud de la linea mas larga copiada: %d\n", LargestLineSoSeeFar, StoredAccountant);
	else if (MaximumLineSeeSoFar > 0)
		printf("%s", LargestLineSoSeeFar);
	return 0;
}

// Obtiene nueva línea

getlinee(char StoredCharacter[], int SizeArray)
{
	int i, InputCharacter;

	for (i = 0; i < (SizeArray - 1) && ((InputCharacter = getchar()) != EOF) && (InputCharacter != '\n'); i++)
		StoredCharacter[i] = InputCharacter;

	if (InputCharacter == '\n')
		StoredCharacter[i++] = InputCharacter;

	StoredCharacter[i] = '\0';

	return(i);
}

// Utilizamos el concepto de artimética de punteros -> esta aritmética contiene la parte de aritmetica de array, en por definición es una parte de la artimética de
// Punteros.

// copia la línea mas larga vista has ahoara.

void copy(char LargestLineSeeSoFar[], char StoresLineLongest[])
{
	while((*LargestLineSeeSoFar++ = *StoresLineLongest++))
		;
}
