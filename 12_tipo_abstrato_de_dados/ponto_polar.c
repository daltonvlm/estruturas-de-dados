#include"ponto.h"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct ponto {
	float r;		// distância do centro (0, 0)
	float t;		// ângulo 't'eta
};

Ponto *pto_cria(float x, float y)
{
	Ponto *p = (Ponto *) malloc(sizeof(Ponto));
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	p->r = sqrt(x * x + y * y);
	p->t = atan2f(x, y);
	return p;
}

void pto_libera(Ponto * p)
{
	free(p);
}

void pto_acessa(Ponto * p, float *x, float *y)
{
	*x = p->r * cos(p->t);
	*y = p->r * sin(p->t);
}

void pto_atribui(Ponto * p, float x, float y)
{
	p->r = sqrt(x * x + y * y);
	p->t = atan2f(x, y);
}

float pto_distancia(Ponto * p1, Ponto * p2)
{
	float x1 = p1->r * cos(p1->t);
	float y1 = p1->r * sin(p1->t);

	float x2 = p2->r * cos(p2->t);
	float y2 = p2->r * sin(p2->t);

	float dx = x1 - x2;
	float dy = y1 - y2;

	return sqrt(dx * dx + dy * dy);
}
