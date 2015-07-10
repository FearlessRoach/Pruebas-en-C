#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(unsigned int n, char s[]);

int main()
{
	char s[100] = {'\0'};
	int c;
	c = 39;
	printf("Como tipo entero\t\t--> %d\n", c);
	itoa(c, s);
	printf("Como tipo cadena de caracteres  --> %s", s);	
	return 0;
}

/* itoa: convert 'num' to characters in 's' */
void itoa(unsigned int num, char s[])
{
	int i, sign;
	
	if((sign = num) < 0) /* Record sign */ 
		num = -num;	/* Make 'num' positive */
	i = 0;
	do	/* Generate digits in reverse order */
	{
		s[i++] = num % 10 + '0';	/* Get next digit */
	} while ((num /= 10) > 0);	/* Delete it */
	if(sign < 0)
		s[i++] = '-';
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
