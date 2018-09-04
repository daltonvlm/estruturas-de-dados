#include <stdio.h>
#include <stdlib.h>
#include "pilha_cmplx.h"
#include "complexo.h"

struct pilha {
	int dim;
	int topo;
	Complexo **vet;
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
	return p;
}

Pilha *pilha_cria(void)
{
	Pilha *p = (Pilha *) aloca(sizeof(Pilha));
	p->dim = 4;
	p->topo = 0;
	p->vet = (Complexo **) aloca(p->dim * sizeof(Complexo *));
	return p;
}

void pilha_push(Pilha * p, Complexo * v)
{
	if (p->topo == p->dim) {
		p->dim *= 2;
		p->vet =
		    (Complexo **) realloc(p->vet, p->dim * sizeof(Complexo *));
		check(p->vet);
	}
	p->vet[p->topo++] = v;
}

Complexo *pilha_pop(Pilha * p)
{
	if (!p->topo) {
		fprintf(stderr, "Erro: pilha vazia\n");
		exit(EXIT_FAILURE);
	}
	return p->vet[--p->topo];
}

int pilha_vazia(Pilha * p)
{
	return !p->topo;
}

void pilha_libera(Pilha * p)
{
	while (!pilha_vazia(p)) {
		cmplx_libera(pilha_pop(p));
	}
	free(p->vet);
	free(p);
}

void pilha_imprime(Pilha * p)
{
	for (int i = 0; i < p->topo; i++) {
		cmplx_imprime(p->vet[i]);
	}
}
