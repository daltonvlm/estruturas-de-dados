#include "calc_cmplx.h"

#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"
#include "pilha_cmplx.h"

struct calc {
	Pilha *p;
};

Calc *calc_cria(void)
{
	Calc *c = (Calc *) malloc(sizeof(Calc));
	if (!c) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	c->p = pilha_cria();
	return c;
}

void calc_operando(Calc * c, float a, float b)
{
	Complexo *cmplx = cmplx_cria(a, b);
	pilha_push(c->p, cmplx);
	cmplx_imprime(cmplx);
}

void calc_operador(Calc * c, char op)
{
	Complexo *cmplx2 = pilha_vazia(c->p) ?
	    cmplx_cria(0, 0) : pilha_pop(c->p);

	Complexo *cmplx1 = pilha_vazia(c->p) ?
	    cmplx_cria(0, 0) : pilha_pop(c->p);

	Complexo *r;

	switch (op) {
	case '+':
		r = cmplx_soma(cmplx1, cmplx2);
		break;
	case '-':
		r = cmplx_subtrai(cmplx1, cmplx2);
		break;
	case '*':
		r = cmplx_multiplica(cmplx1, cmplx2);
		break;
	case '/':
		r = cmplx_divide(cmplx1, cmplx2);
	}

	cmplx_libera(cmplx1);
	cmplx_libera(cmplx2);
	cmplx_imprime(r);
	pilha_push(c->p, r);
}

void calc_libera(Calc * c)
{
	pilha_libera(c->p);
	free(c);
}
