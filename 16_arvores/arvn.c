#include "arvn.h"
#include <stdio.h>
#include <stdlib.h>

struct arvnno {
	char info;
	ArvnNo *prim;		// ponteiro para o primeiro eventual filho
	ArvnNo *prox;		// ponteiro para o primeiro eventual irmao
};

struct arvn {
	ArvnNo *raiz;
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

static void imprime(ArvnNo * r)
{
	printf("< %c ", r->info);
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		imprime(p);
	}
	printf(">");
}

void arvn_imprime(Arvn * a)
{
	if (a->raiz) {
		imprime(a->raiz);
		puts("");
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
	if (a->raiz) {
		return busca(a->raiz, c);
	}
	return NULL;
}

static void libera(ArvnNo * r)
{
	ArvnNo *p = r->prim;
	while (p) {
		ArvnNo *t = p;
		p = p->prox;
		libera(t);
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
	if (a->raiz) {
		return altura(a->raiz);
	}
	return -1;
}
