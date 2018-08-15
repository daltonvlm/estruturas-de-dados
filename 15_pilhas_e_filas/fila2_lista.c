#include "fila2.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
	float info;
	No *ant;
	No *prox;
};

struct fila2 {
	No *ini;
	No *fim;
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

Fila2 *fila2_cria(void)
{
	Fila2 *f = (Fila2 *) aloca(sizeof(Fila2));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila2_insere_ini(Fila2 * f, float v)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = v;
	novo->ant = NULL;
	novo->prox = f->ini;
	if (f->ini) {
		f->ini->ant = novo;
	} else {
		f->fim = novo;
	}
	f->ini = novo;
}

void fila2_insere_fim(Fila2 * f, float v)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = v;
	novo->prox = NULL;
	novo->ant = f->fim;
	if (f->fim) {
		f->fim->prox = novo;
	} else {
		f->ini = novo;
	}
	f->fim = novo;
}

float fila2_retira_ini(Fila2 * f)
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
	} else {
		f->ini->ant = NULL;
	}
	free(t);
	return v;
}

float fila2_retira_fim(Fila2 * f)
{
	if (!f->ini) {
		fprintf(stderr, "Erro: fila vazia\n");
		exit(EXIT_FAILURE);
	}
	No *t = f->fim;
	float v = t->info;
	f->fim = t->ant;
	if (!f->fim) {
		f->ini = NULL;
	} else {
		f->fim->prox = NULL;
	}
	free(t);
	return v;
}

int fila2_vazia(Fila2 * f)
{
	return !f->ini;
}

void fila2_libera(Fila2 * f)
{
	while (f->ini) {
		No *t = f->ini;
		f->ini = t->prox;
		free(t);
	}
	free(f);
}
