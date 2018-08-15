/*
 * Implemente uma função que compare se duas árvores são iguais. Essa função deve
 * obedecer ao protótipo:
 *
 * 		Arvn* igual (Arvn* a, Arvn* b);
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

static int arvnno_igual(ArvnNo * r, ArvnNo * s)
{
	if (r && s) {
		return r->info == s->info && arvnno_igual(r->prim, s->prim)
		    && arvnno_igual(r->prox, s->prox);
	}
	return r == s;
}

Arvn *igual(Arvn * a, Arvn * b)
{
	if (arvnno_igual(a->raiz, b->raiz)) {
		return a;
	}
	return NULL;
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

	Arvn x = { &a };
	Arvn y = { &a };

	a.prim = &b;
	b.prox = &f;
	b.prim = &c;
	c.prox = &e;
	c.prim = &d;
	f.prox = &g;
	g.prim = &h;
	h.prox = &i;
	i.prim = &j;

	printf("iguais: %d\n", ! !igual(&x, &y));

	return 0;
}
