/* Version of the exercise 2.4. Could be a misled idea
 * but it's what I got from the exercise's sentence.
 */
#include <stdio.h>

void squeeze2(char s1[], char s2[]);

int main()
{
	char s1[30] = "prueba ghj rtm miro squeeze";
	char s2[30] = "prueba de squeeze";
	
	printf("%s\n", s1);
	squeeze2(s1, s2);
	printf("%s\n", s1);
	printf("%s", s2);
	return 0;
}

void squeeze2(char s1[], char s2[]) 
{
	/* Function to 'squeeze' a string (s1) 
	 * against other string (s2). 
	 */
	int i, j, k;

	for(i = 0; s2[i] != '\0'; i++) 
	{
		/* Comparing a character from 's2' with entire 's1' string */
		for(j = k = 0; s1[j] != '\0'; j++)
			if(s2[i] != s1[j] || s1[j] == ' ')
				/* If the char's are different, add 's1' char to its begining */
				s1[k++] = s1[j];
	}
	s1[k] = '\0';
}
