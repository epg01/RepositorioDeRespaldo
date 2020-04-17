/**
 *   Note: Solution of the book programming in C of k&D
 *   *******************************************************
 *   *             Program Structure                       *
 *   *             While (there's another line)            *
 *   *                    (save it)                        *
 *   *                    (save its lenght)                *
 *   *             print longest line                      *
 *   *******************************************************
 */

#include <stdio.h>

#define MAXLINE 1000     /* Maximun input line length*/

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

// Print the longest input line
int main(void)
{
	int len;                      // Current line length
	int max;                      // Maximun length see so far
	char line[MAXLINE];           // Current input line
	char longest[MAXLINE];        // longest line saved here

	max = 0;
	while ((len = getlinee(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0)                  // There was a line
		printf("%s", longest);
	return(0);
}
