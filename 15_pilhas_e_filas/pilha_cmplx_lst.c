#include <stdio.h>
#include <stdlib.h>
#include "pilha_cmplx.h"
#include "complexo.h"

typedef struct listano ListaNo;
struct listano {
	Complexo *info;
	ListaNo *prox;
};

struct pilha {
	ListaNo *topo;
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
	ListaNo *novo = (ListaNo *) aloca(sizeof(ListaNo));
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
	ListaNo *topo = p->topo;
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
		ListaNo *t = p->topo;
		p->topo = t->prox;
		cmplx_libera(t->info);
		free(t);
	}
	free(p);
}

void pilha_imprime(Pilha * p)
{
	for (ListaNo * topo = p->topo; topo; topo = topo->prox) {
		cmplx_imprime(topo->info);
	}
}
