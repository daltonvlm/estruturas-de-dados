/* 
 * Compare a eficiência do algoritmo heapsort com o algoritmo de ordenação rápida
 * (qsort) da biblioteca padrão. Compare a eficiência para diferentes entradas, com
 * diferentes números de valores. Se possível, contrua gráficos de eficiência dos algo-
 * ritmos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hsortgen.h"

#define N 10
#define MIN_DIM 500
#define MAX_DIM 10000

static int cmp(const void *v1, const void *v2)
{
	float *f1 = (float *)v1;
	float *f2 = (float *)v2;

	if (*f1 < *f2) {
		return -1;
	}
	if (*f1 > *f2) {
		return 1;
	}
	return 0;
}

static void imprime(float *v, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%f\n", v[i]);
	}
	puts("");
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

static double benchmark_qsort(int n)
{
	clock_t ti, tf;
	float *v = (float *)aloca(n * sizeof(float));

	srand(0);
	for (int i = 0; i < n; i++) {
		v[i] = (float)((double)rand() / RAND_MAX);
	}

	ti = clock();
	qsort(v, n, sizeof(float), cmp);
	tf = clock();

	free(v);
	return (double)(tf - ti) / CLOCKS_PER_SEC;
}

static double benchmark_hsort(int n)
{
	clock_t ti, tf;
	float *v = (float *)aloca(n * sizeof(float));

	srand(0);
	for (int i = 0; i < n; i++) {
		v[i] = (float)((double)rand() / RAND_MAX);
	}

	ti = clock();
	hsort(v, n, sizeof(float), cmp);
	tf = clock();

	free(v);
	return (double)(tf - ti) / CLOCKS_PER_SEC;
}

int main(void)
{
	while (1) {
		srand(time(NULL));
		int n = rand() % (MAX_DIM - MIN_DIM) + MIN_DIM;
		double bqs = benchmark_qsort(n);
		double bhs = benchmark_hsort(n);
		printf("n = %d\n", n);
		printf("Tempo qsort = %f segundos\n", bqs);
		printf("Tempo hsort = %f segundos\n", bhs);
		getchar();
	}
	return 0;
}
