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

/* A questão apresenta um erro conceitual, pois uma sequência constituida de 0s é também
 * uma PA. No entanto, da maneira como a questão está formulada, um retorno de 0 implicaria
 * que a sequência não constitui uma PA.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10

int testa_PA(int n, int *v)
{
	int k = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		if (v[i] != v[0] + i * k) {
			return 0;
		}
	}
	return k;
}

int main(void)
{
	int vet[N];
	while (1) {
		int n;
		printf("Entre com o numero de elementos (valor maximo = %d): ",
		       N);
		scanf("%d", &n);
		if (n < 0 || n > N) {
			fprintf(stderr, "Entrada invalida.\n");
			continue;
		} else if (!n) {
			break;
		}
		puts("Entre com os valores:");
		for (int i = 0; i < n; i++) {
			scanf("%d", vet + i);
		}
		printf("%s\n", testa_PA(n, vet) ? "E PA" : "Nao e PA");
	}
	return 0;
}
