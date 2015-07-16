#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100	/* Maximum size of operand or operator */
#define NUMBER '0' /* Signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF)
	{
		switch(type)
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
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

/*--------Push & Pop--------*/

#define MAXVAL 100 /* Maximum depth of 'val' stack */

int sp = 0;	/* Next free stack position */
double val[MAXVAL];	/* Value stack */

/* push: push 'f' onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else 
		printf("Error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
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

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '-')
		return c;	/* Not a number */
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
	if(isdigit(c))	/* Collect interger part */
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')	/* Collect function part */
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

/*--------Getch & Ungetch--------*/

#define BUFSIZE 100

char buf[BUFSIZE];	/* Buffer for ungetch */
int bufp = 0;	/* Next free position in buf */

int getch(void) /* Get a (possibly pushed-back) character back on input */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* Push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("Ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
