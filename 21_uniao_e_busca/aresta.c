#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "ponto.h"

struct aresta {
	Ponto *p, *q;
	float d;
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

Aresta *aresta_cria(Ponto * p, Ponto * q)
{
	Aresta *a = (Aresta *) aloca(sizeof(Aresta));
	a->p = p;
	a->q = q;
	a->d = ponto_distancia(p, q);
	return a;
}

void aresta_libera(Aresta * a, void (*libera) (void *))
{
	if (libera) {
		libera(a->p);
		libera(a->q);
	}
	free(a);
}

float aresta_pega_distancia(Aresta * a)
{
	return a->d;
}

void aresta_pega_pontos(Aresta*a,Ponto**p,Ponto**q){
	*p=a->p;
	*q=a->q;
}

void aresta_imprime(Aresta*a){
	ponto_imprime(a->p,"(%.2f, %.2f)\t");
	ponto_imprime(a->q,"(%.2f, %.2f)\t");
	printf("%.2f\n",a->d);
}
