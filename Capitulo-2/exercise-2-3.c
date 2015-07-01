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
	int i, j, len, res;

	res = 0;
	len = slen(s);
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		for(i = len-1; i > 1; i--)
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
	else
	{
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

int slen(char s[])
{
	int i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}
