/*
 * Implemente uma função que receba como parâmetros um vetor de números inteiros
 * v e seu número de elementos n, e verifique se os elementos do vetor correspondem aos
 * termos de uma PA (progressão aritmética), isto é, se existe um número inteiro k tal
 * que v[i] seja igual a v[0] + i*k. Caso os elementos do vetor correspondam aos
 * termos de uma PA, a função deve retornar o valor calculado para k. Por exemplo,
 * se for passado para essa função o vetor {2,10,18,26,34}, ela deve retornar o valor
 * 8. Caso o vetor não corresponda a uma PA, a função deve retornar 0. Assuma
 * que o vetor sempre terá pelo menos três elementos. Tal função deve ter o seguinte
 * protótipo:
 *
 *      int testa_PA (int n, int *v);
 */

#include <stdio.h>

#define N 10

int testa_PA(int n, int *v)
{
	int k = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		if (v[i] != v[0] + k * i) {
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	while (1) {
		int pa, n, v[N];

		printf("\nn: ");
		scanf("%d", &n);

		if (n > N) {
			printf("Entre com um valor menor ou igual a %d\n", N);
			continue;
		}

		printf("valores: ");
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		pa = testa_PA(n, v);
		printf("pa = %d\n", pa);
	}
	return 0;
}
