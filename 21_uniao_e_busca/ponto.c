#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
	float x, y;
	int id;
};

static void verifica(void *p)
{
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	verifica(p);
	return p;
}

Ponto *ponto_cria(float x, float y, int id)
{
	Ponto *p = (Ponto *) aloca(sizeof(Ponto));
	p->x = x;
	p->y = y;
	p->id = id;
	return p;
}

void ponto_libera(Ponto * p)
{
	free(p);
}

float ponto_distancia(Ponto * p, Ponto * q)
{
	return sqrt(pow(p->x - q->x, 2)
		    + pow(p->y - q->y, 2)
	    );
}

int ponto_pega_id(Ponto*p){
	return p->id;
}

void ponto_imprime(Ponto*p,char*fmt){
	printf(fmt,p->x,p->y);
}
