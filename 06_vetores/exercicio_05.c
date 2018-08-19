/*
 * A média harmônica, Hn, de um conjunto de valores é dada por:
 *
 *      1/Hn = S[i=0, n-1] 1/Vi
 *
 * Escreva uma função para calcular e retornar a média harmônica de um conjunto
 * de valores. Essa função deve obedecer ao protótipo a seguir. Escreva um programa
 * para testar sua função.
 *
 *      float harmonica (int n, float *v);
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

float harmonica(int n, float *v)
{
	float s = .0f;
	for (int i = 0; i < n; i++) {
		s += 1 / v[i];
	}
	return 1 / s;
}

int main(void)
{
	float hn, v[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		v[i] = rand() % 100 + 1;
		printf("%.2f ", v[i]);
	}
	puts("");
	hn = harmonica(N, v);
	printf("Hn = %f\n", hn);
	return 0;
}
