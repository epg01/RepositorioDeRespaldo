#include <stdlib.h>
#include <stdio.h>

// Declaramos las funciones y como otros lo denominan (funciones prototipo)

unsigned char StoredCharacterOfTheArray(char StoredCharacter[]);
unsigned char RemoveComment(char StoredCharacter[], unsigned char IndexOfArray);
unsigned char SecondVersion(char StoredCharacter[], unsigned char IndexOfArray);

#define ARRAYSIZE 170     /* Tamaño del arrray nota: por que se habrá escodigo 170  */

unsigned char ContantOfCharacterStored;
int main(void)
{

	char StoredCharacter[ARRAYSIZE];

	unsigned char i, State, AccountantCharacter;

	State = 1;                                                     /* Ya que debe entrar, por tanto el State tiene que ser verdadero*/
	i = 0;
	while (State)
	{
		if (i == 0)
			ContantOfCharacterStored = StoredCharacterOfTheArray(StoredCharacter);

		/*Por si nadie escribe ningun caracter en la input. */
		if (!ContantOfCharacterStored)
			goto Salir;                     /*Se utilizó goto con la etiqueta de salir */

		/* Para inicializar el i cuando llegue al final de los caracteres almacenados en el array. (StoredCharacter)*/

		else if (i == ContantOfCharacterStored)
			i = 0;

		/* Condición que me cuenta los caracteres menos los saltos de línea y tabuladores*/

		else if ((StoredCharacter[i] != '/') && (StoredCharacter[i + 1] != '*') /*&& !(StoredCharacter[i + 1] == '/')*/)
			putchar(StoredCharacter[i]), i++;

		else //((StoredCharacter[i] == '/') && (StoredCharacter[i + 1] == '*'))
			i = RemoveComment(StoredCharacter, i);
//	        else if ((StoredCharacter[i] == '/') && (StoredCharacter[i + 1] == '/'))
//			i = SecondVersion(StoredCharacter, i);

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

	for (i = 0; (i < (ARRAYSIZE - 1)) && ((Character = getchar()) != EOF) && (Character != '\n'); i++)
		StoredCharacter[i] = Character;
	if (Character == EOF)
		StoredCharacter[i++] = Character;
	else if (Character == '\n')
		StoredCharacter[i++] = Character;

	StoredCharacter[i] = '\0';

	return (i);
}

unsigned char RemoveComment(char StoredCharacter[], unsigned char IndexOfArray)
{
	char State = 1;

	while (State)
	{
		if (IndexOfArray == ContantOfCharacterStored)
			ContantOfCharacterStored = StoredCharacterOfTheArray(StoredCharacter), IndexOfArray = 0;
		if (StoredCharacter[IndexOfArray] == '*' && StoredCharacter[IndexOfArray + 1] == '/')
			State = 0;
		else if (StoredCharacter[IndexOfArray] == EOF || ContantOfCharacterStored == 0)
			exit(0);
		IndexOfArray++;
	}
	return (IndexOfArray + 1);
}

unsigned char SecondVersion(char StoredCharacter[], unsigned char IndexOfArray)
{
        char State = 1;

        while (State)
        {
                if (IndexOfArray == ContantOfCharacterStored)
                        ContantOfCharacterStored = StoredCharacterOfTheArray(StoredCharacter), IndexOfArray = 0;
                if (StoredCharacter[IndexOfArray] == '\n')
                        State = 0;
                else if (StoredCharacter[IndexOfArray] == EOF || ContantOfCharacterStored == 0)
                        exit(0);
                IndexOfArray++;
        }

        return (IndexOfArray - 1);
}
