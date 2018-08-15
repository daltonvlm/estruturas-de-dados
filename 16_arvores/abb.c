#include "abb.h"

#include <stdio.h>
#include <stdlib.h>

struct arv {
	ArvNo *raiz;
};

struct arvno {
	int info;
	ArvNo *esq;
	ArvNo *dir;
};

Arv *abb_cria(void)
{
	Arv *a = (Arv *) malloc(sizeof(Arv));
	if (!a) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
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

static int max2(int a, int b)
{
	return a > b ? a : b;
}

static int altura(ArvNo * r)
{
	if (r) {
		return 1 + max2(altura(r->esq), altura(r->dir));
	}
	return -1;
}

static void balanceia(ArvNo ** p)
{
	if (*p) {
		int he = altura((*p)->esq);
		int hd = altura((*p)->dir);

		while (abs(he - hd) >= 2) {
			if (he > hd) {
				ArvNo **q = &(*p)->esq;
				while (*q && (*q)->dir) {
					q = &(*q)->dir;
				}
				if (*q == (*p)->esq) {
					(*q)->dir = *p;
					*p = *q;
					*q = NULL;
				} else {
					ArvNo *t = (*q)->esq;
					(*q)->esq = (*p)->esq;
					(*q)->dir = *p;
					(*p)->esq = NULL;
					*p = *q;
					*q = t;
				}
			} else {
				ArvNo **q = &(*p)->dir;
				while (*q && (*q)->esq) {
					q = &(*q)->esq;
				}
				if (*q == (*p)->dir) {
					(*q)->esq = *p;
					*p = *q;
					*q = NULL;
				} else {
					ArvNo *t = (*q)->dir;
					(*q)->dir = (*p)->dir;
					(*q)->esq = *p;
					(*p)->dir = NULL;
					*p = *q;
					*q = t;
				}
			}
			he = altura((*p)->esq);
			hd = altura((*p)->dir);
		}
		balanceia(&(*p)->esq);
		balanceia(&(*p)->dir);
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
	*p = (ArvNo *) malloc(sizeof(ArvNo));
	if (!(*p)) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	(*p)->info = v;
	(*p)->esq = NULL;
	(*p)->dir = NULL;
	balanceia(&a->raiz);
}

void abb_retira(Arv * a, int v)
{
	ArvNo **p = &a->raiz;

	// busca o no
	while (*p && v != (*p)->info) {
		if (v < (*p)->info) {
			p = &(*p)->esq;
		} else {
			p = &(*p)->dir;
		}
	}

	if (*p) {		// se econtrou o no
		// verifica se o no tem nenhum, um ou dois filhos
		if ((*p)->esq) {
			if ((*p)->dir) {
				ArvNo **q = &(*p)->esq;
				while ((*q)->dir) {	// busca o maior no da sub arvore esquerda
					q = &(*q)->dir;
				}
				(*p)->info = (*q)->info;	// troca de valor com o no procurado
				ArvNo *tmp = *q;
				*q = tmp->esq;	// acerta o encadeamento
				free(tmp);
			} else {
				ArvNo *tmp = (*p)->esq;
				free(*p);
				*p = tmp;
			}
		} else {
			ArvNo *tmp = (*p)->dir;
			free(*p);
			*p = tmp;
		}
	}
	balanceia(&a->raiz);
}

static void imprime(ArvNo * r, int n)
{
	for (int i = 0; i < n; i++) {
		printf("|  ");
	}
	if (r) {
		printf("%d\n", r->info);
		imprime(r->esq, n + 1);
		imprime(r->dir, n + 1);
	} else {
		puts("X");
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

static ArvNo *busca(ArvNo * r, int v)
{
	if (!r) {
		return NULL;
	}
	if (r->info == v) {
		return r;
	}
	if (v < r->info) {
		return busca(r->esq, v);
	}
	return busca(r->dir, v);
}

ArvNo *abb_busca(Arv * a, int v)
{
	return busca(a->raiz, v);
}
