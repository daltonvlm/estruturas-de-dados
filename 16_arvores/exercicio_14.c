/*
 * Implemente uma função que crie uma cópia de uma árvore. Essa função deve
 * obedecer ao protótipo:
 *
 * 		Arvn* copia (Arvn* a);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct arvnno ArvnNo;
typedef struct arvn Arvn;

struct arvnno {
	int info;
	ArvnNo *prim;
	ArvnNo *prox;
};
struct arvn {
	ArvnNo *raiz;
};

static void arvnno_imprime(ArvnNo * r, int n)
{
	for (int i = 0; i < n; i++) {
		printf("|  ");
	}
	printf("%d\n", r->info);
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		arvnno_imprime(p, n + 1);
	}
}

void imprime(Arvn * a)
{
	if (a->raiz) {
		arvnno_imprime(a->raiz, 0);
	}
	puts("");
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

static void arvnno_libera(ArvnNo * r)
{
	if (r) {
		arvnno_libera(r->prim);
		arvnno_libera(r->prox);
		free(r);
	}
}

static void libera(Arvn * a)
{
	arvnno_libera(a->raiz);
	free(a);
}

static ArvnNo *arvnno_copia(ArvnNo * r)
{
	ArvnNo *novo = NULL;
	if (r) {
		novo = (ArvnNo *) aloca(sizeof(ArvnNo));
		novo->info = r->info;
		novo->prim = arvnno_copia(r->prim);
		novo->prox = arvnno_copia(r->prox);
	}
	return novo;
}

Arvn *copia(Arvn * a)
{
	Arvn *cp = (Arvn *) aloca(sizeof(Arvn));
	cp->raiz = arvnno_copia(a->raiz);
	return cp;
}

int main(void)
{
	ArvnNo a = { 0, NULL, NULL };
	ArvnNo b = { 1, NULL, NULL };
	ArvnNo c = { 2, NULL, NULL };
	ArvnNo d = { 3, NULL, NULL };
	ArvnNo e = { 4, NULL, NULL };
	ArvnNo f = { 5, NULL, NULL };
	ArvnNo g = { 6, NULL, NULL };
	ArvnNo h = { 7, NULL, NULL };
	ArvnNo i = { 8, NULL, NULL };
	ArvnNo j = { 9, NULL, NULL };

	Arvn arv = { &a };
	Arvn *cp;

	a.prim = &b;
	b.prox = &f;
	b.prim = &c;
	c.prox = &e;
	c.prim = &d;
	f.prox = &g;
	g.prim = &h;
	h.prox = &i;
	i.prim = &j;

	cp = copia(&arv);

	puts("arv:");
	imprime(&arv);
	puts("cp:");
	imprime(cp);
	libera(cp);

	return 0;
}
