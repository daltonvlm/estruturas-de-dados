/*
 * Implemente uma função iterativa para calcular o máximo divisor comum de dois
 * números inteiros positivos, MDC(X,Y), usando o algoritmo de Euclides. Este algo-
 * ritmo é baseado no fato de que se o resto da divisão de x por y, representado por
 * r, for igual a zero, y é o MDC. Se o resto for diferente de zero, o MDC de x e y
 * é igual ao MDC de y e r. O processo se repete até que o valor do resto da divisão
 * seja zero.
 */

int mdc(int x, int y)
{
	int r;
	while ((r = x % y) != 0) {
		x = y;
		y = r;
	}
	return y;
}
