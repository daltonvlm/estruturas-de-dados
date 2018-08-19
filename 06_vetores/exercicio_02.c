/*
 * Implemente uma função que receba como parâmetro um vetor de números inteiros
 * de tamanho n e inverta a ordem dos elementos armazenados nesse vetor. Essa
 * função deve obedecer ao protótipo a seguir. Escreva um programa para testar sua
 * função.
 *
 *      void inverte (int n, int* vet);
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void inverte(int n, int *vet)
{
	for (int i = 0; i < n / 2; i++) {
		int t = vet[i];
		vet[i] = vet[n - 1 - i];
		vet[n - 1 - i] = t;
	}
}

int main(void)
{
	int v[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		v[i] = rand() % N;
		printf("%d ", v[i]);
	}
	puts("");
	inverte(N, v);
	for (int i = 0; i < N; i++) {
		printf("%d ", v[i]);
	}
	puts("");
	return 0;
}
