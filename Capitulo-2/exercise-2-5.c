#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char s1[10] = "abcde fg";
	char s2[10] = "hijkk";

	printf("%d", any(s1, s2));
	return 0;
}

int any(char s1[], char s2[])
{
	/* any: returns the location of 's1' where first ocurrence with any
	 * character of 's2' appears.
	 */
	int i, j;
	int exit = -1; /* If there's no char matched then default token is -1 */
	
	for(i = 0; s2[i] != '\0' && exit == -1; i++)
		for(j = 0; s1[j] != '\0' && exit == -1; j++)
			if(s1[j] == s2[i])
				exit = j;
	return exit;
}
