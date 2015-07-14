/* Version of function strindex, returns the rightmost occurrence
 * of 't' (the last finding) in 's'
 */
#include <stdio.h>
#include <string.h>

int strindex2(char s[], char t[]);

int main()
{
	printf("%d\n", strindex2("prueba, veremos funciona, creo que ", "vere"));
	return 0;
}

int strindex2(char s[], char t[])
{
	int i, j, k;

	for(i = strlen(s)-1; i >= 0; i--) /* Inspects 's' backwards */
	{
		for(j = i, k = strlen(t)-1; k >= 0 && s[j] == t[k]; j--, k--)
			;
		if(t[k+1] == t[0])
			return i - (strlen(t)-1);
	}
	return -1;
}
