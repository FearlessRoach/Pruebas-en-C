#include <stdio.h>

unsigned inverted(unsigned, int, int);
unsigned getbits(unsigned, int, int);

int main()
{
	printf("%d", 3 >> 2);
	return 0;
}

unsigned inverted(unsigned x, int p, int n)
{
	unsigned b;
	
	b = ~getbits(x, p, n);
	b = (b >> (x-p+1)) << (p+1-n);
	return; 
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
