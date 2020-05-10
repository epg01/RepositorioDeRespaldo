#include <stdio.h>

unsigned char StoredCharacterOfTheArray(char StoredCharacter[]);
void PrintSpaceCharacter(unsigned char NumberOfSpaceForPrint);

int main(void)
{

	char StoredCharacter[9];
	unsigned char ContantOfCharacterStored;
	unsigned char Accountant, State = 1, Accountant2;

	Accountant2 = Accountant = ContantOfCharacterStored = 0;
	while (State)
	{
		if (Accountant2 == 8)
			Accountant2 = 0;

		if (Accountant == 0)
			ContantOfCharacterStored = StoredCharacterOfTheArray(StoredCharacter);

		if (!ContantOfCharacterStored)
			goto Salir;

		else if (Accountant == ContantOfCharacterStored)
			Accountant = 0;

		else if ((StoredCharacter[Accountant] != ' ') && (StoredCharacter[Accountant] != '\n'))
			putchar(StoredCharacter[Accountant]), Accountant2++, Accountant++;
		else if (StoredCharacter[Accountant] == ' ')
			putchar(StoredCharacter[Accountant]), Accountant2 = 0, Accountant++;
		else if ((StoredCharacter[Accountant] == '\n'))
			putchar(StoredCharacter[Accountant]), Accountant2 = 0, Accountant++;
		else if (!(StoredCharacter[Accountant] != '\t'))
			PrintSpaceCharacter(Accountant2), Accountant++, Accountant2 = 0;

		if (StoredCharacter[Accountant] == EOF)
			State = 0;
	}
Salir:
	return (0);
}

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

void PrintSpaceCharacter(unsigned char NumberOfSpaceForPrint)
{
	unsigned char numero;

	numero = 8 - NumberOfSpaceForPrint;
	NumberOfSpaceForPrint = 0;
	while (NumberOfSpaceForPrint < numero)
		putchar(' '), NumberOfSpaceForPrint++;
}
