/*
 * Escreva uma função de potenciação recursiva, considerando o expoente como sendo
 * um valor inteiro positivo (x^k, k > 0). A função deve seguir o protótipo:
 *
 *      double pot (double x, int k);
 *
 * Escreva uma função main para testar sua implementação; compare o resultado da
 * sua função com o valor retornado pela função de potenciação pow, existente na
 * biblioteca de matemática padrão de C.
 */

#include <stdio.h>
#include <math.h>

double pot(double x, int k)
{
	if (0 == k) {
		return 1;
	}
	return x * pot(x, k - 1);
}

int main(void)
{
	double x;
	int k;

	printf("x k: ");
	scanf("%lf %d", &x, &k);

	printf("pot(%f, %d) = %f\n", x, k, pot(x, k));
	printf("pow(%f, %d) = %f\n", x, k, pow(x, k));
	return 0;
}
