/*
 * Implemente uma função que receba uma string como parâmetro e retorne como
 * resultado o número de vogais nessa string. Essa função deve obedecer ao protótipo:
 *
 *      int conta_vogais (char* str);
 */

#include<stdio.h>

int conta_vogais(char *str)
{
	int n = 0;
	while (*str) {
		if ('a' == *str || 'e' == *str || 'i' == *str || 'o' == *str
		    || 'u' == *str) {
			n++;
		}
		str++;
	}
	return n;
}

int main(void)
{
	while (1) {
		char str[81];
		scanf(" %80[^\n]", str);
		printf("%d\n", conta_vogais(str));
	}
	return 0;
}
