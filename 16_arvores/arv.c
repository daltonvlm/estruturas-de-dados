#include "arv.h"

#include <stdio.h>
#include <stdlib.h>

struct arvno {
	char info;
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
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

Arv *arv_cria(ArvNo * r)
{
	Arv *a = (Arv *) aloca(sizeof(Arv));
	a->raiz = r;
	return a;
}

ArvNo *arv_criano(char c, ArvNo * esq, ArvNo * dir)
{
	ArvNo *p = (ArvNo *) aloca(sizeof(ArvNo));
	p->info = c;
	p->esq = esq;
	p->dir = dir;
	return p;
}

static void libera(ArvNo * r)
{
	if (r) {
		libera(r->esq);
		libera(r->dir);
		free(r);
	}
}

void arv_libera(Arv * a)
{
	libera(a->raiz);
	free(a);
}

static void imprime(ArvNo * r, int n)
{
	for (int i = 0; i < n; i++) {
		printf("|  ");
	}
	if (r) {
		printf("%c\n", r->info);
		imprime(r->esq, n + 1);
		imprime(r->dir, n + 1);
	} else {
		puts("X");
	}
}

void arv_imprime(Arv * a)
{
	imprime(a->raiz, 0);
}

int pertence(ArvNo * r, char c)
{
	if (r) {
		return r->info == c || pertence(r->esq, c)
		    || pertence(r->dir, c);
	}
	return 0;
}

int arv_pertence(Arv * a, char c)
{
	return pertence(a->raiz, c);
}

static ArvNo *busca(ArvNo * r, char c)
{
	if (r) {
		if (r->info == c) {
			return r;
		}
		ArvNo *no = busca(r->esq, c);
		if (!no) {
			no = busca(r->dir, c);
		}
		return no;
	}
	return NULL;
}

ArvNo *arv_busca(Arv * a, char c)
{
	return busca(a->raiz, c);
}

static int max2(int a, int b)
{
	return a > b ? a : b;
}

static int altura(ArvNo * r)
{
	if (!r) {
		return -1;
	}
	return 1 + max2(altura(r->esq), altura(r->dir));
}

int arv_altura(Arv * a)
{
	return altura(a->raiz);
}
