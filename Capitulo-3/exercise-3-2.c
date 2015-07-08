#include <stdio.h>

void escape(char to[], char from[]);
void unescape(char to[], char from[]);

int main()
{
	char f[100] = "hola, prueba\tde caracteres \rde escape\n, veamos\t\t\0";
	char to[100];

	escape(to, f);
	printf("%s\n\n%s", f, to);
	unescape(f, to);
	printf("\n\n%s", f);
	return 0;
}

/* Transforms escape characters into printable chars i.e., '\t', '\n' */
void escape(char to[], char from[])
{
	int i, j;

	for(i = j = 0; from[i] != '\0'; i++)
		switch(from[i])
		{
			case '\n':
				to[j++] = '\\';
				to[j++] = 'n';
				break;
			case '\t':
				to[j++] = '\\';
				to[j++] = 't';
				break;
			case '\r':
				to[j++] = '\\';
				to[j++] = 'r';
				break;
			default:
				to[j++] = from[i];
				break;
		}
	to[j] = '\0';
}

/* Converts printable escape chars into their escape form */
void unescape(char to[], char from[])
{
	int i, j;

	for(i = j = 0; from[i] != '\0'; i++)
		switch(from[i])
		{
			case '\\':
				switch(from[++i])
				{
					case 'n':
						to[j++] = '\n';
						break;
					case 't':
						to[j++] = '\t';
						break;
					case 'r':
						to[j++] = '\r';
						break;
					default:
						to[j++] = from[i-1];
						to[j++] = from[i];
						break;
				}
				break;
			default:
				to[j++] = from[i];
				break;
		}
	to[j] = '\0';
}
