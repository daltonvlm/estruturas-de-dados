#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila2_float.h"

#define DIM 4
#define ERR_MSG "Erro: fila vazia."

struct fila2 {
	int n;
	int dim;
	int ini;
	float *v;
};

static void check(void *p)
{
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

Fila2 *fila2_cria(void)
{
	Fila2 *f = (Fila2 *) aloca(sizeof(Fila2));
	f->n = 0;
	f->dim = DIM;
	f->ini = 0;
	f->v = (float *)aloca(f->dim * sizeof(float));
	return f;
}

static void redimensiona(Fila2 * f)
{
	f->dim *= 2;
	f->v = (float *)realloc(f->v, f->dim * sizeof(float));
	check(f->v);
	if (f->ini) {
		int nelem = f->n - f->ini;
		int src = f->ini;
		int dest = f->dim - nelem;
		memmove(f->v + dest, f->v + src, nelem * sizeof(float));
		f->ini = dest;
	}
}

void fila2_insere_ini(Fila2 * f, float v)
{
	if (f->n == f->dim) {
		redimensiona(f);
	}
	f->ini = (f->dim + (f->ini - 1)) % f->dim;
	f->v[f->ini] = v;
	f->n++;
}

void fila2_insere_fim(Fila2 * f, float v)
{
	if (f->n == f->dim) {
		redimensiona(f);
	}
	int fim = (f->ini + f->n) % f->dim;
	f->v[fim] = v;
	f->n++;
}

float fila2_retira_ini(Fila2 * f)
{
	if (fila2_vazia(f)) {
		fprintf(stderr, "%s\n", ERR_MSG);
		exit(EXIT_FAILURE);
	}
	float v = f->v[f->ini];
	f->ini = (f->ini + 1) % f->dim;
	f->n--;
	return v;
}

float fila2_retira_fim(Fila2 * f)
{
	if (fila2_vazia(f)) {
		fprintf(stderr, "%s\n", ERR_MSG);
		exit(EXIT_FAILURE);
	}
	float v = f->v[(f->ini + f->n - 1) % f->dim];
	f->n--;
	return v;
}

int fila2_vazia(Fila2 * f)
{
	return !f->n;
}

void fila2_libera(Fila2 * f)
{
	free(f->v);
	free(f);
}

void fila2_imprime(Fila2 * f)
{
	for (int i = 0; i < f->n; i++) {
		printf("%f\n", f->v[(f->ini + i) % f->dim]);
	}
}
