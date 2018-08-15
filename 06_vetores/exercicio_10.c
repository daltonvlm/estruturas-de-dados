/*
 * Considere histogramas como sendo o número de ocorrências de valores em diferentes
 * intervalos. Considere ainda um experimento laboratorial em que foram colhidos n
 * medições, todas elas maiores ou iguais a 0 e menores que 1. Escreva uma função
 * para preencher um vetor com 10 elementos que represente o histograma destas
 * medidas. O primeiro elemento do vetor deve armazenar o número de medidas
 * maiores ou iguais a 0 e menores que 0.1, o segundo elemento deve armazenar o
 * número de medidas maiores ou iguais a 0.1 e menores que 0.2 e assim por diante.
 *
 * A função deve receber o vetor, v, com as n medidas do experimento e deve preencher
 * o vetor h que, sabe-se, tem dimensão igual a 10. Por exemplo, se for passado como
 * entrada o vetor:
 *
 *      v = {0.11,0.2,0.03,0.56,0.323,0.345,0.234,0.56,0.6546,0.123,0.123,0.999}
 *
 * a função deve preencher o vetor h como:
 * 
 *                          h = {1,3,2,2,0,2,1,0,0,1}
 *
 * A função deve seguir o protótipo:
 *
 *      void histograma (int n, float *v, int *h);
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void histograma(int n, float *v, int *h)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (v[i] < j * .1 + .1) {
				h[j]++;
				break;
			}
		}
	}
}

int main(void)
{
	float v[N];
	int h[10] = { 0 };

	srand(time(NULL));

	for (int i = 0; i < N; i++) {
		int n1 = rand();
		int n2 = rand();

		v[i] = (float)(n1 < n2 ? n1 : n2) / (n1 > n2 ? n1 : n2);
		printf("%.2f ", v[i]);
	}
	puts("");

	histograma(N, v, h);
	for (int i = 0; i < 10; i++) {
		printf("%d ", h[i]);
	}
	puts("");

	return 0;
}
