#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "listagen.h"

#define TOL 1e-5

typedef struct ponto Ponto;
struct ponto {
	float x, y;
};

typedef struct cg Cg;
struct cg {
	int n;
	Ponto p;
};

static void insere_ponto(ListaGen * lst, float x, float y)
{
	Ponto *p = (Ponto *) malloc(sizeof(Ponto));
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	p->x = x;
	p->y = y;
	lgen_insere(lst, p);
}

static void *imprime(void *info, void *dado)
{
	if (info) {
		Ponto *p = (Ponto *) info;
		printf("(%.2f,%.2f)\n", p->x, p->y);
	}
	return NULL;
}

static void *centro_geom(void *info, void *dado)
{
	if (info) {
		Ponto *p = (Ponto *) info;
		Cg *cg = (Cg *) dado;
		cg->p.x += p->x;
		cg->p.y += p->y;
		cg->n++;
	}
	return NULL;
}

static void *igualdade(void *info, void *dado)
{
	if (info) {
		Ponto *p = (Ponto *) info;
		Ponto *q = (Ponto *) dado;
		if (fabs(p->x - q->x) < TOL && fabs(p->y - q->y) < TOL) {
			return info;
		}
	}
	return NULL;
}

static void *pertence(ListaGen * lst, float x, float y)
{
	Ponto p = { x, y };
	return lgen_percorre(lst, igualdade, &p);
}

int main(void)
{
 Ponto p = { x: 1, y:0 };
	ListaGen *lst = lgen_cria();

	for (int i = 0; i < 10; i++) {
		insere_ponto(lst, i, i);
	}
	lgen_percorre(lst, imprime, NULL);

	if (pertence(lst, p.x, p.y)) {
		printf("(%.1f,%.1f) esta na lista\n", p.x, p.y);
	} else {
		printf("(%.1f,%.1f) nao esta na lista\n", p.x, p.y);
	}

	lgen_libera(lst, free);
	return 0;
}
