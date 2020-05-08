/**
 *         **************************************************************************************************
 *         *   Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to   *
 *         *                  write a program that reverses its input a line at a time.                     *
 *         *                                                                                                *
 *         **************************************************************************************************
 */

#include <stdio.h>

#define MAXNUMBER 1000

int getlinee(char StoredCharacter[], int SizeArray);
void reverse(char StoredCharacter[], int indexOfArray);

int main(void)
{
	char StoredCharacter[MAXNUMBER];
	int LengthOfStoredCharacters;

	while ((LengthOfStoredCharacters = getlinee(StoredCharacter, MAXNUMBER)) > 0)
		reverse(StoredCharacter, LengthOfStoredCharacters), printf("%s",StoredCharacter);
}

// OBTENER NUEVA LÍNEA.

int getlinee(char StoredCharacter[], int SizeArray)
{
	int Character, i;

	for (i = 0; i < (SizeArray -1) && ((Character = getchar()) != '\n') && (Character != EOF); i++)
		StoredCharacter[i] = Character;
	if (Character == '\n')
		StoredCharacter[i++] = Character;
	StoredCharacter[i] = '\0';
	return (i);
}

//Función de reversar.

void reverse(char StoredCharacter[], int indexOfArray)
{
	char *PunteroStoredCharacter = StoredCharacter;
	char CharacterTempOfStoredCharacter;
	int SolveHalfTheSize;

	PunteroStoredCharacter += (indexOfArray - 2);
	SolveHalfTheSize = indexOfArray/2;
	if (*(StoredCharacter + indexOfArray - 1) == '\n')
	{
		while (indexOfArray-- > (SolveHalfTheSize) + 1)
		{
			CharacterTempOfStoredCharacter = *StoredCharacter, *StoredCharacter = *PunteroStoredCharacter;
			*PunteroStoredCharacter = CharacterTempOfStoredCharacter;
			*PunteroStoredCharacter--, StoredCharacter++;
		}
 	}
}
