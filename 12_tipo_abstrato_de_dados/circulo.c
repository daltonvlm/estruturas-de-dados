#include "circulo.h"

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

struct circulo {
	float r;
	Ponto *p;
};

Circulo *circ_cria(float x, float y, float r)
{
	Circulo *c = (Circulo *) malloc(sizeof(Circulo));
	if (!c) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	c->r = r;
	c->p = pto_cria(x, y);
	return c;
}

void circ_libera(Circulo * c)
{
	pto_libera(c->p);
	free(c);
}

float circ_area(Circulo * c)
{
	return PI * c->r * c->r;
}

int circ_interior(Circulo * c, Ponto * p)
{
	return pto_distancia(c->p, p) < c->r;
}
