#include <stdio.h>
#include <math.h>
#include <string.h>

void itob(int n, char s[], unsigned short base);
void reverse(char s[]);

int main()
{
	char s[20] = {'\0'};
	itob(4096, s, 10);
	printf("%s", s);
	return 0;
}

/* Function for base conversion e.g, decimal-hex, decimal-binary, ... */
void itob(int n, char s[], unsigned short b)
{
	int i, j;
	
	if(b == 16) /* Hexadecimal */
		for(i = n, j = 0; i > 0; i /= b, j++)
			s[j] = ((i % b) >= 10) ? (i % b) + 'A' - 10 : (i % b) + '0'; 
	else if(b == 10 || b == 8 || b == 2) /* Decimal, octal and binary */
		for(i = n, j = 0; i > 0; i /= b, j++)
			s[j] = (i % b) + '0'; 	
	else
		printf("Error. Incorrect value in third parameter.");
	s[j] = '\0';
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
