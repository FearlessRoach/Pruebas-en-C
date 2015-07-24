#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXVAL 100
#define NUMBER '0'
#define VAR 10

int sp = 0;
double val[MAXVAL];
double var[VAR];

int getop(char []);
void push(double);
double pop(void);

int main()
{
	int com; /* Command introduced */
	int i, v = 0;
	double op2, op3;
	char s[MAXVAL];
	
	for(i = 0; i < VAR; i++)
		var[i] = 0;
	while((com = getop(s)) != EOF)
	{
		switch(com)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case '\n':
				if(sp > 0)
				{
					printf("\t%.8g\n", op2 = pop());
					push(op2);
				}
				else
					printf("\t%.8g\n", pop());
				break;
			case 'P': /* Prints all elements of the stack */
				for(i = 0; i < sp; i++)
					printf("\t%g", val[i]);
				printf("\n");
				break;
			case 'D': /* Duplicates entire stack */
				for(i = 0; i < sp; i++)
					push(val[i]);
				break;
			case '$': /* Swaps last to elements of stack */
				op2 = pop();
				op3 = pop();
				push(op2);
				push(op3);
				break;
			case 'r': /* Clears whole stack */
				for(i = sp-1; i >= 0; i--)
					pop();
				break;
			case 'S':
				push(sin(pop()));
				break;
			case 'C':
				push(cos(pop()));
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '~':
				push(sqrt(pop()));
				break;
			case 'L':
				push(log(pop()));
				break;
			case 'E':
				push(exp(pop()));
				break;
			case '=':
				var[v - 'a'] = pop();
				pop();
				break;
			default:
				if(com >= 'a' && com <= 'j')
				{
					push(var[com - 'a']);
					v = com;
				}
				else
					printf("Error: unknown command %s\n", s);
				break;	
		}
	}
}

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else 
		printf("Error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else 
	{
		printf("Stack empty\n");
		return 0.0;
	}
}

/*--------Getop section----------*/

#include <ctype.h>

#define LIM 1000

int getline2(char s[], int lim);

int i = 0;

int getop(char s[])
{
	int j, len;
	char str[LIM];
	
	j = 0;
	len = getline2(str, LIM);
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if(!isdigit(str[i]) && str[i] != '.' && str[i] != '-')
		return str[i];
	if(str[i] == '-')
	{
		if(!isdigit(str[i+1]) && str[i+1] != '.')
			return str[i];
		else
		{
			s[0] = '-';	
			if(isdigit(str[++i]))	
				while(isdigit(s[++j] = str[i++]))
					;
			if(str[i] == '.')
				while(isdigit(s[++j] = str[++i]))
					;
		}
	}
	if(isdigit(str[i]))
		while(isdigit(s[++j] = str[i++]))
			;
	if(str[i] == '.')
		while(isdigit(s[++j] = str[i++]))
			;
	if(str[i] == '\n')
		i = 0;
	s[j] = '\0';
	return NUMBER;
}

/*--------Getline--------*/

int getline2(char s[], int lim) /* Version 2.0 of the getline function */
{
	int c, j; 

	j = 0;
	while(j < lim-1)
	{
		if((c = getchar()) != '\n')
		{
			if(c != EOF)
				s[j] = c;
			else
				break;	/* Searching for a way to maket it work without break
							 * statement involve
							 */
		}
		else
			break;
		j++;
	}
	if(c == '\n')
	{
		s[j] = c;
		j++;
	}
	s[j] = '\0';
	return j;
}

