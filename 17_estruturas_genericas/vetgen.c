#include <stdio.h>
#include <stdlib.h>
#include "vetgen.h"

struct vetorgen {
	int n;
	int tam;
	void **vet;
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

VetorGen *vgen_cria(void)
{
	VetorGen *v = (VetorGen *) aloca(sizeof(VetorGen));
	v->n = 0;
	v->tam = 4;
	v->vet = (void **)aloca(v->tam * sizeof(void *));
	return v;
}

void vgen_insere(VetorGen * v, void *p)
{
	if (v->n == v->tam) {
		v->tam *= 2;
		v->vet = (void **)realloc(v->vet, v->tam * sizeof(void *));
	}
	v->vet[v->n++] = p;
}

int vgen_tam(VetorGen * v)
{
	return v->n;
}

void *vgen_acessa(VetorGen * v, int i)
{
	return (i < 0 || i >= v->n) ? NULL : v->vet[i];
}

int vgen_percorre(VetorGen * v, int (*cb) (void *info, void *dado), void *dado)
{
	int r = 0;
	for (int i = 0; i < v->n; i++) {
		r = cb(v->vet[i], dado);
		if (r) {
			break;
		}
	}
	return r;
}

void vgen_libera(VetorGen * v, void (*cb) (void *))
{
	if (cb) {
		for (int i = 0; i < v->n; i++) {
			cb(v->vet[i]);
		}
	}
	free(v->vet);
	free(v);
}
