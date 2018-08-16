/*
 * Escreva um programa em C quer receba três números inteiros como entrada e im-
 * prima, como saída, os números em ordem crescente.
 */

#include <stdio.h>

int main(void)
{
	int a, b, c;
	int maior, medio, menor;
	printf("a, b, c: ");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b && a > c) {
		maior = a;
		medio = b;
		menor = c;
		if (c > b) {
			medio = c;
			menor = b;
		}
	} else if (b > c) {
		maior = b;
		medio = a;
		menor = c;
		if (c > a) {
			medio = c;
			menor = a;
		}
	} else {
		maior = c;
		medio = a;
		menor = b;
		if (b > a) {
			medio = b;
			menor = a;
		}
	}
	printf("%d %d %d\n", menor, medio, maior);
	return 0;
}
