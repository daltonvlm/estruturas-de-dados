#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

struct pilha {
	int n;
	int dim;
	float *vet;
};

Pilha *pilha_cria(void)
{
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));

	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	p->n = 0;
	p->dim = 2;
	p->vet = (float *)malloc(p->dim * sizeof(float));

	if (!p->vet) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

void pilha_push(Pilha * p, float v)
{
	if (p->n == p->dim) {
		p->dim *= 2;
		p->vet = (float *)realloc(p->vet, p->dim * sizeof(float));

		if (!p->vet) {
			perror("Erro");
			exit(EXIT_FAILURE);
		}
	}
	p->vet[p->n++] = v;
}

float pilha_pop(Pilha * p)
{
	if (!p->n) {
		fprintf(stderr,
			"Erro: tentativa de retirar elemento de pilha vazia\n");
		exit(EXIT_FAILURE);
	}
	return p->vet[--p->n];
}

int pilha_vazia(Pilha * p)
{
	return !p->n;
}

void pilha_libera(Pilha * p)
{
	free(p->vet);
	free(p);
}

void pilha_imprime(Pilha * p)
{
	for (int i = p->n - 1; i >= 0; i--) {
		printf("%f\n", p->vet[i]);
	}
}
