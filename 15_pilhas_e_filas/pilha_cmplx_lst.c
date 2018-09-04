#include <stdio.h>
#include <stdlib.h>
#include "pilha_cmplx.h"
#include "complexo.h"

typedef struct no No;
struct no {
	Complexo *info;
	No *prox;
};

struct pilha {
	No *topo;
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

Pilha *pilha_cria(void)
{
	Pilha *p = (Pilha *) aloca(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

void pilha_push(Pilha * p, Complexo * info)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = info;
	novo->prox = p->topo;
	p->topo = novo;
}

Complexo *pilha_pop(Pilha * p)
{
	if (pilha_vazia(p)) {
		fprintf(stderr, "Erro: pilha vazia.\n");
		exit(EXIT_FAILURE);
	}
	No *topo = p->topo;
	Complexo *info = topo->info;
	p->topo = topo->prox;
	free(topo);
	return info;
}

int pilha_vazia(Pilha * p)
{
	return !p->topo;
}

void pilha_libera(Pilha * p)
{
	while (p->topo) {
		No *t = p->topo;
		p->topo = t->prox;
		cmplx_libera(t->info);
		free(t);
	}
	free(p);
}

void pilha_imprime(Pilha * p)
{
	for (No * topo = p->topo; topo; topo = topo->prox) {
		cmplx_imprime(topo->info);
	}
}
