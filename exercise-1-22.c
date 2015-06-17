/* Program that 'folds' long text lines i.e. separates long input lines into
   several shorter lines. */

#include <stdio.h>

#define COLUMN 30 // Defines a quantity for text character to be allowed in 
						// one same line.

void fold(char line[], int len, int column);

int main()
{
	char sent[300] = "sdfsdfk/*saj fasñda  asdfnña sasfnas fñasdafaos sfanfskdjnfksdkf aeiuqn qpeocnoeqperituqet qpnvqjslkjf fañeiencpn jc//nlaejfn vj//kdfñkjdakjhf kjhfak    d         kdjfhalfkj*hd adkjfh ds*/klksjdcn39iun aj sd";
	
	printf("%s\n\n", sent);
	fold(sent, 300, COLUMN);
	return 0;
}

void fold(char line[], int len, int col) /* Function to fold lines */
{
	int i, j;
	int token; /* Indicates if a blank space or a tab space has been found at
					  the commencement of a new folded line. */

	token = 0; 
	if(len <= col)
		printf("%s", line);
	else
	{
		for(i = 0; i < len; i++)
		{
			if(line[i] != ' ' && line[i] != '\t')
				token = 1; /* A character has been encounter. */
			if((i+1) % col != 0 && token == 1) // Prints only COLUMN amount of
				printf("%c", line[i]);			  // characters
			if((i+1) % col == 0) /* Start of a new line. */
			{
				token = 0;
				printf("\n");
			}
		}
	}
}
