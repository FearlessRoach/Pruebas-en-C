#include <stdio.h>
#include <math.h>

#define TABSTOPS 3
#define MAXLINE 1000

void detab(char line[], int len, int tabs);
void display_tab_stops(int tabs, int len);
int getline(char line[], int lim);
void copy(char to[], char from[]);

int main()
{
	int len, max;
	char str[MAXLINE];
	
	max = 0;
	while((len = getline(str, MAXLINE)) > 0)
	{
		detab(str, len, TABSTOPS);
		printf("%s", str);
		if(len > max)
			max = len;
	}
	printf("\n");
	display_tab_stops(TABSTOPS, max);
	return 0;
}

void detab(char line[], int len, int tabs)
{
	int i, j, tleft; /* 'tleft' indicates the amount of remaining spaces until next tab stop */
	char cop[len];
	
	i = j = 0;
	while(i < len)
	{
		if(line[i] == '\t')
		{
			for(j = 0; j < (tleft = (i+1) % tabs); j++)
				cop[i + j] = ' ';
			i += j;	
		}
		else
			cop[i] = line[i];
		i++;
	}	
	copy(line, cop);
}
	
void display_tab_stops(int tabs, int len)
{
	int i, j;
	
	for(i = 0; i < ceil((float)len/tabs); i++)
	{
		for(j = 0; j < tabs; j++)
		{
			if( j == 0)
				printf("^");
			else
				printf(" ");
		}
	} 
	printf("\n");
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy (char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
