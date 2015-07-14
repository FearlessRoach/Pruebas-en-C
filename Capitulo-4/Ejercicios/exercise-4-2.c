/* Version of atof function. Handling scientific notation */
#include <stdio.h>
#include <string.h>
#include <math.h>

double atof2(char s[]);

int main()
{
	printf("%f\n", atof2("-1.921e3")*2);
	printf("%f", -1.921e-1*2);
	return 0;
}

/* atof2: casts a string into a floating number (even scientific notation) */
double atof2(char s[])
{
	double val, power, exp;
	int i, sign, signe;

	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0*val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++, power *= 10)
		val = 10.0*val + (s[i] - '0');
	if(s[i] == 'e')
		i++;
	signe = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(exp = 0.0; isdigit(s[i]); i++)
		exp = 10.0*exp + (s[i] - '0');
	return (sign * val / power) * pow(10, signe*exp);
}
