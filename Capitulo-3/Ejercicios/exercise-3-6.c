#include <stdio.h>
#include <string.h>

void itoa_pad( unsigned int n, char s[], unsigned int w);
void reverse(char s[]);

int main()
{
	char s[20];

	itoa_pad(39, s, 10);
	printf("%s", s);
	return 0;
}

/* Pads with blanks to the left depending on the width ('w') asigned */
void itoa_pad(unsigned int num, char s[], unsigned int wid)
{
	int i, sign;
	
	if((sign = num) < 0)
		num = -num;
	i = 0;
	do
	{
		s[i++] = num % 10 + '0';
	} while ((num /= 10) > 0 && i < wid);
	if(sign < 0)
		s[i++] = '-';
	while(i < wid) /* Makes the padding */
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
