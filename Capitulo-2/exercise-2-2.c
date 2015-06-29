/* Re-writing getline loop from chapter 1 without
 * the use of && nor ||.
 */
#include <stdio.h>

#define MAX 1000
 
int getline2(char line[], int max);

int main()
{
	char li[MAX];
	int len;

	while((len = getline2(li, MAX)) > 0)
		printf("%s", li);
	return 0;
}

int getline2(char s[], int lim) /* Version 2.0 of the getline function */
{
	int c, i; 

	i = 0;
	while(i < lim-1)
	{
		if((c = getchar()) != '\n')
		{
			if(c != EOF)
				s[i] = c;
			else
				break;	/* Searching for a way to maket it work without break
							 * statement involve
							 */
		}
		else
			break;
		i++;
	}
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}
