#include <stdio.h>
unsigned inverted(unsigned, int, int);
unsigned getbits(unsigned, int, int);

int main()
{
	unsigned bit;

	printf("%d", inverted(8, 1, 2));
	return 0;
}

unsigned inverted(unsigned x, int p, int n)
{
	/* Inverts 'n' bits from position 'p' of 'x' */
	unsigned b;
	
	b = getbits(x, p, n); /* Gets the bits to invert */
	b = (b | ~(~0 << n)) << (p+1-n); 
	return b ^ x; /* Applies XOR to contrast 'b' into 'x' */
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
