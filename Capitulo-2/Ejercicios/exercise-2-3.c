/* Creating function 'htoi' to convert string of hexadecimal digits
 * into the equivalent integer value.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int htoi(char string[]);
int slen(char string[]);

int main()
{
	char s[20] = "3da5Fg\0";
	int n;
	
	n = htoi(s);
	printf("%d", n);
	return 0;
}

int htoi(char s[])
{
	/* Streams any value in HEX representation into integer form */
	int i, j, len, res;

	res = 0; /* Gives the resulting value */
	len = slen(s);
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		/* If the HEX starts with '0x' or '0X' */
		for(i = len-1; i > 1; i--)
		{
			/* Walkthrough is in 'reverse' mode (last char to first char) */
			if(s[i] >= '0' && s[i] <= '9')
				res = res + (s[i] - '0')*pow(16, len-1-i);
			else if(s[i] >= 'a' && s[i] <= 'f')
				res = res + (s[i] - 'a' + 10)*pow(16, len-1-i);
			else if(s[i] >= 'A' && s[i] <= 'F')
				res = res + (s[i] - 'A' + 10)*pow(16, len-1-i);
			else
			{
				printf("The \'%c\' value does not correspond " 
						 "with HEX symbol.\n", s[i]);
				exit(0);
			}
		}
	}
	else
	{
		/* Same process but without '0x' or '0X' */
		for(i = len-1; i >= 0; i--)
		{
			if(s[i] >= '0' && s[i] <= '9')
				res = res + (s[i] - '0')*pow(16, len-1-i);
			else if(s[i] >= 'a' && s[i] <= 'f')
				res = res + (s[i] - 'a' + 10)*pow(16, len-1-i);
			else if(s[i] >= 'A' && s[i] <= 'F')
				res = res + (s[i] - 'A' + 10)*pow(16, len-1-i);
			else
			{
				printf("The \'%c\' value does not correspond " 
						 "with HEX symbol.\n", s[i]);
				exit(0);
			}
		}
	}
	return res;
}

int slen(char s[]) /* slen: returns length of string 's' */
{
	int i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}
