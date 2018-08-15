/*
 * Implemente uma função que receba uma string como parâmetro e substitua todas as
 * letras por suas sucessoras no alfabeto. Por exemplo, a string "Casa" seria alterada
 * para "Dbtb". A letra z deve ser substituida pela letra a (e Z por A). Caracteres
 * que não forem letras devem permanecer inalterados. Essa função deve obedecer ao
 * protótipo:
 *
 *      void shift_string (char* str);
 */

#include<stdio.h>

void shift_string(char *str)
{
	while (*str) {
		if ('a' <= *str && *str <= 'z') {
			*str = 'a' + (*str - 'a' + 1) % ('z' - 'a' + 1);
		} else if ('A' <= *str && *str <= 'Z') {
			*str = 'A' + (*str - 'A' + 1) % ('z' - 'a' + 1);
		}
		str++;
	}
}

int main(void)
{
	while (1) {
		char str[81];
		scanf(" %80[^\n]", str);
		shift_string(str);
		puts(str);
	}
	return 0;
}
