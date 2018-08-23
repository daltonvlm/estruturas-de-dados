/*
 * Implemente uma função que receba como parâmetros uma cadeia de caracteres
 * (string) e um número inteiro n, e retorne uma nova cadeia, alocada dinamicamente
 * dentro da função, que represente a cadeia original sem os últimos n caracteres. Por
 * exemplo, se forem passados para a função a cadeia "Rio de Janeiro" e o número
 * 4, a função deve retonar a cadeia "Rio de Jan". A função deve obedecer ao
 * protótipo a seguir.
 *
 *      char* retira_sufixo (char* s, int n);
 *
 * Assuma que a cadeia original terá sempre mais do que n caracteres.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *retira_sufixo(char *s, int n)
{
	int len = strlen(s) - n;
	char *r = (char *)malloc(len + 1);
	if (r) {
		r[len] = '\0';
		for (int i = 0; i < len; i++) {
			r[i] = s[i];
		}
	}
	return r;
}

int main(void)
{
	int n;
	char str[81], *r;
	while (1) {
		printf("Texto: ");
		scanf(" %80[^\n]", str);
		printf("Quantidade: ");
		scanf("%d", &n);
		r = retira_sufixo(str, n);
		if (r) {
			puts(r);
			free(r);
		}
	}
	return 0;
}
