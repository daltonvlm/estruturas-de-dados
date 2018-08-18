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

static int primo(int n)
{
	if (2 == n) {
		return 1;
	}
	if (n < 2 || !(n % 2)) {
		return 0;
	}
	int r = sqrt(n);
	for (int i = 3; i <= r; i += 2) {
		if (!(n % i)) {
			return 0;
		}
	}
	return 1;
}

void a(void)
{
	while (1) {
		int x;
		printf("x: ");
		scanf("%d", &x);
		for (int i = 2; i < x; i++) {
			if (primo(i)) {
				printf("%d ", i);
			}
		}
		puts("");
	}
}

void b(void)
{
	while (1) {
		int n;
		printf("n: ");
		scanf("%d", &n);
		for (int i = 2; n; i++) {
			if (primo(i)) {
				printf("%d ", i);
				n--;
			}
		}
		puts("");
	}
}

int main(void)
{
	//a();
	b();
	return 0;
}
