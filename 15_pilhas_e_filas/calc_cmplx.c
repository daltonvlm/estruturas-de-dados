#include <stdio.h>
#include <stdlib.h>
#include "calc_cmplx.h"
#include "pilha_cmplx.h"
#include "complexo.h"

struct calc {
	Pilha *p;
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

Calc *calc_cria(void)
{
	Calc *calc = (Calc *) aloca(sizeof(Calc));
	calc->p = pilha_cria();
	return calc;
}

void calc_operando(Calc * c, float a, float b)
{
	Complexo *info = cmplx_cria(a, b);
	pilha_push(c->p, info);
	cmplx_imprime(info);
}

void calc_operador(Calc * c, char op)
{
	Complexo *info2 =
	    pilha_vazia(c->p) ? cmplx_cria(0, 0) : pilha_pop(c->p);
	Complexo *info1 =
	    pilha_vazia(c->p) ? cmplx_cria(0, 0) : pilha_pop(c->p);
	Complexo *info;

	switch (op) {
	case '+':
		info = cmplx_soma(info1, info2);
		break;
	case '-':
		info = cmplx_subtrai(info1, info2);
		break;
	case '*':
		info = cmplx_multiplica(info1, info2);
		break;
	case '/':
		info = cmplx_divide(info1, info2);
		break;
	default:
		fprintf(stderr, "Erro: operador invalido.\n");
		exit(EXIT_FAILURE);
	}
	cmplx_libera(info1);
	cmplx_libera(info2);
	pilha_push(c->p, info);
	cmplx_imprime(info);
}

void calc_libera(Calc * c)
{
	pilha_libera(c->p);
	free(c);
}
