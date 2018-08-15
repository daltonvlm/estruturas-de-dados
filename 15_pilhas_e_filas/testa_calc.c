#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

static int operador(char c)
{
	return '+' == c || '-' == c || '*' == c || '/' == c || '#' == c
	    || '^' == c;
}

int main(void)
{
	Calc *calc = calc_cria("%.2f\n");
	while (1) {
		char c;
		scanf(" %c", &c);
		if ('q' == c) {
			break;
		}
		if (!operador(c)) {
			float v;
			ungetc(c, stdin);
			if (scanf("%f", &v) != 1) {
				fprintf(stderr, "Erro na leitura\n");
				exit(EXIT_FAILURE);
			}
			calc_operando(calc, v);
		} else {
			calc_operador(calc, c);
		}
	}
	calc_libera(calc);
	return 0;
}
