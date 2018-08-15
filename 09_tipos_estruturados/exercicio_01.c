/*
 * Considerando uma estrutura para representar um ponto no espaço 2D, implemente
 * uma função que indique se um ponto p está localizado dentro ou fora de um retân-
 * gulo. O retângulo é definido por seus vértices inferior esquerdo v1 e superior direito
 * v2. A função deve retornar 1, caso o ponto esteja localizado dentro do retângulo, e
 * 0, cado contrário. Essa função deve obedecer ao protótipo:
 *
 *      int dentroRet (Ponto* v1, Ponto* v2, Ponto* p);
 */

#include <stdio.h>

typedef struct ponto Ponto;
struct ponto {
	float x, y;
};

int dentroRet(Ponto * v1, Ponto * v2, Ponto * p)
{
	return p->x > v1->x && p->x < v2->x && p->y > v1->y && p->y < v2->y;
}

int main(void)
{
	while (1) {
		Ponto v1, v2, p;

		scanf("%f %f", &v1.x, &v1.y);
		scanf("%f %f", &v2.x, &v2.y);
		scanf("%f %f", &p.x, &p.y);

		if (dentroRet(&v1, &v2, &p)) {
			puts("Dentro");
		} else {
			puts("Fora");
		}
	}
	return 0;
}
