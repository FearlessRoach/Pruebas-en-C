#include <stdio.h>

int logb2(int n);
unsigned rightrot(unsigned x, int n);
unsigned getbits(unsigned x, int p, int n);

int main()
{
	unsigned x = 17;
	
	printf("%u", rightrot(x, 2));
	return 0;
}

/* Rotates 'x' rightwise according to number 'n' */
unsigned rightrot(unsigned x, int n)
{
	int i;
	unsigned au;

	au = x;
	/* Inside the loop: makes a logical shift to the right and applies
	 * OR operation versus least bit padded leftwise according x's 
	 * number of bits
	 */
	for(i = 0; i < n; i++)
		au = (au >> 1) | (getbits(au, 0, 1) << logb2(x)-1);
	return au;
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

/* Function to get the logarithm base 2 of 'n' */
int logb2(int n)
{
	int i, j;

	i = 1;
	j = n;
	while(j >= 2)
	{
		j = j/2;
		i++;
	}
	return i;
}
