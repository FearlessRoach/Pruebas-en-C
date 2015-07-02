/* Setbits function */
#include <stdio.h>

unsigned setbits(unsigned, int, int, unsigned);
unsigned getbits(unsigned, int, int);

int main()
{
	unsigned x = 2, y = 9;

	printf("%u", setbits(x, 3, 4, y));
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	/* Modifies 'x' rolling it 'n' number of times to the left
	 * and adding 'n' bits from the rightmost part of 'y' starting
	 * at position 'p'.
	 */
	unsigned bits;
	bits = getbits(y, p, n);
	return ~(~x << n) & ~(~(~0 << n) & ~bits);
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
