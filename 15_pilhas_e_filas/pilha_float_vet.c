#include <stdio.h>
#include <stdlib.h>
#include "pilha_float.h"

struct pilha {
	int n;
	int dim;
	float *v;
};

static void check(void *p)
{
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

Pilha *pilha_cria(void)
{
	Pilha *p = (Pilha *) aloca(sizeof(Pilha));
	p->n = 0;
	p->dim = 2;
	p->v = (float *)aloca(p->dim * sizeof(float));
	return p;
}

void pilha_push(Pilha * p, float info)
{
	if (p->n == p->dim) {
		p->dim *= 2;
		p->v = realloc(p->v, p->dim * sizeof(float));
		check(p->v);
	}
	p->v[p->n++] = info;
}

float pilha_pop(Pilha * p)
{
	if (!p->n) {
		fprintf(stderr, "Erro: pilha vazia.\n");
		exit(EXIT_FAILURE);
	}
	return p->v[--p->n];
}

int pilha_vazia(Pilha * p)
{
	return !p->n;
}

void pilha_libera(Pilha * p)
{
	free(p->v);
	free(p);
}

void pilha_imprime(Pilha * p)
{
	for (int i = p->n - 1; i >= 0; i--) {
		printf("%.2f\n", p->v[i]);
	}
}
