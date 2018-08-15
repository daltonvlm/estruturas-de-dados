/*
 * Considerando uma estrutura para representar um vetor no espaço 3D, implemente
 * uma função que calcule o produto escalar de dois vetores. Essa função deve obedecer
 * ao protótipo:
 *
 *      float escalar (Vetor* v1, Vetor* v2);
 */

#include <stdio.h>

typedef struct vetor Vetor;
struct vetor {
	float x, y, z;
};

float escalar(Vetor * v1, Vetor * v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

int main(void)
{
	while (1) {
		Vetor v1, v2;

		scanf("%f %f %f", &v1.x, &v1.y, &v1.z);
		scanf("%f %f %f", &v2.x, &v2.y, &v2.z);
		printf("%f\n", escalar(&v1, &v2));
	}
	return 0;
}
