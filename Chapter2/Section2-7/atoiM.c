int atoi(char s[])
{
	int n;

	n = 0;
	while (*s)
	{
		n = (n * 10) + (*s++ - '0');
	}
	return (n);
}
