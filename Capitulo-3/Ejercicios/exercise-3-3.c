#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main()
{
	char s[20] = "a-z4-9 8-j -d-g";
	char e[100] = {'\0'}; /* Mandatory to clean string before use it */

	expand(s, e);
	printf("%s", e);
	return 0;
}

/* Expands certain patterns for wilcard use i.e, a-z, 0-9 */
void expand(char s1[], char s2[])
{
	int i, san, j, to; /* san: alphanumeric symbol */

	to = 0;
	for (i = 0; i < strlen(s1); i++)
		if(s1[i] == '-')
		{
			if(isdigit(s1[i-1]) && isdigit(s1[i+1])) /* Processes digits */
				for(san = s1[i-1], j = to; san <= s1[i+1]; san++, j++)
					s2[j] = san;
			else if(isalpha(s1[i-1]) && isalpha(s1[i+1])) /* For alphabet */
				for(san = s1[i-1], j = to; san <= s1[i+1]; san++, j++)
					s2[j] = san;
			else /* In case it's not a complying pattern */
				for(j = to, san = i-1; san <= i+1; j++, san++)
					s2[j] = s1[san];
			s2[j++] = ' ';
			to = j;
		}
}
