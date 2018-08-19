/*
 * Reescreva as funções para calcular a soma e o produto de polinômios representados
 * por vetores para considerar que os dois polinômios de entrada possam ter graus
 * diferentes. Os coeficientes não existentes no polinômio de menor  grau têm valores
 * nulos, mas não são representados no vetor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void soma(int na, float *a, int nb, float *b, float *c)
{
	int i;
	for (i = 0; i < na && i < nb; i++) {
		c[i] = a[i] + b[i];
	}
	for (; i < na; i++) {
		c[i] = a[i];
	}
	for (; i < nb; i++) {
		c[i] = b[i];
	}
}

void produto(int na, float *a, int nb, float *b, float *c)
{
	int nc = 2 * (na > nb ? na : nb) - 1;
	for (int k = 0; k < nc; k++) {
		c[k] = 0;
		for (int i = 0; i <= k; i++) {
			if (i < na && (k - i) < nb) {
				c[k] += a[i] * b[k - i];
			}
		}
	}
}

static void imprime(int n, float *v)
{
	printf("(%.2f)", v[0]);
	for (int i = 1; i < n; i++) {
		printf(" + (%.2f * x^%d)", v[i], i);
	}
	puts("");
}

static void popula(int n, float *v)
{
	for (int i = 0; i < n; i++) {
		v[i] = rand() % 10 + 1;
	}
}

int main(void)
{
	int na, nb, nc;
	float a[N], b[N], c[2 * N - 1] = { 0 };

	srand(time(NULL));
	na = rand() % N + 1;
	nb = rand() % N + 1;
	nc = na > nb ? na : nb;

	popula(na, a);
	imprime(na, a);
	popula(nb, b);
	imprime(nb, b);

	printf("soma: ");
	soma(na, a, nb, b, c);
	imprime(nc, c);

	printf("produto: ");
	produto(na, a, nb, b, c);
	imprime(nc, c);
	return 0;
}
