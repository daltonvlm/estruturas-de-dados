#include "fila2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila2 {
	int n;
	int dim;
	int ini;
	float *vet;
};

Fila2 *fila2_cria(void)
{
	Fila2 *f = (Fila2 *) malloc(sizeof(Fila2));
	if (!f) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	f->n = 0;
	f->ini = 0;
	f->dim = 4;
	f->vet = (float *)malloc(f->dim * sizeof(float));
	if (!f->vet) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return f;
}

void fila2_insere_ini(Fila2 * f, float v)
{
	if (f->n == f->dim) {
		f->dim *= 2;
		f->vet = (float *)realloc(f->vet, f->dim * sizeof(float));
		if (!f->vet) {
			perror("Erro");
			exit(EXIT_FAILURE);
		}
		if (f->ini) {
			int n = f->n - f->ini;
			memmove(&f->vet[f->dim - n],
				&f->vet[f->ini], n * sizeof(float));
			f->ini = f->dim - n;
		}
	}
	f->ini = (f->ini - 1 + f->dim) % f->dim;
	f->vet[f->ini] = v;
	f->n++;
}

void fila2_insere_fim(Fila2 * f, float v)
{
	int fim;
	if (f->n == f->dim) {
		f->dim *= 2;
		f->vet = (float *)realloc(f->vet, f->dim * sizeof(float));
		if (!f->vet) {
			perror("Erro");
			exit(EXIT_FAILURE);
		}
		if (f->ini) {
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

float fila2_retira_ini(Fila2 * f)
{
	if (!f->n) {
		fprintf(stderr, "Erro: fila vazia\n");
		exit(EXIT_FAILURE);
	}
	float v = f->vet[f->ini];
	f->ini = (f->ini + 1) % f->dim;
	f->n--;
	return v;
}

float fila2_retira_fim(Fila2 * f)
{
	if (!f->n) {
		fprintf(stderr, "Erro: fila vazia\n");
		exit(EXIT_FAILURE);
	}
	float v = f->vet[(f->ini + f->n - 1) % f->dim];
	f->n--;
	return v;
}

int fila2_vazia(Fila2 * f)
{
	return !f->n;
}

void fila2_libera(Fila2 * f)
{
	free(f->vet);
	free(f);
}
