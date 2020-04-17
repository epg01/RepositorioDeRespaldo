* Vertical Histogram of words in a Sentence */

#include<stdio.h>
#define MAXWL 20  /* Maximum length of a word */
#define MAXNO 25 /* Maximum No of words in a sentence */

int main(void)
{
	int word[MAXNO];
	int i,c,j,nc,nw;

	for(i=0;i<MAXNO;++i)
		word[i]=0;

	nc = nw = 0;

	while( (c=getchar()) != EOF)
	{
		++nc;
		if( c ==' ' || c =='\n' || c =='\t')
		{
			word[nw] = nc -1; /* -1 for excluding the space in the word length */
			++nw;
			nc = 0; /* resetting the word-length for the next word */
		}
  
	}

	for( i = MAXWL; i >= 1; --i)
	{
		for(j=0;j <= nw;++j)
		{
		if( i <= word[j])
			putchar('*');
		else  
			putchar(' ');
	}
		putchar('\n');
	}

	return 0;
	}
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
