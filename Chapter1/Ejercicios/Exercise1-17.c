/**
 *   ***********************************************************************************************************************
 *   * Programmingin C K&D.                                                                                                *
 *   *                                                                                                                     *
 *   *       Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.                   *
 *   *                                                                                                                     *
 *   *       En este ejercicio se intentará hacer un "código limpio" " aplicando algunos métodos que se dan en el libro    *
 *   *       Code Simplicity - Max Kanat-Alexander.                                                                        *
 *   *       Se  tratará de aplicar los conceptos de los capítulos 1,2 y 3 -> espero hacerlo bien.                         *
 *   *                                                                                                                     *
 *   ***********************************************************************************************************************
 *
 */

/* Inlcuimos la librería stdio.h -> Aun no entiendo bien las funcionalidades de esta librería 
   pero sé que esta librería define la entrada y salida de funciones, tipos y macros. (Tengo que profundizar más en esto.)*/

#include <stdio.h>

/* Sé define dos contante simbolica, ya que es una mala practica enterrar número mágicos*/

#define NUMBERMAXIMUMCHARACTERES   1000
#define CHARACTERPRINT             5

/* Sé declaran una funcion, ya que especifica el tipo de argumentos que le llegan y el tipo de dato que retornará la función 
   nota: aun no hemos definido la funcion, como se declaran las funciones es optativo en los parámetros asignar un nombre de variable al tipo de dato, pero esto
          es una mala practica ya que da poca documentación o informacion al programa. */

int getlinee(char StoredCharacter[], int SizeArray);    /* En donde como hemos dicho pudimos hacer escrito int getline(char [], int) ya que no estamos
							  definiendo a la función si no declarandola, inclusive tambien se pude hacer escrito
						          getline(char [], int) si no se coloca el tipo de dato el compilador asumirá que será de tipo int*/

// Nota: Las funciones que se declaran, comunmente arriva de la funcion principal (main), se denomina comunmnete función prototipo (function prototype)

int main (void) // Sé definio una función y estoy seguro que también se declara.
{
	int SizeLineCurrent;
	char StoredCharacter[NUMBERMAXIMUMCHARACTERES];

	printf("No tuvimos en cuenta el desbordamiento, ejercicio hecho en el problema Exercise1-16\n");
	SizeLineCurrent = 0;
	while ((SizeLineCurrent = getlinee(StoredCharacter, NUMBERMAXIMUMCHARACTERES)) > 0)
		if (SizeLineCurrent > CHARACTERPRINT)
			printf("Línea con un numero mayor de 80 caracteres: %s", StoredCharacter);
	return(0);
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
