/*
 * Implemente uma função que retorne o nível do nó que contém a informação x numa
 * árvore binária de busca. Essa função deve obedecer ao protótipo:
 *
 * 		int nivel (Arv* a, int x);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct arvno ArvNo;
typedef struct arv Arv;

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
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

Arv *cria(void)
{
	Arv *a = (Arv *) aloca(sizeof(Arv));
	a->raiz = NULL;
	return a;
}

static void arvno_libera(ArvNo * r)
{
	if (r) {
		arvno_libera(r->esq);
		arvno_libera(r->dir);
		free(r);
	}
}

void libera(Arv * a)
{
	arvno_libera(a->raiz);
	free(a);
}

void insere(Arv * a, int v)
{
	ArvNo **p = &a->raiz;
	ArvNo *novo = (ArvNo *) aloca(sizeof(ArvNo));

	novo->info = v;
	novo->esq = NULL;
	novo->dir = NULL;

	while (*p) {
		if (v < (*p)->info) {
			p = &(*p)->esq;
		} else {
			p = &(*p)->dir;
		}
	}
	*p = novo;
}

static void arvno_imprime(ArvNo * r, int n)
{
	for (int i = 0; i < n; i++) {
		printf("|  ");
	}
	if (r) {
		printf("%d\n", r->info);
		arvno_imprime(r->esq, n + 1);
		arvno_imprime(r->dir, n + 1);
	} else {
		puts("X");
	}
}

void imprime(Arv * a)
{
	arvno_imprime(a->raiz, 0);
	puts("");
}

int nivel(Arv * a, int x)
{
	int n = 0;
	ArvNo *p = a->raiz;

	while (p && p->info != x) {
		n++;
		if (x < p->info) {
			p = p->esq;
		} else {
			p = p->dir;
		}
	}
	return p ? n : -1;
}

int main(void)
{
	Arv *a = cria();

	insere(a, 5);
	insere(a, 2);
	insere(a, 8);
	insere(a, 1);
	insere(a, 3);
	insere(a, 6);
	insere(a, 9);
	insere(a, 0);
	insere(a, 4);
	insere(a, 7);
	insere(a, 10);

	imprime(a);
	for (int i = -1; i < 12; i++) {
		printf("nivel de %d = %d\n", i, nivel(a, i));
	}
	libera(a);
	return 0;
}
