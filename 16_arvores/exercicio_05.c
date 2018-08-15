/*
 * Implemente uma função que crie uma cópia de uma árvore binária. Essa função
 * deve obedecer ao protótipo:
 *
 * 		Arv* copia (Arv* a);
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

static void arvno_copia(ArvNo * r, ArvNo ** p)
{
	*p = NULL;
	if (r) {
		ArvNo *novo = (ArvNo *) aloca(sizeof(ArvNo));
		novo->info = r->info;
		*p = novo;
		arvno_copia(r->esq, &novo->esq);
		arvno_copia(r->dir, &novo->dir);
	}
}

Arv *copia(Arv * a)
{
	Arv *cp = (Arv *) aloca(sizeof(Arv));
	arvno_copia(a->raiz, &cp->raiz);
	return cp;
}

int main(void)
{
	Arv *a = cria();
	Arv *cp;

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

	cp = copia(a);

	puts("a:");
	imprime(a);
	libera(a);

	puts("cp:");
	imprime(cp);
	libera(cp);

	return 0;
}
