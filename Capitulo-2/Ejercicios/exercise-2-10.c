#include <stdio.h>
int lower2(int c);

int main()
{
	printf("%c", lower2('G'));
	return 0;
}

/* Function using operator '?', replacing if-else way from function lower */
int lower2(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
