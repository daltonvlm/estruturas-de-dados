#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#include "pilha_float.h"

struct calc {
	char *fmt;
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

Calc *calc_cria(char *fmt)
{
	Calc *c = (Calc *) aloca(sizeof(Calc));
	c->fmt = fmt;
	c->p = pilha_cria();
	return c;
}

void calc_operando(Calc * c, float v)
{
	pilha_push(c->p, v);
	printf(c->fmt, v);
}

void calc_operador(Calc * c, char op)
{
	float v2 = pilha_vazia(c->p) ? 0 : pilha_pop(c->p);
	float v1 = pilha_vazia(c->p) ? 0 : pilha_pop(c->p);
	float v;
	switch (op) {
	case '+':
		v = v1 + v2;
		break;
	case '-':
		v = v1 - v2;
		break;
	case '*':
		v = v1 * v2;
		break;
	case '/':
		v = v1 / v2;
		break;
	case '#':
		v = sqrtf(v2);
		pilha_push(c->p, v1);
		break;
	case '^':
		v = powf(v1, v2);
		break;
	default:
		fprintf(stderr, "Erro: operador '%c' invalido.\n", op);
		exit(EXIT_FAILURE);
	}
	calc_operando(c, v);
}

void calc_libera(Calc * c)
{
	pilha_libera(c->p);
	free(c);
}
