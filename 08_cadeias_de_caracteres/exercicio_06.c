/*
 * Implemente uma função que receba uma string como parâmetro e desloque os seus
 * caracteres uma posição para a direita. Por exemplo a string "casa" seria alterada
 * para "acas". Repare que o último caractere vai para o início da string. Essa função
 * deve obedecer ao protótipo:
 *
 *      void roda_string (char* str);
 */

#include<stdio.h>
#include<string.h>

void roda_string(char *str)
{
	char c = *str;
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		int p = (i + 1) % n;
		char t = str[p];
		str[p] = c;
		c = t;
	}
}

int main(void)
{
	while (1) {
		char str[81];
		scanf(" %80[^\n]", str);
		roda_string(str);
		puts(str);
	}
	return 0;
}
