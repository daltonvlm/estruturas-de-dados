#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila {
	int n;
	int ini;
	int dim;
	float *vet;
};

Fila *fila_cria(void)
{
	Fila *f = (Fila *) malloc(sizeof(Fila));

	if (!f) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	f->n = 0;
	f->ini = 0;
	f->dim = 4;
	f->vet = (float *)malloc(f->dim * sizeof(float));

	if (!f->vet) {
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return f;
}

void fila_insere(Fila * f, float v)
{
	int fim;
	if (f->n == f->dim) {
		f->dim *= 2;
		f->vet = (float *)realloc(f->vet, f->dim * sizeof(float));

		if (!f->vet) {
			perror("Erro");
			exit(EXIT_FAILURE);
		}
		if (f->ini != 0) {
			int n = f->n - f->ini;
			memmove(&f->vet[f->dim - n],
				&f->vet[f->ini], n * sizeof(float));
			f->ini = f->dim - n;
		}
	}
	fim = (f->ini + f->n) % f->dim;
	f->vet[fim] = v;
	f->n++;
}

float fila_retira(Fila * f)
{
	if (!f->n) {
		fprintf(stderr,
			"Erro: tentativa de retirar elemento de fila vazia\n");
		exit(EXIT_FAILURE);
	}
	float v = f->vet[f->ini];
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
		printf("%f\n", f->vet[(f->ini + i) % f->dim]);
	}
}
