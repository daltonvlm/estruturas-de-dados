/*
 * Escreva uma função que retorne o valor mínimo armazenado em um vetor. Essa
 * função deve obedecer ao protótipo a seguir. Escreva um programa para testar sua
 * função.
 *      
 *      float minimo (int n, float *v);
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

float minimo(int n, float *v)
{
	float min = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] < min) {
			min = v[i];
		}
	}
	return min;
}

int main(void)
{
	float min;
	float v[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		v[i] = rand() % 100;
		printf("%.2f ", v[i]);
	}
	puts("");
	min = minimo(N, v);
	printf("min = %.2f\n", min);
	return 0;
}
