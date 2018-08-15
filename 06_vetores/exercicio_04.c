/*
 * Escreva versões recursivas das funções dos exercícios anteriores e teste-as.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

#define imprime(n,v,fmt) 	\
	for(int i=0;i<n;i++){  	\
		printf(fmt,v[i]); 	\
	}						\
	puts("");				\

int pares(int n, int *vet)
{
	if (n != 0) {
		return (vet[0] % 2 == 0) + pares(n - 1, vet + 1);
	}
	return 0;
}

void inverte(int n, int *vet)
{
	if (n > 1) {
		int t = vet[0];
		vet[0] = vet[n - 1];
		vet[n - 1] = t;
		inverte(n - 2, vet + 1);
	}
}

float minimo(int n, float *v)
{
	if (1 == n) {
		return v[0];
	}
	int minsub = minimo(n - 1, v + 1);
	return v[0] < minsub ? v[0] : minsub;
}

int main(void)
{
	int np, vi[N];
	float min, vf[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		vi[i] = rand() % 100;
		vf[i] = rand() % 100;
	}

	imprime(N, vi, "%d ");
	np = pares(N, vi);
	printf("Pares = %d\n", np);

	inverte(N, vi);
	imprime(N, vi, "%d ");

	puts("");
	imprime(N, vf, "%.2f ");
	min = minimo(N, vf);
	printf("Minimo = %.2f\n", min);

	return 0;
}
