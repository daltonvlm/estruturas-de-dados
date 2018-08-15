/*
 * Considerando a função que determina se um número é ou não primo, escreva um programa para:
 *
 * (a) Imprimir todos os números primos menores que um valor x, fornecido via
 *     teclado.
 *
 * (b) Imprimir os primeiros n números primos, onde n é fornecido via teclado.
 */

#include <stdio.h>
#include <math.h>

int primo(int n)
{
	if (2 == n) {
		return 1;
	}
	if (n < 2 || n % 2 == 0) {
		return 0;
	}
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	while (1) {
		int x;
		printf("\nx: ");
		scanf("%d", &x);
		for (int i = 2; i < x; i++) {
			int p = primo(i);
			if (p) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
