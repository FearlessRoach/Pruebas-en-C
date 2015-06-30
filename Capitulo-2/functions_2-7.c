/* In this code are written the functions introduced as examples
 * in section 2.7-Type Convertions.
 */
#include <stdio.h>

unsigned long int next = 1;

int atoi(char s[]);
int lower(int c);
int rand(void);
void srand(unsigned int s);

int main()
{
	int c, n;
	unsigned int num;
	char l[4] = "45";

	n = atoi(l);
	c = lower('D');
	num = rand();
	printf("%d -- %c\n", n, c);
	printf("%d -- %s\n", n*2, l);
	printf("%d", num);
	srand(num);
	return 0;
}

/* atoi: convert s to integer */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0'	 && s[i] <= '9'; ++i)
		n = 10*n + (s[i] - '0');
	return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

/* rand: return pseudo-random integer on  0..32767 */
int rand(void)
{
	next = next*1122948109 + 12345;
	return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed)
{
	next = seed;
}
