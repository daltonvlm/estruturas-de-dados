#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct fila {
	int n;
	int ini;
	int dim;
	int *vet;
};

static void verifica(void *p)
{
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	verifica(p);
	return p;
}

Fila *fila_cria(void)
{
	Fila *f = (Fila *) aloca(sizeof(Fila));

	f->n = 0;
	f->ini = 0;
	f->dim = 4;
	f->vet = (int *)aloca(f->dim * sizeof(int));
	return f;
}

void fila_insere(Fila * f, int v)
{
	int fim;
	if (f->n == f->dim) {
		f->dim *= 2;
		f->vet = (int *)realloc(f->vet, f->dim * sizeof(int));

		verifica(f->vet);

		if (f->ini != 0) {
			int n = f->n - f->ini;
			memmove(&f->vet[f->dim - n],
				&f->vet[f->ini], n * sizeof(int));
			f->ini = f->dim - n;
		}
	}
	fim = (f->ini + f->n) % f->dim;
	f->vet[fim] = v;
	f->n++;
}

int fila_retira(Fila * f)
{
	if (!f->n) {
		fprintf(stderr,
			"Erro: tentativa de retirar elemento de fila vazia\n");
		exit(EXIT_FAILURE);
	}
	int v = f->vet[f->ini];
	f->n--;
	f->ini = (f->ini + 1) % f->dim;
	return v;
}

int fila_vazia(Fila * f)
{
	return !f->n;
}

void fila_libera(Fila * f)
{
	free(f->vet);
	free(f);
}

void fila_imprime(Fila * f)
{
	for (int i = 0; i < f->n; i++) {
		printf("%d\n", f->vet[(f->ini + i) % f->dim]);
	}
}
