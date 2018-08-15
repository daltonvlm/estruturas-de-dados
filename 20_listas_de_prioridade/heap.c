#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

#define DIM_INI 15

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

struct heap {
	int n;
	int nmax;
	void **v;
	int (*cmp) (const void *v1, const void *v2);
};

static void check(void *p)
{
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

static void troca(Heap * h, int i, int j)
{
	void *tmp = h->v[i];
	h->v[i] = h->v[j];
	h->v[j] = tmp;
}

static void desce(Heap * h, int i)
{
	int c = esq(i);
	while (c < h->n) {
		int c2 = dir(i);
		if (c2 < h->n && h->cmp(h->v[c2], h->v[c]) > 0) {
			c = c2;
		}
		if (h->cmp(h->v[c], h->v[i]) < 0) {
			break;
		}
		troca(h, i, c);
		i = c;
		c = esq(i);
	}
}

static void sobe(Heap * h, int i)
{
	while (i > 0) {
		int p = pai(i);
		if (h->cmp(h->v[i], h->v[p]) < 0) {
			break;
		}
		troca(h, p, i);
		i = p;
	}
}

Heap *heap_cria(int (*cmp) (const void *v1, const void *v2))
{
	Heap *h = (Heap *) aloca(sizeof(Heap));
	h->n = 0;
	h->nmax = DIM_INI;
	h->v = (void **)aloca(h->nmax * sizeof(void *));
	h->cmp = cmp;
	return h;
}

Heap *heap_constroi(int n, void **v,
		    int (*cmp) (const void *v1, const void *v2))
{
	Heap *h = (Heap *) aloca(sizeof(Heap));
	h->n = n;
	h->nmax = n;
	h->v = (void **)aloca(h->nmax * sizeof(void *));
	h->cmp = cmp;
	memcpy(h->v, v, n * sizeof(void *));
	for (int i = h->n / 2 - 1; i >= 0; i--) {
		desce(h, i);
	}
	return h;
}

void heap_libera(Heap * h, void (*libera) (void *v))
{
	if (libera) {
		for (int i = 0; i < h->n; i++) {
			libera(h->v[i]);
		}
	}
	free(h->v);
	free(h);
}

int heap_vazia(Heap * h)
{
	return !h->n;
}

void heap_insere(Heap * h, void *value)
{
	if (h->n == h->nmax) {
		h->nmax *= 2;
		h->v = (void **)realloc(h->v, h->nmax * sizeof(void *));
		check(h->v);
	}
	h->v[h->n++] = value;
	sobe(h, h->n - 1);
}

void *heap_retira(Heap * h)
{
	void *r = h->v[0];
	h->v[0] = h->v[--h->n];
	desce(h, 0);
	return r;
}

int heap_verifica(Heap * h)
{
	for (int i = 0; i < h->n / 2; i++) {
		int e = esq(i);
		int d = dir(i);

		if (h->cmp(h->v[e], h->v[i]) > 0) {
			return 0;
		}
		if (d < h->n && h->cmp(h->v[d], h->v[i]) > 0) {
			return 0;
		}
	}
	return 1;
}
