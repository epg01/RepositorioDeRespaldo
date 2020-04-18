include <stdio.h>

#define DEFAULT '\0'
#define IAMAWORD(x) (((x) != ('\n')) && ((x) != (' ')) && ((x) != ('_')))
#define NOTWORD(y) (((y) == ('\n')) || ((y) == (' ')) || ((y) == ('_')) || ((y) == (DEFAULT)))
int getlinee(char StoredC[], int Limit)
{
	int c;             // Variable que guardará o almacenará el valor de getchar retorne
	char temp;          // Guardará el pasado de temp, es decir el valor anterior.
	int i;             // Ésta variable denominada i es fundamental ta que ésta servirá de contador de caracteres, incluido el terminador para la string '\0'.
	// Inicializamos la variable temp, al valor po DEFAULT, esto es necesario y obviamente inicializamos a la variable i, ya que este recorrerá las celdas del vector.
	char *p = StoredC;
	int count = 0, count1 = 0, respaldo = 0;
	char s[9];
	temp = DEFAULT, i = 0;
	while((--Limit > 0) && (temp != '\n') && (p++))
	{
		if (NOTWORD(p[-1]) && NOTWORD(temp))
			temp = p[-1];
		else if (IAMAWORD(p[-1]))
			s[i] = p[-1], temp = p[-1];
		else if ((IAMAWORD(temp) && NOTWORD(p[-1])))
		{
			if (p[-1] != '\n')
			{
				if (!count1)
					count1 = i;
				count = i;
				s[count++] = p[-1];
			}
			else
				s[respaldo++] = '\n', s[respaldo] = '\0';
			if (!respaldo)
				respaldo = count1, count1 = 0;

		}
		if (s[respaldo - 1] == '\n')
			temp = '\n';
		i++;
	}
	return(i);
}

int main(void)
{
	char s[] = "hola_ _\n";
	getlinee(s, 15);
	printf("%s", s);

	char t[] = "  hola_ _\n";
	getlinee(t, 15);

	char ss[] = " _h_t_\n";
	getlinee(ss, 15);

	char sss[] = " _h__t\n";
	getlinee(sss, 15);
}
