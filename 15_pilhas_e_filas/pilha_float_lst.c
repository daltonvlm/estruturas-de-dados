#include <stdio.h>
#include <stdlib.h>
#include "pilha_float.h"

typedef struct listano ListaNo;
struct listano {
	float info;
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

void pilha_push(Pilha * p, float info)
{
	ListaNo *novo = (ListaNo *) aloca(sizeof(ListaNo));
	novo->info = info;
	novo->prox = p->topo;
	p->topo = novo;
}

float pilha_pop(Pilha * p)
{
	if (!p->topo) {
		fprintf(stderr, "Erro: pilha vazia.\n");
		exit(EXIT_FAILURE);
	}
	ListaNo *topo = p->topo;
	float info = topo->info;
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
		free(t);
	}
	free(p);
}

void pilha_imprime(Pilha * p)
{
	for (ListaNo * topo = p->topo; topo; topo = topo->prox) {
		printf("%.2f\n", topo->info);
	}
}
