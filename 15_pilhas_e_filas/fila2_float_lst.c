#include <stdio.h>
#include <stdlib.h>
#include "fila2_float.h"

#define ERR_MSG "Erro: fila vazia."

typedef struct listano ListaNo;
struct listano {
	float info;
	ListaNo *ant;
	ListaNo *prox;
};

struct fila2 {
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

Fila2 *fila2_cria(void)
{
	Fila2 *f = (Fila2 *) aloca(sizeof(Fila2));
	f->ini = f->fim = NULL;
	return f;
}

static ListaNo *cria_no(float info)
{
	ListaNo *p = (ListaNo *) aloca(sizeof(ListaNo));
	p->info = info;
	p->ant = p->prox = NULL;
	return p;
}

void fila2_insere_ini(Fila2 * f, float v)
{
	ListaNo *p = cria_no(v);
	p->prox = f->ini;
	if (f->ini) {
		f->ini->ant = p;
	} else {
		f->fim = p;
	}
	f->ini = p;
}

void fila2_insere_fim(Fila2 * f, float v)
{
	ListaNo *p = cria_no(v);
	p->ant = f->fim;
	if (f->fim) {
		f->fim->prox = p;
	} else {
		f->ini = p;
	}
	f->fim = p;
}

float fila2_retira_ini(Fila2 * f)
{
	if (fila2_vazia(f)) {
		fprintf(stderr, "%s\n", ERR_MSG);
		exit(EXIT_FAILURE);
	}
	ListaNo *prim = f->ini;
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
	ListaNo *ult = f->fim;
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
		ListaNo *t = f->ini;
		f->ini = t->prox;
		free(t);
	}
	free(f);
}

void fila2_imprime(Fila2 * f)
{
	for (ListaNo * prim = f->ini; prim; prim = prim->prox) {
		printf("%f\n", prim->info);
	}
}
