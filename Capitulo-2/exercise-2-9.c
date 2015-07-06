#include <stdio.h>

int bitcount(unsigned y);

int main()
{
	unsigned x = 7;
	
	printf("%d", bitcount(x));
	return 0;
}

/* Counts 1's in any unsigned number */
int bitcount(unsigned y)
{
	int i;

	for(i = 0; y != 0; y &= (y-1))
		i++;
	return i;
}
