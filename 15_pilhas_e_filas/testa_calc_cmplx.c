#include <stdio.h>
#include <stdlib.h>
#include "calc_cmplx.h"

int operador(char c)
{
	return '+' == c || '-' == c || '*' == c || '/' == c;
}

int main(void)
{
	Calc *c = calc_cria();
	while (1) {
		float a, b;
		char op;
		scanf(" %c", &op);
		if (operador(op)) {
			calc_operador(c, op);
		} else if ('q' == op) {
			break;
		} else {
			ungetc(op, stdin);
			if (scanf("(%f,%f)", &a, &b) != 2) {
				fprintf(stderr, "Entrada invalida.\n");
				exit(EXIT_FAILURE);
			} else {
				calc_operando(c, a, b);
			}
		}
	}
	calc_libera(c);
	return 0;
}
