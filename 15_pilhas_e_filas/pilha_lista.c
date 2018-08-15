#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
	float info;
	No *prox;
};

struct pilha {
	No *prim;
};

void *aloca(int n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

Pilha *pilha_cria(void)
{
	Pilha *p = (Pilha *) aloca(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void pilha_push(Pilha * p, float v)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = v;
	novo->prox = p->prim;
	p->prim = novo;
}

float pilha_pop(Pilha * p)
{
	if (!p->prim) {
		fprintf(stderr,
			"Erro: tentativa de retirar elemento de pilha vazia\n");
		exit(EXIT_FAILURE);
	}
	No *no = p->prim;
	float v = no->info;

	p->prim = no->prox;
	free(no);
	return v;
}

int pilha_vazia(Pilha * p)
{
	return !p->prim;
}

void pilha_libera(Pilha * p)
{
	while (p->prim) {
		No *t = p->prim;
		p->prim = t->prox;
		free(t);
	}
	free(p);
}

void pilha_imprime(Pilha * p)
{
	No *t = p->prim;
	while (t) {
		printf("%f\n", t->info);
		t = t->prox;
	}
}
