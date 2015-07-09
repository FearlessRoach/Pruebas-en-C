/* Rudimentary system for error checking in C code.
	This program particularly is going to be done in various
	stages (several days) for it's immensely broader than it 
	seems.
*/

#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);
void errpa(char line[], int len);

int main()
{
	char text[MAXLINE];
	errpa(text, MAXLINE);
	return 0;
}

void errpa(char line[], int max)
{
	int i;
	int err;
	int lines, len;
	int auxp, auxb;
	int tokens, tokend;
	int ipar, ibrak, ikey;
	
	lines = ipar = ikey = ibrak = auxp = auxb = 0;
	tokend = tokens = err = 0;
	while((len = getline(line, max)) > 0)
	{
		++lines;
		for(i = 0; i < len; i++)
		{
			if(line[i] == '\'' && tokens == 0 && tokend == 0) 
				tokens = 1;
			else if(line[i] == '\"' && tokend == 0 && tokens == 0)
				tokend = 1;
			else if(line[i] == '\'' && (tokens || tokend))
			{
			/* Marks the end of a single quoted string with variable tokens. */
				if(line[i-1] == '\\')
				{
					if(line[i-2] == '\\')
						tokens = 0;
				}
				else
					tokens = 0;	
			}
			else if(line[i] == '\"' && (tokend || tokens))
			{
			/* Marks the end of a double quoted string with variable tokend. */
				if(line[i-1] == '\\')
				{
					if(line[i-2] == '\\')
						tokens = 0;
				}
				else
					tokend = 0;			
			}
			else 
			{
				if(line[i] == '(')
				{
					auxb = ibrak;
					ipar++;
				}
				else if(line[i] == ')')
				{
					if(auxb == ibrak)
						ipar--;
					else
					{
						printf("Error: Parenthesis misplaced. Line --> %d\n", lines);
						err++;
					}
				}
				else if(line[i] == '[')
				{
					auxp = ipar;
					ibrak++;
				}
				else if(line[i] == ']')
				{
					if(auxp == ipar)
						ibrak--;
					else
					{
						printf("Error: Bracket misplaced. Line --> %d\n", lines);
						err++;
					}
				}
				else if(line[i] == '{')
				{
					if(ipar || ibrak)
					{
						printf ("Error: Brace misplaced. Line --> %d\n", lines);
						err++;
					}
					else
						ikey++;
				}
				else if(line[i] == '}')
					ikey--;
			}
		}
		if(ibrak)
		{	
			printf("Error. Mismatched brackets in line --> %d\n", lines);
			err++;
			ibrak = 0;
		}
		if(ipar)
		{
			printf("Error. Mismatched parenthesis in line --> %d\n", lines);
			err++;
			ipar = 0;
		}
		if(tokens || tokend)
		{
			printf("Error. Mismatched single or double quote string in line --> %d\n", lines);
			err++;
			tokend = tokend = 0;
		}
		
	}	
	if(ikey)
	{
		printf("Error. Mismatched keys.\n");
		err++;
	}
	printf("\nSyntactic errors found: %d", err);
}

int getline(char s[], int lim)
{
	int c, i; 

	for(i = 0; i < lim-1 && (c = getchar()) != EOF &&
			c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
