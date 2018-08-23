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
	char *r = (char *)malloc(strlen(s1) + strlen(s2) + 1);
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
	char *s, s1[81], s2[81];
	char sep;
	while (1) {
		printf("Texto 1: ");
		scanf(" %80[^\n]", s1);
		printf("Texto 2: ");
		scanf(" %80[^\n]", s2);
		printf("Separador: ");
		scanf(" %c", &sep);
		s = concatena(s1, s2, sep);
		if (s) {
			puts(s);
			free(s);
		}
	}
	return 0;
}
