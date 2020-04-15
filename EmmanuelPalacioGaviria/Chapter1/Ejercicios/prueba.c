#include <stdio.h>
void printHV(int *s)
{
	int i = 0;
	int *temp = s;
	int *temp2;
	temp2 = s + 3;

	for( ; *temp2; )
	{
		if(s[i] == *temp2)
			putchar('*'), s++;
		if(!(s[i] - *temp2))
			putchar('*'), s++;
		if (s[i] > *temp2)
			putchar('*'), s++;
		else
			putchar('_'), s++;
		if(s[i] == 3456 || s[i] == 3444)
		{
			putchar('\n');
			s = temp;
			*temp2 -= 1;
			i = 0;
		}
	}
}

int main() {


	int s[] ={1,6,2,6,5,1, 3456, 3444};
	printHV(s);
	return 0;
}
