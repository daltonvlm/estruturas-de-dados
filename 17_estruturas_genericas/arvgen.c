#include <stdio.h>
#include <stdlib.h>
#include "arvgen.h"

typedef struct arvgenno ArvGenNo;

struct arvgenno {
	void *info;
	ArvGenNo *esq;
	ArvGenNo *dir;
};
struct arvgen {
	ArvGenNo *raiz;
	int (*cmp) (void *, void *);
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

ArvGen *agen_cria(int (*cb) (void *chave, void *info))
{
	ArvGen *a = (ArvGen *) aloca(sizeof(ArvGen));
	a->raiz = NULL;
	a->cmp = cb;
	return a;
}

void agen_insere(ArvGen * a, void *chave, void *info)
{
	ArvGenNo **p = &a->raiz;

	while (*p) {
		int cmp = a->cmp(chave, (*p)->info);
		if (cmp < 0) {
			p = &(*p)->esq;
		} else {
			p = &(*p)->dir;
		}
	}
	*p = (ArvGenNo *) aloca(sizeof(ArvGenNo));
	(*p)->info = info;
	(*p)->esq = NULL;
	(*p)->dir = NULL;
}

void *agen_busca(ArvGen * a, void *chave)
{
	ArvGenNo *p = a->raiz;
	while (p) {
		int cmp = a->cmp(chave, p->info);
		if (!cmp) {
			break;
		}
		if (cmp < 0) {
			p = p->esq;
		} else {
			p = p->dir;
		}
	}
	return p ? p->info : NULL;
}

static int percorre(ArvGenNo * r, int (*cb) (void *info, void *dado),
		    void *dado)
{
	if (!r) {
		return 0;
	}
	int s;
	if (s = percorre(r->esq, cb, dado)) {
		return s;
	}
	if (s = cb(r->info, dado)) {
		return s;
	}
	return percorre(r->dir, cb, dado);
}

int agen_percorre(ArvGen * a, int (*cb) (void *info, void *dado), void *dado)
{
	return percorre(a->raiz, cb, dado);
}

static void libera(ArvGenNo * r, void (*cb) (void *))
{
	if (r) {
		libera(r->esq, cb);
		libera(r->dir, cb);
		cb(r->info);
		free(r);
	}
}

void agen_libera(ArvGen * a, void (*cb) (void *))
{
	libera(a->raiz, cb);
	free(a);
}
