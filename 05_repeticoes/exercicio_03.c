/*
 * Considerando a função que avalia o valor do n-ésimo termo da série de Fibonacci,
 * escreva um programa para:
 *
 * (a) Imprimir os primeiros n termos da série, onde n é fornecido via teclado.
 * (b) Determinar se um valor x, fornecido via teclado, pertence ou não à série.
 */

#include<stdio.h>

static int fibonacci(int i)
{
	if (i < 2) {
		return i;
	}
	int a = 1;
	int b = 1;
	for (int j = 2; j <= i; j++) {
		b += a;
		a = b - a;
	}
	return b;
}

void a(void)
{
	while (1) {
		int n;
		printf("n: ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			printf("%d ", fibonacci(i));
		}
		puts("");
	}
}

void b(void)
{
	while (1) {
		int i = 0;
		int x, f;
		printf("x: ");
		scanf("%d", &x);
		do {
			f = fibonacci(i);
			i++;
		} while (f < x);
		printf("%s\n", f == x ? "Pertence" : "Nao pertence");
	}
}

int main(void)
{
	//a();
	b();
	return 0;
}
