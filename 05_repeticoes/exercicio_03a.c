/*
 * Considerando a função que avalia o valor do n-ésimo termo da série de Fibonacci,
 * escreva um programa para:
 *
 * (a) Imprimir os primeiros n termos da série, onde n é fornecido via teclado.
 * (b) Determinar se um valor x, fornecido via teclado, pertence ou não à série.
 */

#include <stdio.h>

int fibonacci(int n)
{
	if (n < 2) {
		return n;
	}
	int a = 0, b = 1;
	for (int i = 2; i <= n; i++) {
		b += a;
		a = b - a;
	}
	return b;
}

int main(void)
{
	while (1) {
		int n;
		printf("\nn: ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			printf("%d\n", fibonacci(i));
		}
	}
	return 0;
}
