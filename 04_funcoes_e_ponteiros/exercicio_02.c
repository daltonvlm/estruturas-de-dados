/*
 * O máximo divisor comum de três números inteiros positivos, MDC(x,y,z), é igual
 * a MDC(MDC(x,y),z). Escreva um programa que capture três números inteiros
 * fornecidos via teclado e imprima o MDC deles, usando a função MDC apresentada
 * no texto.
 */

#include <stdio.h>

int mdc(int x, int y)
{
	int r = x % y;
	if (0 == r) {
		return y;
	}
	return mdc(y, r);
}

int main(void)
{
	int x, y, z;

	printf("x, y, z: ");
	scanf("%d %d %d", &x, &y, &z);

	printf("mdc(%d, %d, %d) = %d\n", x, y, z, mdc(mdc(x, y), z));
	return 0;
}
