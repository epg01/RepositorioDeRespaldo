/**
 *   *************************************************************************************************************************
 *   *  Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number                          *
 *   *                 of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.        *
 *   *                 Should n be a variable or a symbolic parameter?                                                       *
 *   *                                                                                                                       *
 *   *  Se hicieron algunos modificaciones para este ejercicio, ya qué lo que pedian era muy trivial, por tanto se opto      *
 *   *  Por algo mas general, en tonde si no escribimos ninunga letra al comienzo la tabulacion normal sería de 8 espacios   *
 *   *  De caracteres, por tanto si escribiamos primero hola (esto son 4 caracteres) luego sí ingresabamos la tecla tab      *
 *   *  Se espaciaba 4 caracteres (8 - 4) así funciona la tab de mi terminal, no se las otras, con base a esto se hizo       *
 *   *  Este ejercicio.                                                                                                      *
 *   *                                                                                                                       *
 *   *************************************************************************************************************************
 *    NOTA: SE UTILIZÓ UNA FUNCIÓN GOTO, QUE SE VERÁ EN EL CAPÍTULO 4 Y SE PUDE HABER COLOCADO RETURN.
 */

#include <stdio.h>

// Declaramos las funciones y como otros lo denominan (funciones prototipo)

unsigned char StoredCharacterOfTheArray(char StoredCharacter[]);
void PrintSpaceCharacter(unsigned char NumberOfSpaceForPrint);

#define ARRAYSIZE 9     /* Tamaño del arrray nota: por que se habrá escodigo 9 */
#define TABLENGTH   8

int main(void)
{

	char StoredCharacter[ARRAYSIZE];
	unsigned char ContantOfCharacterStored;
	unsigned char i, State, AccountantCharacter;

	State = 1;                                                     /* Ya que debe entrar, por tanto el State tiene que ser verdadero*/
	AccountantCharacter = i = ContantOfCharacterStored = 0;
	while (State)
	{
		/* Me controla una posible inicializacion de la variable AccountantCharacter*/
		if (AccountantCharacter == TABLENGTH)
			AccountantCharacter = 0;

		if (i == 0)
			ContantOfCharacterStored = StoredCharacterOfTheArray(StoredCharacter);

		/*Por si nadie escribe ningun caracter en la input. */
		if (!ContantOfCharacterStored)
			goto Salir;                     /*Se utilizó goto con la etiqueta de salir */

		/* Para inicializar el i cuando llegue al final de los caracteres almacenados en el array. (StoredCharacter)*/

		else if (i == ContantOfCharacterStored)
			i = 0;

		/* Condición que me cuenta los caracteres menos los saltos de línea y tabuladores*/

		else if ((StoredCharacter[i] != '\n') && (StoredCharacter[i] != '\t'))
			putchar(StoredCharacter[i]), AccountantCharacter++, i++;

		/*Un salto de línea hace que la variable AccountantCharacter se tenga que inicializar */

		else if ((StoredCharacter[i] == '\n'))
			putchar(StoredCharacter[i]), AccountantCharacter = 0, i++;

		/*Aquí está la magia ya que llamamos  al función PrintSpaceCharacter para que haga su trabajo */

		else if (!(StoredCharacter[i] != '\t'))
			PrintSpaceCharacter(AccountantCharacter), i++, AccountantCharacter = 0;

		/*Esta condición me controla la condición del cilo while*/

		if (StoredCharacter[i] == EOF)
			State = 0;
	}
Salir:
	return (0);
}

// Función que almacena una cantidad limitada de 9 espacios para los caracteres recibidos.

unsigned char StoredCharacterOfTheArray(char StoredCharacter[])
{
	unsigned char i;
	int Character;

	for (i = 0; (i < (9 - 1)) && ((Character = getchar()) != EOF) && (Character != '\n'); i++)
		StoredCharacter[i] = Character;
	if (Character == EOF)
		StoredCharacter[i++] = Character;
	else if (Character == '\n')
		StoredCharacter[i++] = Character;

	StoredCharacter[i] = '\0';

	return (i);
}

// función que imprime los caracteres de espacios equivalente a la tabulación.

void PrintSpaceCharacter(unsigned char NumberOfSpaceForPrint)
{
	unsigned char LimtOfLength;

	LimtOfLength = TABLENGTH - NumberOfSpaceForPrint;
	NumberOfSpaceForPrint = 0;
	while (NumberOfSpaceForPrint < LimtOfLength)
		putchar(' '), NumberOfSpaceForPrint++;
}
