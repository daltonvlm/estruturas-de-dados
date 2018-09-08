#include <stdio.h>
#include <stdlib.h>
#include "fila_float.h"

typedef struct listano ListaNo;
struct listano {
	float info;
	ListaNo *prox;
};

struct fila {
	ListaNo *ini;
	ListaNo *fim;
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
	ListaNo *p = (ListaNo *) aloca(sizeof(ListaNo));
	p->info = v;
	p->prox = NULL;
	if (!f->ini) {
		f->ini = p;
	} else {
		f->fim->prox = p;
	}
	f->fim = p;
}

float fila_retira(Fila * f)
{
	if (!f->ini) {
		fprintf(stderr, "Erro: fila vazia.\n");
		exit(EXIT_FAILURE);
	}
	ListaNo *prim = f->ini;
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
		ListaNo *t = f->ini;
		f->ini = t->prox;
		free(t);
	}
	free(f);
}

void fila_imprime(Fila * f)
{
	for (ListaNo * prim = f->ini; prim; prim = prim->prox) {
		printf("%.2f\n", prim->info);
	}
}
