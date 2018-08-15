/*
 * Implemente uma função que receba uma string como parâmetro e altere nessa
 * string as ocorrências de caracteres maiúsculos para minúsculos. Essa função deve
 * obedecer ao protótipo:
 *
 *      void minusculo (char* str);
 */

#include<stdio.h>

void minusculo(char *str)
{
	while (*str) {
		if ('A' <= *str && *str <= 'Z') {
			*str = 'a' + *str - 'A';
		}
		str++;
	}
}

int main(void)
{
	while (1) {
		char str[81];
		scanf(" %80[^\n]", str);
		minusculo(str);
		puts(str);
	}
	return 0;
}
