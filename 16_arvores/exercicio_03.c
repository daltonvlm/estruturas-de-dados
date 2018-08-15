/*
 * Implemente uma função que retorne a quantidade de nós de uma árvore binária
 * que possuem apenas um filho. Essa função deve obedecer ao protótipo:
 *
 * 		int um_filho (Arv *a);
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

static int arvno_um_filho(ArvNo * r)
{
	if (!r || !r->dir && !r->esq) {
		return 0;
	}
	return !(r->esq
		 && r->dir) + arvno_um_filho(r->esq) + arvno_um_filho(r->dir);
}

int um_filho(Arv * a)
{
	return arvno_um_filho(a->raiz);
}

void imprime_nos(ArvNo * r, int n)
{
	for (int i = 0; i < n; i++) {
		printf("|  ");
	}
	if (r) {
		printf("%d\n", r->info);
		imprime_nos(r->esq, n + 1);
		imprime_nos(r->dir, n + 1);
	} else {
		puts("X");
	}
}

void imprime(Arv * a)
{
	imprime_nos(a->raiz, 0);
	puts("");
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

	imprime(&a);
	printf("Um filho: %d\n", um_filho(&a));

	return 0;
}
