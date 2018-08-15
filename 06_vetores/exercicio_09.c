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
	int min = na < nb ? na : nb;
	int i;

	for (i = 0; i < min; i++) {
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
	int max = na > nb ? na : nb;
	int m = 2 * max - 1;
	for (int k = 0; k < m; k++) {
		c[k] = .0f;
		for (int i = 0; i <= k; i++) {
			if (i < na && k - i < nb) {
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

static void preenche(int n, float *v)
{
	for (int i = 0; i < n; i++) {
		v[i] = rand() % 10 + 1;
	}
}

int main(void)
{
	int na, nb, maior;
	float a[N], b[N], c[2 * N - 1] = { 0 };

	srand(time(NULL));
	na = rand() % N + 1;
	nb = rand() % N + 1;
	maior = na > nb ? na : nb;

	preenche(na, a);
	preenche(nb, b);
	imprime(na, a);
	imprime(nb, b);

	printf("soma: ");
	soma(na, a, nb, b, c);
	imprime(maior, c);

	printf("produto: ");
	produto(na, a, nb, b, c);
	imprime(2 * maior - 1, c);
	return 0;
}
