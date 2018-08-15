/*
 * Implemente uma função que receba como parâmetros uma cadeia de caracteres
 * (string) e um caractere c, e retorne o número de ocorrências do caractere dentro da
 * cadeia. Por exemplo, se forem passados para a função a cadeia "Rio de Janeiro"
 * e o caractere 'i', a função deve retornar o valor 2. A função deve obedecer ao
 * protótipo a seguir.
 *
 *      int conta_ocorrencias (char* s, char c);
 */

#include<stdio.h>

int conta_ocorrencias(char *s, char c)
{
	int n = 0;
	while (*s) {
		if (*s == c) {
			n++;
		}
		s++;
	}
	return n;
}

int main(void)
{
	while (1) {
		char c, s[81];
		int n;
		scanf(" %80[^\n]", s);
		scanf(" %c", &c);
		n = conta_ocorrencias(s, c);
		printf("%d\n", n);
	}
	return 0;
}
