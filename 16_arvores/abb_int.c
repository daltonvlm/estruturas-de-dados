#include <stdio.h>
#include <stdlib.h>
#include "abb_int.h"

#define TAB "  "
#define max(a, b) ((a) > (b) ? (a) : (b))

struct arvno {
	int info;
	ArvNo *esq;
	ArvNo *dir;
};

struct arv {
	ArvNo *raiz;
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

Arv *abb_cria(void)
{
	Arv *a = (Arv *) aloca(sizeof(Arv));
	a->raiz = NULL;
	return a;
}

static void libera(ArvNo * r)
{
	if (r) {
		libera(r->esq);
		libera(r->dir);
		free(r);
	}
}

void abb_libera(Arv * a)
{
	libera(a->raiz);
	free(a);
}

static int altura(ArvNo * r)
{
	if (!r) {
		return -1;
	}
	return 1 + max(altura(r->esq), altura(r->dir));
}

static void gira_esquerda(ArvNo ** r)
{
	ArvNo **p = &(*r)->dir;
	while ((*p)->esq) {
		p = &(*p)->esq;
	}
	(*p)->esq = *r;
	if (*p == (*r)->dir) {
		*r = *p;
		*p = NULL;
	} else {
		ArvNo *t = (*p)->dir;
		(*p)->dir = (*r)->dir;
		(*r)->dir = NULL;
		*r = *p;
		*p = t;
	}
}

static void gira_direita(ArvNo ** r)
{
	ArvNo **p = &(*r)->esq;
	while ((*p)->dir) {
		p = &(*p)->dir;
	}
	(*p)->dir = *r;
	if (*p == (*r)->esq) {
		*r = *p;
		*p = NULL;
	} else {
		ArvNo *t = (*p)->esq;
		(*p)->esq = (*r)->esq;
		(*r)->esq = NULL;
		*r = *p;
		*p = t;
	}
}

static void balanceia(ArvNo ** r)
{
	if (*r) {
		int hesq = altura((*r)->esq);
		int hdir = altura((*r)->dir);
		int dif = hesq - hdir;
		while (abs(dif) >= 2) {
			if (dif < 0) {
				gira_esquerda(r);
			} else {
				gira_direita(r);
			}
			hesq = altura((*r)->esq);
			hdir = altura((*r)->dir);
			dif = hesq - hdir;
		}
		balanceia(&(*r)->esq);
		balanceia(&(*r)->dir);
	}
}

void abb_insere(Arv * a, int v)
{
	ArvNo **p = &a->raiz;
	while (*p) {
		if (v < (*p)->info) {
			p = &(*p)->esq;
		} else {
			p = &(*p)->dir;
		}
	}
	*p = (ArvNo *) aloca(sizeof(ArvNo));
	(*p)->info = v;
	(*p)->esq = NULL;
	(*p)->dir = NULL;
	balanceia(&a->raiz);
}

static ArvNo **busca(ArvNo ** r, int v)
{
	while (*r && (*r)->info != v) {
		if (v < (*r)->info) {
			r = &(*r)->esq;
		} else {
			r = &(*r)->dir;
		}
	}
	return r;
}

void abb_retira(Arv * a, int v)
{
	ArvNo **p = busca(&a->raiz, v);
	if (*p) {
		do {
			ArvNo **q = &(*p)->esq;
			while (*q && (*q)->dir) {
				q = &(*q)->dir;
			}
			if (!(*q)) {
				break;
			}
			(*p)->info = (*q)->info;
			(*q)->info = v;
			p = q;
		} while (*p);
		ArvNo *t = *p;
		*p = (*p)->dir;
		free(t);
	}
}

ArvNo *abb_busca(Arv * a, int v)
{
	ArvNo **p = busca(&a->raiz, v);
	return *p;
}

int abb_vazia(Arv * a)
{
	return !a->raiz;
}

static void imprime(ArvNo * r, int ntabs)
{
	for (int i = 0; i < ntabs; i++) {
		printf("|%s", TAB);
	}
	if (r) {
		printf("%d\n", r->info);
		imprime(r->esq, ntabs + 1);
		imprime(r->dir, ntabs + 1);
	} else {
		puts("x");
	}
}

void abb_imprime(Arv * a)
{
	imprime(a->raiz, 0);
}

static void imprime_ordenado(ArvNo * r)
{
	if (r) {
		imprime_ordenado(r->esq);
		printf("%d\n", r->info);
		imprime_ordenado(r->dir);
	}
}

void abb_imprime_ordenado(Arv * a)
{
	imprime_ordenado(a->raiz);
}
