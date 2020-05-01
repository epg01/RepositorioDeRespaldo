// The concept of pointers descussed in chapter 5 was used.

void copy(char to[], char from[])
{
	while ((*to++ = *from++))
		;
}
