/* Rudimentary system for error checking in C code.
	This program particularly is going to be done in various
	stages (several days) for it's immensely broader than it 
	seems.
*/

#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char(to[]), char from[]);
void errpa(char line[], int len);

int main()	
{
		
}

void errpa(char line[], int max)
{
	int i;
	int ind; /* Signifies the loop (while) located a '(' or ')' */
	
	ind = 0;
	while((len = getline(line, max)) > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(line[i] == '(')
			{
				++ind;
				
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
