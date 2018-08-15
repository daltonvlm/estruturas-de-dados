/*
 * Implemente uma função que compare se duas árvores binárias são iguais. Essa
 * função deve obedecer ao protótipo:
 *
 * 		int igual (Arv* a, Arv* b);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;
typedef struct arvno ArvNo;

struct arv {
	ArvNo *raiz;
};

struct arvno {
	int info;
	ArvNo *esq;
	ArvNo *dir;
};

static int arvno_igual(ArvNo * r, ArvNo * s)
{
	if (r && s) {
		return r->info == s->info && arvno_igual(r->esq, s->esq)
		    && arvno_igual(r->dir, s->dir);
	}
	return r == s;
}

int igual(Arv * a, Arv * b)
{
	return arvno_igual(a->raiz, b->raiz);
}

int main(void)
{
	ArvNo zero = { 0, NULL, NULL };
	ArvNo um = { 1, NULL, NULL };
	ArvNo dois = { 2, NULL, NULL };
	ArvNo tres = { 3, NULL, NULL };
	ArvNo quatro = { 4, NULL, NULL };
	ArvNo cinco = { 5, NULL, NULL };
	ArvNo seis = { 6, NULL, NULL };
	ArvNo sete = { 7, NULL, NULL };
	ArvNo oito = { 8, NULL, NULL };
	ArvNo nove = { 9, NULL, NULL };
	ArvNo dez = { 10, NULL, NULL };

	Arv a = { &cinco };
	Arv b = { &cinco };

	cinco.esq = &dois;
	cinco.dir = &oito;

	dois.esq = &um;
	dois.dir = &tres;

	oito.esq = &seis;
	oito.dir = &nove;

	um.esq = &zero;
	tres.dir = &quatro;

	seis.dir = &sete;
	nove.dir = &dez;

	printf("iguais: %d\n", igual(&a, &b));

	return 0;
}
