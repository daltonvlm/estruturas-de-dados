/*
 * Implemente uma função que receba uma string como parâmetro e retorne como
 * resultado o número de vogais nessa string. Essa função deve obedecer ao protótipo:
 *
 *      int conta_vogais (char* str);
 */

#include <stdio.h>

int conta_vogais(char *str)
{
	int n = 0;
	char c, v;
	char *p, *vogais = "aeiou";
	while (c = *str++) {
		p = vogais;
		while (v = *p++) {
			if (c == v) {
				n++;
				break;
			}
		}
	}
	return n;
}

int main(void)
{
	char s[81], msg[21];
	int n;
	while (1) {
		printf("Texto: ");
		scanf(" %80[^\n]", s);
		n = conta_vogais(s);
		sprintf(msg, "%d", n);
		printf("%s ocorrencia%s encontrada%s.\n",
		       n ? msg : "Nenhuma", n > 1 ? "s" : "", n > 1 ? "s" : "");
	}
	return 0;
}
