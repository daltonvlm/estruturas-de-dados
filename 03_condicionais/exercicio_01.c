/*
 * Escreva um programa em C que receba três números inteiros como entrada e im-
 * prima, como saída, o maior número recebido.
 */

#include <stdio.h>

int main(void)
{
	int a, b, c, maior;
	printf("a, b, c: ");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b && a > c) {
		maior = a;
	} else if (b > c) {
		maior = b;
	} else {
		maior = c;
	}
	printf("maior: %d\n", maior);
	return 0;
}
