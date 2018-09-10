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
	int (*cmp) (void *chave, void *info);
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

ArvGen *agen_cria(int (*cb_cmp) (void *chave, void *info))
{
	ArvGen *a = (ArvGen *) aloca(sizeof(ArvGen));
	a->raiz = NULL;
	a->cmp = cb_cmp;
	return a;
}

static int max(int a, int b)
{
	return a > b ? a : b;
}

static int altura(ArvGenNo * r)
{
	if (r) {
		return 1 + max(altura(r->esq), altura(r->dir));
	}
	return -1;
}

static void gira_esquerda(ArvGenNo ** p)
{
	ArvGenNo **q = &(*p)->dir;
	while ((*q)->esq) {
		q = &(*q)->esq;
	}
	(*q)->esq = *p;
	if (*q == (*p)->dir) {
		*p = *q;
		*q = NULL;
	} else {
		ArvGenNo *t = (*q)->dir;
		(*q)->dir = (*p)->dir;
		(*p)->dir = NULL;
		*p = *q;
		*q = t;
	}
}

static void gira_direita(ArvGenNo ** p)
{
	ArvGenNo **q = &(*p)->esq;
	while ((*q)->dir) {
		q = &(*q)->dir;
	}
	(*q)->dir = *p;
	if (*q == (*p)->esq) {
		*p = *q;
		*q = NULL;
	} else {
		ArvGenNo *t = (*q)->esq;
		(*q)->esq = (*p)->esq;
		(*p)->esq = NULL;
		*p = *q;
		*q = t;
	}
}

static void balanceia(ArvGenNo ** p)
{
	if (*p) {
		int he = altura((*p)->esq);
		int hd = altura((*p)->dir);
		int dif;
		while (abs(dif = he - hd) >= 2) {
			if (dif < 0) {
				gira_esquerda(p);
			} else {
				gira_direita(p);
			}
			he = altura((*p)->esq);
			hd = altura((*p)->dir);
		}
		balanceia(&(*p)->esq);
		balanceia(&(*p)->dir);
	}
}

void agen_insere(ArvGen * a, void *chave, void *info)
{
	ArvGenNo **p = &a->raiz;
	while (*p) {
		if (a->cmp(chave, (*p)->info) <= 0) {
			p = &(*p)->esq;
		} else {
			p = &(*p)->dir;
		}
	}
	*p = (ArvGenNo *) aloca(sizeof(ArvGenNo));
	(*p)->info = info;
	(*p)->esq = (*p)->dir = NULL;
	balanceia(&a->raiz);
}

static ArvGenNo **busca(ArvGenNo ** p, void *chave,
			int (*cb_cmp) (void *, void *))
{
	while (*p) {
		int cmp = cb_cmp(chave, (*p)->info);
		if (cmp < 0) {
			p = &(*p)->esq;
		} else if (cmp > 0) {
			p = &(*p)->dir;
		} else {
			break;
		}
	}
	return p;
}

void agen_retira(ArvGen * a, void *chave, void (*cb_libera) (void *))
{
	ArvGenNo **p = busca(&a->raiz, chave, a->cmp);
	if (*p) {
		while (1) {
			ArvGenNo **q = &(*p)->esq;
			while (*q && (*q)->dir) {
				q = &(*q)->dir;
			}
			if (!(*q)) {
				break;
			}
			void *info = (*p)->info;
			(*p)->info = (*q)->info;
			(*q)->info = info;
			p = q;
		}
		ArvGenNo *t = *p;
		*p = t->dir;
		cb_libera(t);
	}
}

void *agen_busca(ArvGen * a, void *chave)
{
	ArvGenNo **p = &a->raiz;
	while (*p) {
		int cmp = a->cmp(chave, (*p)->info);
		if (cmp < 0) {
			p = &(*p)->esq;
		} else if (cmp > 0) {
			p = &(*p)->dir;
		} else {
			return (*p)->info;
		}
	}
	return NULL;
}

static int percorre(ArvGenNo * r, int (*cb) (void *info, void *dado),
		    void *dado)
{
	if (r) {
		int s = percorre(r->esq, cb, dado);
		if (s) {
			return s;
		}
		s = cb(r->info, dado);
		if (s) {
			return s;
		}
		return percorre(r->dir, cb, dado);
	}
	return 0;
}

int agen_percorre(ArvGen * a, int (*cb) (void *, void *), void *dado)
{
	return percorre(a->raiz, cb, dado);
}

static void libera(ArvGenNo * r, void (*cb_libera) (void *))
{
	if (r) {
		libera(r->esq, cb_libera);
		libera(r->dir, cb_libera);
		if (cb_libera) {
			cb_libera(r->info);
		}
		free(r);
	}
}

void agen_libera(ArvGen * a, void (*cb_libera) (void *))
{
	libera(a->raiz, cb_libera);
	free(a);
}
