#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define MAXVAL 100
#define NUMBER '0'

int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);

int main()
{
	int com; /* Command introduced */
	int i;
	double op2;
	char s[MAX];

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
				printf("\t%.8g\n", pop());
				break;
			case 'p':
				for(i = 0; i < sp; i++)
					printf("\t%g\t", val[i]);
				printf("\n");
				break;
			default:
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
		printf("Error: stack empty\n");
		return 0.0;
	}
}

/*--------Getop section----------*/

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if(c == '-')
	{
		if(!isdigit(c = getch()) && c != '.')
			return '-';
		else
		{
			s[0] = '-';
			ungetch(c);	
			if(isdigit(c))	
				while(isdigit(s[++i] = c = getch()))
					;
			if(c == '.')
				while(isdigit(s[++i] = c = getch()))
					;
		}
	}
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

/*--------Getch & Ungetch--------*/

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("Ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
