/*
 * Escreva uma função que receba um vetor de números reais e tenha como valor de
 * retorno um novo vetor, alocado dinamicamente, com os elementos do vetor original
 * em ordem reversa. A função deve ter como valor de retorno o ponteiro do vetor
 * alocado, seguindo o protótipo:
 *
 *      float* reverso (int n, float *v);
 *
 * Faça uma função main para testar sua função. Na função main, não esqueça de
 * liberar a memória alocada pela função auxiliar.
 */

#include<stdio.h>
#include<stdlib.h>

float *reverso(int n, float *v)
{
	float *r = (float *)malloc(n * sizeof(float));

	if (NULL != r) {
		for (int i = 0; i < n; i++) {
			r[i] = v[n - 1 - i];
		}
	}
	return r;
}

#define N 10

int main(void)
{
	float v[N] = { 0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f };
	float *r = reverso(N, v);

	if (r != NULL) {
		for (int i = 0; i < N; i++) {
			printf("%.2f ", r[i]);
		}
		puts("");
		free(r);
	}

	return 0;
}
