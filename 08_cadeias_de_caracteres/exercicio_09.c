/*
 * Escreva uma função que receba como parâmetros duas strings e um caractere sepa-
 * rador. A função deve criar a string que representa a concatenação das duas strings
 * de entrada, usando o caractere como separador. Por exemplo, se forem passadas
 * as strings "ex" e "aluno", e o caractere hífen '-', deve-se ter como valor de retorno
 * a string "ex-aluno". O protótipo da função deve ser:
 *
 *      char* concatena (char* s1, char* s2, char sep);
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *concatena(char *s1, char *s2, char sep)
{
	char *r = (char *)malloc(strlen(s1) + strlen(s2) + 2);
	if (r) {
		char *t = r;
		while (*t++ = *s1++) ;
		*(t - 1) = sep;
		while (*t++ = *s2++) ;
	}
	return r;
}

int main(void)
{
	while (1) {
		char sep, str1[81], str2[81], *r;

		scanf(" %80[^\n]", str1);
		scanf(" %80[^\n]", str2);
		scanf(" %c", &sep);

		r = concatena(str1, str2, sep);
		if (r) {
			puts(r);
			free(r);
		}
	}
	return 0;
}
