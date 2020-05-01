#include <stdio.h>

#define MAXLINE 5

int getlinee(char s[], int MaxLine);

int main(void)
{
	int Len;
	char Line[MAXLINE];


	while((Len = getlinee(Line, MAXLINE)) > 0)
		if (Len)
			printf("%s", Line);
	return(0);
}
// Constantes simbolícas

#define DEFAULT '\0'     // Valor por defecto que dentra la variable temporal, ya que inicialmente temp posee valor, ya que es el pasado de la variable
                         // Que se guarda en la función getchar()

// Macros.

#define IAMAWORD(x) (((x) != ('\n')) && ((x) != (' ')) && ((x) != ('\t')))
#define NOTWORD(y) (((y) == ('\n')) || ((y) == ('\t')) || ((y) == (' ')) || ((y) == (DEFAULT)))

// Se defina la función getlinee.
int getlinee(char StoredC[], int Limit)
{
	int c;             // Variable que guardará o almacenará el valor de getchar retorne
	int temp;          // Guardará el pasado de temp, es decir el valor anterior.
	int i;             // Ésta variable denominada i es fundamental ta que ésta servirá de contador de caracteres, incluido el terminador para la string '\0'.

// Inicializamos la variable temp, al valor po DEFAULT, esto es necesario y obviamente inicializamos a la variable i, ya que este recorrerá las celdas del vector.

	temp = DEFAULT, i = 0;
	while((--Limit > 0) && ((c = getchar()) != EOF) && (temp != '\n'))
	{
		if (NOTWORD(c) && NOTWORD(temp))
			;
		else if (IAMAWORD(c))
			StoredC[i++] = c;
		else if (NOTWORD(temp) && (c == '\n'))
			StoredC[i++] = '\n', StoredC[i] = '\0';
		temp = c;
	}
	return(i);
}
