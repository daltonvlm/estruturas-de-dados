/*
 * Reescreva o programa que calcula as raízes de uma equação do segundo grau do
 * capítulo anterior. Nesta nova versão, escreva uma função que calcula as raízes da
 * equação. A função deve retornar o número de raízes reais existentes e preencher os
 * endereços passados com os valores das raízes correspondentes, seguindo o protótipo:
 *
 *      int raizes (double a, double b, double c, double* px1, double* px2);
 *
 * A função main deve capturar os valores dos coeficientes, fornecidos via teclado,
 * chamar a função e exibir os resultados.
 */

#include <stdio.h>
#include <math.h>

int raizes(double a, double b, double c, double *px1, double *px2)
{
	if (0 == a) {
		*px1 = -c / b;
		return 1;
	}
	double delta = b * b - 4 * a * c;
	if (delta < 0) {
		return 0;
	}
	delta = sqrt(delta);
	*px1 = (-b - delta) / (2 * a);
	if (delta) {
		*px2 = (-b + delta) / (2 * a);
		return 2;
	}
	return 1;
}

int main(void)
{
	double a, b, c;
	double x1, x2;
	int n;

	printf("a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	n = raizes(a, b, c, &x1, &x2);
	if (0 == n) {
		printf("S = {}\n");
	} else if (1 == n) {
		printf("S = {%f}\n", x1);
	} else {
		printf("S = {%f, %f}\n", x1, x2);
	}
	return 0;
}
