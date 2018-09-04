#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

static int eh_operador(char c)
{
	return '+' == c || '-' == c || '*' == c || '/' == c || '#' == c
	    || '^' == c;
}

int main(void)
{
	Calc *calc = calc_cria("%.2f\n");
	char op;
	float v;
	while (1) {
		scanf(" %c", &op);
		if (eh_operador(op)) {
			calc_operador(calc, op);
		} else if ('q' == op) {
			break;
		} else {
			ungetc(op, stdin);
			if (1 == scanf("%f", &v)) {
				calc_operando(calc, v);
			} else {
				fprintf(stderr, "Erro na leitura.\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	calc_libera(calc);
	return 0;
}
