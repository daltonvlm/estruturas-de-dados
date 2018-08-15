/*
 * Implemente uma função que receba uma string como parâmetro e substitua as
 * ocorrências de uma letra pelo seu oposto no alfabeto, isto é, a <-> z, b <-> y, c <-> x
 * etc. Caracteres que não forem letras devem permanecer inalterados. Essa função
 * deve obedecer ao protótipo:
 *
 *      void string_oposta (char* str);
 */

#include<stdio.h>

void string_oposta(char *str)
{
	while (*str) {
		if ('a' <= *str && *str <= 'z') {
			*str = 'a' + 'z' - *str;
		} else if ('A' <= *str && *str <= 'Z') {
			*str = 'A' + 'Z' - *str;
		}
		str++;
	}
}

int main(void)
{
	while (1) {
		char str[81];
		scanf(" %80[^\n]", str);
		string_oposta(str);
		puts(str);
	}
	return 0;
}
