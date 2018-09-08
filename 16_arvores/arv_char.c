#include <stdio.h>
#include <stdlib.h>
#include "arv_char.h"

#define TAB "  "

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
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

Arv *arv_cria(ArvNo * raiz)
{
	Arv *a = (Arv *) aloca(sizeof(Arv));
	a->raiz = raiz;
	return a;
}

ArvNo *arv_criano(char c, ArvNo * esq, ArvNo * dir)
{
	ArvNo *arvno = (ArvNo *) aloca(sizeof(ArvNo));
	arvno->info = c;
	arvno->esq = esq;
	arvno->dir = dir;
	return arvno;
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

static void imprime(ArvNo * r, int ntabs)
{
	for (int i = 0; i < ntabs; i++) {
		printf("|%s", TAB);
	}
	if (r) {
		printf("%c\n", r->info);
		imprime(r->esq, ntabs + 1);
		imprime(r->dir, ntabs + 1);
	} else {
		puts("x");
	}
}

void arv_imprime(Arv * a)
{
	imprime(a->raiz, 0);
}

static int pertence(ArvNo * r, char c)
{
	if (r) {
		return r->info == c ||
		    pertence(r->esq, c) || pertence(r->dir, c);
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
		ArvNo *sub = busca(r->esq, c);
		return sub ? sub : busca(r->dir, c);
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
	if (r) {
		return 1 + max2(altura(r->esq), altura(r->dir));
	}
	return -1;
}

int arv_altura(Arv * a)
{
	return altura(a->raiz);
}
