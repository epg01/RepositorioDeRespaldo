#include <stdio.h>

#define ALLOCSIZE 1000
#define VALUEDEFAULT '\0'
#define DEFAULT -2

int storedC[ALLOCSIZE];

#define IAMAWORD(x) (((x) != ('\n')) && ((x) != ('\t')) && ((x) != (' ')) && ((x) != ('\0')))
#define NOTWORD(y) (((y) == ('\n')) || ((y) == (' ')) || ((y) == ('\t')))

void printHV(int *s, int M);
int searchM(int s[]);

int main(void)
{
	int c;
	int temp;
	int count;
	int i = 0;
	int M;

	i = 0, count = 0, temp = VALUEDEFAULT;
	while((c = getchar()) != EOF)
	{
		if (IAMAWORD(temp) && NOTWORD(c))
			storedC[i++] = count, count = 0;
		else if(IAMAWORD(c))
			count++;
		temp = c;
	}
	storedC[i++] = DEFAULT, storedC[i] = DEFAULT;
	M = searchM(storedC);
	printHV(storedC, M);
	return(0);
}
int searchM(int s[])
{
	int temp1, temp2;
	int i,j;

	for(i = 0, j = 1, temp2 = 0; s[i]; j += 1, i = j + 1)
	{
		if (s[i] > s[j])
		{
			temp1 = s[i];
		}
		else
			temp1 = s[j];
		if (temp2 < temp1)
			temp2 = temp1;
	}
	return(temp2);
}

void printHV(int *s, int M)
{
	int i;
	int *temp = s;
	int *temp2;

	for(i = 0, temp2 = &M ; *temp2; )
	{
		if(s[i] == *temp2)
			putchar('*'), s++;
		if(!(s[i] - *temp2))
			putchar('*'), s++;
		if (s[i] > *temp2 && s[i] != DEFAULT)
			putchar('*'), s++;
		else
			putchar('_'), s++;
		if((s[i] == DEFAULT) || (s[i] == DEFAULT))
		{
			putchar('\n');
			s = temp;
			*temp2 -= 1;
			i = 0;
		}
	}
}
