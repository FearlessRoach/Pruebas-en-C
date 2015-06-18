/* This program deletes all comments inside a C code, both single and multiple
	line scope. */

#include <stdio.h>

#define MAXLINE 1000

int getline(char str[], int lim);
void copy(char to[], char from[]);

int main()
{
	int i;
	int len;
	int tokens, tokend;
	int comi, comf;
	char line[MAXLINE];

	tokens = tokend = comi = comf = 0;
	while((len = getline(line, MAXLINE)) > 0)
	{
		i = 0;
		while(i < len)
		{
			if(line[i] == '\'')
			{
				printf("%c", line[i]);
				tokens = 1;
				i++;
			}	
			else if(line[i] == '\'' && tokens == 1)
			{
				printf("%c", line[i]);
				tokens = 0;
				i++;
			}
			else if(line[i] == '\"')
			{
				printf("%c", line[i]);
				tokend = 1;
				i++;
			}	
			else if(line[i] == '\"' && tokend == 1)
			{
				printf("%c", line[i]);
				tokend = 0;
				i++;
			}	
			else
			{
				if(line[i] == '/'	&& tokens == 0 && tokend == 0)
				{
					comi = 1;
					i++;
				}
				else if(line[i] = '*' && comi == 1)
				{
					comf = 1;
					i++;
				}
				else if(comf == 1)
					i++;
				else if(line[i] == '*' && comf == 1)
				{
					comf = 2;
					i++;
				}
				else if(line[i] = '/' && comf == 2)
				{
					comf = 0;
					comi = 0;
					i++;
				}
				else
				{
					printf("%c", line[i]);
					i++;
				}
			}
		}
	}
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
