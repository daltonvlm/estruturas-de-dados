/*
 * Reescreva as funções para calcular a soma e o produto de polinômios representados
 * por vetores para considerar que os dois polinômios de entrada possam ter graus
 * diferentes. Os coeficientes não existentes no polinômio de menor  grau têm valores
 * nulos, mas não são representados no vetor.
 */

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
