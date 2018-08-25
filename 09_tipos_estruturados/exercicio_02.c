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

static void leponto(char *msg, Vetor * v)
{
	printf("%s: ", msg);
	scanf("%f%f%f", &v->x, &v->y, &v->z);
}

float escalar(Vetor * v1, Vetor * v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

int main(void)
{
	Vetor v1, v2;
	while (1) {
		leponto("\nv1", &v1);
		leponto("v2", &v2);
		printf("v1 * v2 = %.2f\n", escalar(&v1, &v2));
	}
	return 0;
}
