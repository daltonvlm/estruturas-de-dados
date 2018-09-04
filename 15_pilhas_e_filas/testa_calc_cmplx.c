#include <stdio.h>
#include <stdlib.h>
#include "calc_cmplx.h"

static int eh_operador(char c)
{
	return '+' == c || '-' == c || '*' == c || '/' == c;
}

int main(void)
{
	char op;
	float a, b;
	Calc *calc = calc_cria();
	while (1) {
		scanf(" %c", &op);
		if ('q' == op) {
			break;
		}
		if (eh_operador(op)) {
			calc_operador(calc, op);
		} else {
			ungetc(op, stdin);
			if (2 == scanf("(%f,%f)", &a, &b)) {
				calc_operando(calc, a, b);
			} else {
				fprintf(stderr, "Erro: entrada invalida.\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	calc_libera(calc);
	return 0;
}
