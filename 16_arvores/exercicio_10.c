/*
 * Considerando estruturas de árvores com número variável de filhos que armazenam
 * valores inteiros, implemente uma função que, dada uma árvore, retorne a quanti-
 * dade de nós que guardam números pares. Essa função deve obedecer ao protótipo:
 *
 * 		int pares (Arvn* a);
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

static void imprime(ArvnNo * r, int n)
{
	for (int i = 0; i < n; i++) {
		printf("|  ");
	}
	printf("%d\n", r->info);
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		imprime(p, n + 1);
	}
}

void arvn_imprime(Arvn * a)
{
	if (a->raiz) {
		imprime(a->raiz, 0);
	}
}

static int arvnno_pares(ArvnNo * r)
{
	int n = 0;
	if (!(r->info % 2)) {
		n++;
	}
	for (ArvnNo * p = r->prim; p; p = p->prox) {
		n += arvnno_pares(p);
	}
	return n;
}

int pares(Arvn * a)
{
	if (a->raiz) {
		return arvnno_pares(a->raiz);
	}
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

	a.prim = &b;
	b.prox = &f;
	b.prim = &c;
	c.prox = &e;
	c.prim = &d;
	f.prox = &g;
	g.prim = &h;
	h.prox = &i;
	i.prim = &j;

	arvn_imprime(&arv);
	printf("pares: %d\n", pares(&arv));
	return 0;
}
