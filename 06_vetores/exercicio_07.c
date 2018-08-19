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

#define N 6

float ponderada(int n, float *v, float *w)
{
	float p = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		p += v[i] * w[i];
		s += w[i];
	}
	return p / s;
}

int main(void)
{
	float notas[N] = { 6.0f, 8.9f, 8.8f, 7.0f, 6.4f, 9.4f };
	float pesos[N] = { 68.f, 68.f, 102.f, 68.f, 102.f, 60.f };
	float cr = ponderada(N, notas, pesos);
	printf("CR = %.1f\n", cr);
	return 0;
}
