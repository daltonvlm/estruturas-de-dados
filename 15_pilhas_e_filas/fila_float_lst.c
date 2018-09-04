#include <stdio.h>
#include <stdlib.h>
#include "fila_float.h"

typedef struct no No;
struct no {
	float info;
	No *prox;
};

struct fila {
	No *ini;
	No *fim;
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

Fila *fila_cria(void)
{
	Fila *f = (Fila *) aloca(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere(Fila * f, float v)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = v;
	novo->prox = NULL;
	if (!f->ini) {
		f->ini = novo;
	} else {
		f->fim->prox = novo;
	}
	f->fim = novo;
}

float fila_retira(Fila * f)
{
	if (!f->ini) {
		fprintf(stderr, "Erro: fila vazia.\n");
		exit(EXIT_FAILURE);
	}
	No *prim = f->ini;
	float v = prim->info;
	f->ini = prim->prox;
	if (!f->ini) {
		f->fim = NULL;
	}
	free(prim);
	return v;
}

int fila_vazia(Fila * f)
{
	return !f->ini;
}

void fila_libera(Fila * f)
{
	while (f->ini) {
		No *t = f->ini;
		f->ini = t->prox;
		free(t);
	}
	free(f);
}

void fila_imprime(Fila * f)
{
	for (No * prim = f->ini; prim; prim = prim->prox) {
		printf("%.2f\n", prim->info);
	}
}
