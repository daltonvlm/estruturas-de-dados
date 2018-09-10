#include <stdio.h>
#include <stdlib.h>
#include "vetgen.h"

#define N 4

// Vetor genérico que armazena void
struct vetorgen {
	int n;
	int dim;
	void **v;
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

// cria vetor vazio
VetorGen *vgen_cria(void)
{
	VetorGen *vg = (VetorGen *) aloca(sizeof(VetorGen));
	vg->n = 0;
	vg->dim = N;
	vg->v = (void **)aloca(vg->dim * sizeof(void *));
	return vg;
}

// insere novo elemento no final do vetor
void vgen_insere(VetorGen * v, void *p)
{
	if (v->n == v->dim) {
		v->dim *= 2;
		v->v = (void **)realloc(v->v, v->dim * sizeof(void *));
		check(v->v);
	}
	v->v[v->n++] = p;
}

// retorna o número de elementos do vetor
int vgen_tam(VetorGen * v)
{
	return v->n;
}

// retorna a informação associada ao elemento de índice i
void *vgen_acessa(VetorGen * v, int i)
{
	if (i < 0 || i >= v->n) {
		fprintf(stderr, "Erro: indice '%d' fora dos limites.\n", i);
		exit(EXIT_FAILURE);
	}
	return v->v[i];
}

// percorre os elementos do vetor chamando a callback
int vgen_percorre(VetorGen * v, int (*cb) (void *info, void *dado), void *dado)
{
	for (int i = 0; i < v->n; i++) {
		int r = cb(v->v[i], dado);
		if (r) {
			return r;
		}
	}
	return 0;
}

// libera a memória do vetor, chamando a callback
void vgen_libera(VetorGen * v, void (*cb) (void *))
{
	if (cb) {
		for (int i = 0; i < v->n; i++) {
			cb(v->v[i]);
		}
	}
	free(v->v);
	free(v);
}
