#include <stdio.h>
#include <stdlib.h>
#include "arvn_char.h"

#define TAB "  "

struct arvnno {
	char info;
	ArvnNo *prim;
	ArvnNo *prox;
};

struct arvn {
	ArvnNo *raiz;
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

ArvnNo *arvn_criano(char c)
{
	ArvnNo *a = (ArvnNo *) aloca(sizeof(ArvnNo));
	a->info = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}

void arvn_insere(ArvnNo * a, ArvnNo * sa)
{
	sa->prox = a->prim;
	a->prim = sa;
}

Arvn *arvn_cria(ArvnNo * r)
{
	Arvn *a = (Arvn *) aloca(sizeof(Arvn));
	a->raiz = r;
	return a;
}

static void imprime(ArvnNo * r, int ntabs)
{
	for (int i = 0; i < ntabs; i++) {
		printf("|%s", TAB);
	}
	printf("%c\n", r->info);
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		imprime(p, ntabs + 1);
	}
}

void arvn_imprime(Arvn * a)
{
	if (a->raiz) {
		imprime(a->raiz, 0);
	}
}

static ArvnNo *busca(ArvnNo * r, char c)
{
	if (r->info == c) {
		return r;
	}
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		ArvnNo *q = busca(p, c);
		if (q) {
			return q;
		}
	}
	return NULL;
}

ArvnNo *arvn_busca(Arvn * a, char c)
{
	return a->raiz ? busca(a->raiz, c) : NULL;
}

static void libera(ArvnNo * r)
{
	ArvnNo *p = r->prim;
	while (p) {
		ArvnNo *t = p->prox;
		libera(p);
		p = t;
	}
	free(r);
}

void arvn_libera(Arvn * a)
{
	if (a->raiz) {
		libera(a->raiz);
	}
	free(a);
}

static int altura(ArvnNo * r)
{
	int hmax = -1;
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		int h = altura(p);
		if (h > hmax) {
			hmax = h;
		}
	}
	return hmax + 1;
}

int arvn_altura(Arvn * a)
{
	return a->raiz ? altura(a->raiz) : -1;
}

/*
static int max2(int a, int b)
{
	return a > b ? a : b;
}

static int altura(ArvnNo * r)
{
	return r ? max2(1 + altura(r->prim), altura(r->prox)) : -1;
}

int arvn_altura(Arvn * a)
{
	return altura(a->raiz);
}
*/
