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
	char s[4] = "F45D";

	
}

int htoi(char s[])
{
	int i, j, len, res;

	res = 0;
	len = slen(s);
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		for(i = 2; i < len; i++)
		{
			if(s[i] >= '0' && s[i] <= '9')
			{
				res = [i] - '0';
			}
			else if(s[i] >= 'a' && s[i] <= 'f')
			{
				res = s[i] - 'a' + 10;
			}
			else if(s[i] >= 'A' && s[i] <= 'F')
			{
				res = s[i] - 'A' + 10;
			}
			else
			{
				printf("The \'%c\' value does not correspond \ 
						  with HEX symbol.\n", s[i]);
				exit(0);
			}

	}
	else
	{
		for(i = 0; i < len; i++)
		{
			if(s[i] >= '0' && s[i] <= '9')
				res = res + s[i] - '0';
			else if(s[i] >= 'a' && s[i] <= 'f')
				res = res + s[i] - 'a' + 10;
			else if(s[i] >= 'A' && s[i] <= 'F')
				res = res + s[i] - 'A' + 10;
			else
			{
				printf("The \'%c\' value does not correspond \ 
						  with HEX symbol.\n", s[i]);
				exit(0);
			}
		}
	}
}

int slen(char s[])
{
	int i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}
