#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_float.h"

#define DIM 4

struct fila {
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

Fila *fila_cria(void)
{
	Fila *f = (Fila *) aloca(sizeof(Fila));
	f->n = 0;
	f->dim = DIM;
	f->ini = 0;
	f->v = (float *)aloca(f->dim * sizeof(float));
	return f;
}

void fila_insere(Fila * f, float v)
{
	if (f->n == f->dim) {
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
	int fim = (f->ini + f->n) % f->dim;
	f->v[fim] = v;
	f->n++;
}

float fila_retira(Fila * f)
{
	if (fila_vazia(f)) {
		fprintf(stderr, "Erro: fila vazia.\n");
		exit(EXIT_FAILURE);
	}
	float v = f->v[f->ini];
	f->ini = (f->ini + 1) % f->dim;
	f->n--;
	return v;
}

int fila_vazia(Fila * f)
{
	return !f->n;
}

void fila_libera(Fila * f)
{
	free(f->v);
	free(f);
}

void fila_imprime(Fila * f)
{
	for (int i = 0; i < f->n; i++) {
		printf("%.2f\n", f->v[(f->ini + i) % f->dim]);
	}
}
