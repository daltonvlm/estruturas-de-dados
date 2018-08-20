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

#include <stdio.h>
#include <stdlib.h>

static void check(void *p)
{
	if (!p) {
		perror("Erro:");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

float *reverso(int n, float *v)
{
	float *r = (float *)aloca(n * sizeof(float));
	for (int i = 0; i < n; i++) {
		printf("%f\n", v[n - 1 - i]);
		r[i] = v[n - 1 - i];
	}
	return r;
}

static void popula(int n, float *v)
{
	puts("Entre com os valores:");
	for (int i = 0; i < n; i++) {
		scanf("%f", v + i);
	}
}

static void imprime(int n, float *v, char *fmt, char *end)
{
	for (int i = 0; i < n; i++) {
		printf(fmt, v[i]);
	}
	printf(end);
}

int main(void)
{
	int n;
	float *v, *r;
	while (1) {
		printf("Entre com o tamanho do vetor: ");
		scanf("%d", &n);
		v = (float *)aloca(n * sizeof(float));
		popula(n, v);
		r = reverso(n, v);
		imprime(n, r, "%.2f ", "\n");
		free(r);
	}
	return 0;
}
