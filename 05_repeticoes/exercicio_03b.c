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
		int x, f;
		printf("\nx: ");
		scanf("%d", &x);
		for (int i = 0; (f = fibonacci(i)) < x; i++) ;
		if (f == x) {
			printf("pertence\n");
		} else {
			printf("nao pertence\n");
		}
	}
	return 0;
}
