/* Version of the exercise 2.4. Could be a misled idea
 * but it's what I got from the exercise's sentence.
 */
#include <stdio.h>

void squeeze2(char s1[], char s2[]);

int main()
{
		
}

void squeeze2(char s1[], char s2[])
{
	int i, j, k;

	for(i = k = 0; s1[i] != '\0'; i++)
		for(j = 0; s2[j] != '\0'; j++)
			if(s[j] != s[i])
				s[k++] = s[i];
	s[k] = '\0';
}
