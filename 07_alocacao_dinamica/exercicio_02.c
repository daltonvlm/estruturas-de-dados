/*
 * Escreva uma função que receba um vetor de inteiros e tenha como valor de retorno
 * um novo vetor, alocado dinamicamente, apenas com os elementos pares do vetor
 * original. A função deve ter como valor de retorno o ponteiro do vetor alocado e
 * preencher o endereço de memória passado com a dimensão do novo vetor, seguindo
 * o protótipo:
 *
 *      int* somente_pares (int n, int* v, int* npares);
 */

#include<stdio.h>
#include<stdlib.h>

#define N 10

int *somente_pares(int n, int *v, int *npares)
{
	int c = 0;
	int *p = NULL;

	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) {
			c++;
		}
	}

	if (c > 0) {
		p = (int *)malloc(sizeof(int));
		if (NULL != p) {
			for (int i = 0, j = 0; j < n; j++) {
				if (v[j] % 2 == 0) {
					p[i++] = v[j];
				}
			}
		}
	}

	*npares = c;
	return p;
}

int main(void)
{
	int np, *p;
	int v[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	p = somente_pares(N, v, &np);

	for (int i = 0; i < np; i++) {
		printf("%d ", p[i]);
	}
	puts("");

	free(p);
	return 0;
}
