/*
 * Implemente uma função que retorne a quantidade de folhas de uma árvore binária.
 * Essa função deve obedecer ao protótipo:
 *
 * 		int folhas (Arv* a);
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

static int arvno_folhas(ArvNo * r)
{
	if (!r) {
		return 0;
	}
	return (!r->esq
		&& !r->dir) + arvno_folhas(r->esq) + arvno_folhas(r->dir);
}

int folhas(Arv * a)
{
	return arvno_folhas(a->raiz);
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

	printf("folhas: %d\n", folhas(&a));
	return 0;
}
