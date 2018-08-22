/*
 * Implemente uma função que receba como parâmetros uma cadeia de caracteres
 * (string) e um caractere c, e retorne o número de ocorrências do caractere dentro da
 * cadeia. Por exemplo, se forem passados para a função a cadeia "Rio de Janeiro"
 * e o caractere 'i', a função deve retornar o valor 2. A função deve obedecer ao
 * protótipo a seguir.
 *
 *      int conta_ocorrencias (char* s, char c);
 */

#include <stdio.h>

int conta_ocorrencias(char *s, char c)
{
	int n = 0;
	char tmp;
	while (tmp = *s++) {
		if (c == tmp) {
			n++;
		}
	}
	return n;
}

int main(void)
{
	char s[81], msg[21];
	char c;
	int n;
	while (1) {
		printf("Texto: ");
		scanf(" %80[^\n]", s);
		printf("Busca: ");
		scanf(" %c", &c);
		n = conta_ocorrencias(s, c);
		sprintf(msg, "%d", n);
		printf("%s ocorrencia%s encontrada%s.\n",
		       n ? msg : "Nenhuma", n > 1 ? "s" : "", n > 1 ? "s" : "");
	}
	return 0;
}
