#include "calc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"

struct calc {
	char f[21];
	Pilha *p;
};

static void *aloca(int n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

Calc *calc_cria(char *f)
{
	Calc *c = (Calc *) aloca(sizeof(Calc));

	strcpy(c->f, f);
	c->p = pilha_cria();
	return c;
}

void calc_operando(Calc * c, float v)
{
	pilha_push(c->p, v);
	printf(c->f, v);
}

void calc_operador(Calc * c, char op)
{
	float v2 = pilha_vazia(c->p) ? 0.f : pilha_pop(c->p);
	float v1 = pilha_vazia(c->p) ? 0.f : pilha_pop(c->p);
	float r = 0.f;

	switch (op) {
	case '+':
		r = v1 + v2;
		break;
	case '-':
		r = v1 - v2;
		break;
	case '*':
		r = v1 * v2;
		break;
	case '/':
		r = v1 / v2;
		break;
	case '#':
		r = sqrt(v2);
		break;
	case '^':
		r = pow(v1, v2);
	}
	pilha_push(c->p, r);
	printf(c->f, r);
}

void calc_libera(Calc * c)
{
	pilha_libera(c->p);
	free(c);
}
