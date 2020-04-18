#include <stdio.h>

#define MAXLINE 3     /* Maximun input line length*/

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

// Print the longest input line
int main(void)
{
	int c;
	int len;                      // Current line length
	int max;                      // Maximun length see so far
	char line[MAXLINE];           // Current input line
	char longest[MAXLINE];        // longest line saved here
	int counti;

	max = counti = 0;
	while ((len = getlinee(line, MAXLINE)) > 0){
		while(c = getchar() != EOF)
			counti++;
		if (len > max){
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)                  // There was a line
		printf("%s", longest);
	printf("\nMaxima linea escrita: %d\n", counti + max);
	return(0);
}

/* getline: read a line into s; return longth */
int getlinee(char s[],int lim)
{
        int c, i;
        for (i = 0; (i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

/* Copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from [i]) != '\0')
		i++;
}
