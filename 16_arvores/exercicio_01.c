/*
 * Considerando estruturas de árvores binárias que armazenam valores inteiros, imple-
 * mente uma função que, dada uma árvore, retorne a quantidade de nós que guardam
 * números pares. Essa função deve obedecer ao protótipo:
 *
 * 		int pares (Arv* a);
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

static int arvno_pares(ArvNo * r)
{
	if (!r) {
		return 0;
	}
	return !(r->info % 2) + arvno_pares(r->esq) + arvno_pares(r->dir);
}

int pares(Arv * a)
{
	return arvno_pares(a->raiz);
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

	printf("pares: %d\n", pares(&a));
	return 0;
}
