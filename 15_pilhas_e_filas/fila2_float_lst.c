#include <stdio.h>
#include <stdlib.h>
#include "fila2_float.h"

#define ERR_MSG "Erro: fila vazia."

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

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

Fila2 *fila2_cria(void)
{
	Fila2 *f = (Fila2 *) aloca(sizeof(Fila2));
	f->ini = f->fim = NULL;
	return f;
}

static No *cria_no(float info)
{
	No *novo = (No *) aloca(sizeof(No));
	novo->info = info;
	novo->ant = novo->prox = NULL;
	return novo;
}

void fila2_insere_ini(Fila2 * f, float v)
{
	No *novo = cria_no(v);
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
	No *novo = cria_no(v);
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
	if (fila2_vazia(f)) {
		fprintf(stderr, "%s\n", ERR_MSG);
		exit(EXIT_FAILURE);
	}
	No *prim = f->ini;
	float v = prim->info;
	f->ini = prim->prox;
	free(prim);
	if (f->ini) {
		f->ini->ant = NULL;
	} else {
		f->fim = NULL;
	}
	return v;
}

float fila2_retira_fim(Fila2 * f)
{
	if (fila2_vazia(f)) {
		fprintf(stderr, "%s\n", ERR_MSG);
		exit(EXIT_FAILURE);
	}
	No *ult = f->fim;
	float v = ult->info;
	f->fim = ult->ant;
	free(ult);
	if (f->fim) {
		f->fim->prox = NULL;
	} else {
		f->ini = NULL;
	}
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

void fila2_imprime(Fila2 * f)
{
	for (No * prim = f->ini; prim; prim = prim->prox) {
		printf("%f\n", prim->info);
	}
}
