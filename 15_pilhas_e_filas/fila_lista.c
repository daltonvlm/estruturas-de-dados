#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
	float info;
	No *prox;
};

struct fila {
	No *ini;
	No *fim;
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

Fila *fila_cria(void)
{
	Fila *f = (Fila *) aloca(sizeof(Fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila_insere(Fila * f, float v)
{
	No *no = (No *) aloca(sizeof(No));
	no->info = v;
	no->prox = NULL;

	if (f->fim) {
		f->fim->prox = no;
	} else {
		f->ini = no;
	}
	f->fim = no;
}

float fila_retira(Fila * f)
{
	if (!f->ini) {
		fprintf(stderr, "Erro: fila vazia\n");
		exit(EXIT_FAILURE);
	}
	No *t = f->ini;
	float v = t->info;

	f->ini = t->prox;
	if (!f->ini) {
		f->fim = NULL;
	}

	free(t);
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
	No *t = f->ini;
	while (t) {
		printf("%f\n", t->info);
		t = t->prox;
	}
}
