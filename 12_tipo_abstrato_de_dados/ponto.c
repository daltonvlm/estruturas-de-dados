#include"ponto.h"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct ponto {
	float x;
	float y;
};

Ponto *pto_cria(float x, float y)
{
	Ponto *p = (Ponto *) malloc(sizeof(Ponto));
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	p->x = x;
	p->y = y;
	return p;
}

void pto_libera(Ponto * p)
{
	free(p);
}

void pto_acessa(Ponto * p, float *x, float *y)
{
	*x = p->x;
	*y = p->y;
}

void pto_atribui(Ponto * p, float x, float y)
{
	p->x = x;
	p->y = y;
}

float pto_distancia(Ponto * p1, Ponto * p2)
{
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	return sqrt(dx * dx + dy * dy);
}

void pto_acessa_polar(Ponto * p, float *r, float *t)
{
	*r = sqrt(p->x * p->x + p->y * p->y);
	*t = atan2f(p->x, p->y);
}
