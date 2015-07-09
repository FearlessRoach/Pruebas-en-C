/* Creates & applicates function 'entab' to substitute numerous succesive
	space blanks for the right amount tabs and blanks to keep the same
	formatting. 
*/

#include <stdio.h>
#include <math.h> /* To use 'ceil' function. */

#define TABSTOPS 4 /* Spaces until next tabstop. */

void entab(char line[], int len, int tabs);
void dts(int tabs, int len);
void copy(char from[], char to[]);

int main()
{
	char str[100] = "Hola, veamos si funciona       la   funcion. Espero  que     si. Andele, si funciono.";
	printf("%s", str);
	entab(str, 100, TABSTOPS);
	printf("\n");
	printf("%s", str);
	return 0;
}

void entab(char line[], int len, int tabs) /* Entab function. */
{
	int i, j, k;
	int token; /* Indicates if blanks are found consecutively */
	char copia[len];
	
	i = k = j = token = 0;
	while(i < len)
	{
		if(line[i] == ' ')
			++token;
		else 
		{
			for(j = 0; j < token/tabs; j++) /* With this we obtain the corresponding tabs' characters ('\t'). */
			{
				for(k = 0; k < tabs; k++) /* Asigns the correct amount of spaces according to TABSTOPS */
					copia[k + i] = ' ';
			}
			i += k;
			for(j = 0; j < token % tabs; j++) /* This is to get the remaining spaces to complete the original format */
				copia[j + i] = ' ';
			i += j;
			copia[i] = line[i-k-j]; 
			token = 0;
		}
		i++;
	}
	copy(copia, line);
}

void copy(char from[], char to[])
{
	int i;
	
	i = 0;
	while(from[i] != '\0')
	{
		to[i] = from[i];
		++i;
	}
}

void dts(int tabs, int len) /* Draws tabstops according to an input length */
{
	int i, j;

	for(i = 0; i < ceil((float)len/tabs); i++)
	{
		for(j = 0; j < tabs; j++)
		{
			if(j == 0)
				printf("^");
			printf(" ");
		}
	}
}
