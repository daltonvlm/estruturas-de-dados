#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

struct complexo {
	float a;
	float b;
};

Complexo *cmplx_cria(float a, float b)
{
	Complexo *c = (Complexo *) malloc(sizeof(Complexo));
	if (!c) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	c->a = a;
	c->b = b;
	return c;
}

void cmplx_libera(Complexo * c)
{
	free(c);
}

Complexo *cmplx_soma(Complexo * c1, Complexo * c2)
{
	// (a + bi) + (c + di) = (a + c) + (b + d)i
	Complexo *c = cmplx_cria(0, 0);
	c->a = c1->a + c2->a;
	c->b = c1->b + c2->b;
	return c;
}

Complexo *cmplx_subtrai(Complexo * c1, Complexo * c2)
{
	// (a + bi) - (c + di) = (a - c) + (b - d)i
	Complexo *c = cmplx_cria(0, 0);
	c->a = c1->a - c2->a;
	c->b = c1->b - c2->b;
	return c;
}

Complexo *cmplx_multiplica(Complexo * c1, Complexo * c2)
{
	// (a + bi)(c + di) = (ac - bd) + (bc + ad)i
	Complexo *c = cmplx_cria(0, 0);
	c->a = c1->a * c2->a - c1->b * c2->b;
	c->b = c1->b * c2->a + c1->a * c2->b;
	return c;
}

Complexo *cmplx_divide(Complexo * c1, Complexo * c2)
{
	//(a + bi)/(c + di) = (ac + bd)/(c^2 + d^2) + ((bc - ad)/(c^2 + d^2))i

	Complexo *c = cmplx_cria(0, 0);
	c->a =
	    ((c1->a * c2->a) + (c1->b * c2->b)) / ((c2->a * c2->a) +
						   (c2->b * c2->b));
	c->b =
	    ((c1->b * c2->a) - (c1->a * c2->b)) / ((c2->a * c2->a) +
						   (c2->b * c2->b));
	return c;
}

void cmplx_imprime(Complexo * c)
{
	printf("(%g,%g)\n", c->a, c->b);
}
