/*
 * A média geométrica, Gn, de um conjunto de valores é dada por:
 *
 *                              Gn = Raiz(n, P[i=0,n-1]: Vi)
 *
 * Escreva uma função para calcular e retornar a média geométrica de um conjunto
 * de valores. Essa função deve obedecer ao protótipo a seguir. Escreva um programa
 * para testar sua função.
 *
 *      float geometrica (int n, float *v);
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 10

float geometrica(int n, float *v)
{
	float p = 1.0f;
	for (int i = 0; i < n; i++) {
		p *= v[i];
	}
	if (p < 0) {
		printf("Erro: raiz com radicando negativo: %f\n", p);
		return 0;
	}
	return powf(p, 1. / n);
}

int main(void)
{
	float gn, v[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		v[i] = rand() % 100;
		printf("%.2f ", v[i]);
	}
	puts("");
	gn = geometrica(N, v);
	printf("Gn = %2.f\n", gn);
	return 0;
}
