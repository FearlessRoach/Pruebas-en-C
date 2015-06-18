/* This program deletes all comments inside a C code, both single and multiple
line scope. */

#include <stdio.h>

#define MAXLINE 1000 /* Maximum number of characters per line. */

int getline(char str[], int lim); // K&R's get line function .
void copy(char to[], char from[]); // K&R's copy function.

int main()
{
	int i, j;
	int len;
	int tokens, tokend; 
	/* 'tokens' variable signals the start & finish of a single quote string.
		'tokend' variable signals the start & finish of a double quote string. */
	int comi; /* Indicates the begining & end of any sort of comment. */
	char line[MAXLINE];

	tokens = tokend = comi = 0;
	while((len = getline(line, MAXLINE)) > 0)
	{
		i = 0;
		while(i < len)
		{
			if(line[i] == '\'' && comi == 0 && tokens == 0)
			{
			/* Prints every single quote string that isn't inside a comment
				and marks its start with variable 'tokens'. */
				printf("%c", line[i]);
				tokens = 1;
				i++;
			}	
			else if(line[i] == '\"' && comi == 0 && tokend == 0)
			{
			/* Prints every double quote string that isn't inside a comment
				and marks its start with variable 'tokend'. */
				printf("%c", line[i]);
				tokend = 1;
				i++;
			}
			else if(line[i] == '\'' && tokens && comi == 0)
			{
			/* Marks the end of a single quoted string with variable tokens. */
				printf("%c", line[i]);
				tokens = 0;
				i++;
			}
			else if(line[i] == '\"' && tokend && comi == 0)
			{
			/* Marks the end of a double quoted string with variable tokend. */
				printf("%c", line[i]);
				tokend = 0;
				i++;
			}
			else if((tokens || tokend) && comi == 0)
			{
			/* Prints anything that belongs into single and double quoted strings,
				and doesn't belong in a comment. */ 
				printf("%c", line[i]);
				i++;
			}
			else
			{
			/* This chunk analyzes everything outside single and double quoted
				strings i.e. Comments. */
				if(line[i] == '/' && line[i+1] == '*')
				{
				/* Finds any multi-line comment and indicates it using 'comi'. */
					comi = 1;
					i += 2;
				}
				else if(line[i] == '/' && line[i+1] == '/')
				{
				/* Finds any single-line comment. */
					for(j = i; j < len-1; j++)
						;
					i = j;
				}
				/* Finds the end of multi-line comments and restores variable 'comi'. */
				else if(line[i] == '*' && line[i+1] == '/'
					&& comi == 1) 
				{
					comi = 0;
					i += 2;
				}
				/* Overrides every char inside a multi-line comment. */
				else if(comi == 1 && (line[i] != '*' && line[i+1] != '/'))
					i++;	
				else
				{
				/* Prints each char outside comments. */
					printf("%c", line[i]);
					i++;
				}
			}
		}
	}
	return 0;
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
