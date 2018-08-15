/*
 * Considerando estruturas de árvores com número variável de filhos, implemente uma
 * função que retorne a quantidade de nós que possuem apenas um filho. Essa função
 * deve obedecer ao protótipo:
 *
 * 		int um_filho (Arvn* a);
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

static int arvnno_um_filho(ArvnNo * r)
{
	ArvnNo *p = r->prim;
	int n = p && !p->prox;
	for (; p; p = p->prox) {
		n += arvnno_um_filho(p);
	}
	return n;
}

int um_filho(Arvn * a)
{
	if (a->raiz) {
		return arvnno_um_filho(a->raiz);
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

	imprime(&arv);
	printf("um filho: %d\n", um_filho(&arv));

	return 0;
}
