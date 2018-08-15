/*
 * A média ponderada de um conjunto de valores é expressa por:
 *
 *                              m = (S: ViWi / S: wi)
 *
 * onde Wi representa os pesos associados aos valores.
 * 
 * Escreva uma função para calcular a média ponderada de um conjunto de valores.
 * A função deve receber como parâmetros os vetores dos valores e dos pesos, e deve
 * retornar a média calculada. Essa função deve obedecer ao protótipo a seguir.
 *
 *      float ponderada (int n, float *v, float *w);
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

float ponderada(int n, float *v, float *w)
{
	float num = .0f;
	float den = .0f;
	for (int i = 0; i < n; i++) {
		num += v[i] * w[i];
		den += w[i];
	}
	return num / den;
}

static void preenche(int n, float *v, int min, int max)
{
	for (int i = 0; i < n; i++) {
		v[i] = rand() % (max - min) + min;
	}
}

static void imprime(int n, float *v)
{
	for (int i = 0; i < n; i++) {
		printf("%5.2f ", v[i]);
	}
	puts("");
}

int main(void)
{
	float mp;
	float v[N], w[N];

	srand(time(NULL));
	preenche(N, v, 0, 11);
	preenche(N, w, 1, 101);

	imprime(N, v);
	imprime(N, w);

	mp = ponderada(N, v, w);
	printf("mp = %.2f\n", mp);
	return 0;
}
