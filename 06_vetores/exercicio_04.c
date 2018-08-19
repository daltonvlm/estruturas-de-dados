/*
 * Escreva versões recursivas das funções dos exercícios anteriores e teste-as.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

#define imprime(n,vet,fmt)      \
    for(int i=0; i<n; i++){     \
        printf(fmt,vet[i]);     \
    }                           \
    puts("");

int pares(int n, int *vet)
{
	if (1 == n) {
		return !(vet[0] % 2);
	}
	return !(vet[0] % 2) + pares(n - 1, vet + 1);
}

void inverte(int n, int *vet)
{
	if (n > 1) {
		int tmp = vet[0];
		vet[0] = vet[n - 1];
		vet[n - 1] = tmp;
		inverte(n - 2, vet + 1);
	}
}

float minimo(int n, float *v)
{
	if (1 == n) {
		return v[0];
	}
	float minsub = minimo(n - 1, v + 1);
	return v[0] < minsub ? v[0] : minsub;
}

int main(void)
{
	int npares, vet[N];
	float min, fvet[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		vet[i] = rand() % 100;
		fvet[i] = rand() % 100;
	}

	imprime(N, vet, "%d ");
	npares = pares(N, vet);
	printf("pares = %d\n", npares);
	inverte(N, vet);
	printf("invertido: ");
	imprime(N, vet, "%d ");

	imprime(N, fvet, "%.1f ");
	min = minimo(N, fvet);
	printf("minimo = %.1f\n", min);
	return 0;
}
