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
	int len = strlen(s);
	char *r = (char *)malloc((len - n) + 1);

	if (r) {
		int i;
		for (i = 0; i < len - n; i++) {
			r[i] = s[i];
		}
		r[i] = '\0';
	}
	return r;
}

int main(void)
{
	while (1) {
		int n;
		char str[81], *r;

		scanf(" %80[^\n]", str);
		scanf("%d", &n);

		r = retira_sufixo(str, n);
		if (r) {
			puts(r);
			free(r);
		}
	}
	return 0;
}
