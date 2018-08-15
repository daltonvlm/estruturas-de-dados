/*
 * A raiz quadrada de um número, raiz(n), pode ser avaliada através do seguinte algo-
 * ritmo: escolhe-se inicialmente um valor inicial qualquer, x0. Podemos, por exemplo,
 * escolher x0 = 1. A partir do valor inicial, avaliamos repetidas vezes um próximo
 * valor através da expressão a seguir, até que o valor de xi aproxime o valor de raiz(n)
 * dentro de certa tolerância.
 *
 *                              Xi+1 = (1/2) (Xi + n/Xi)
 *
 * Usando a contrução do-while, implemente uma função para calcular a raiz qua-
 * drada de um número real dentro de determinada tolerância. Para verificar se o
 * erro na avaliação da raiz quadrada está dentro da tolerância, basta verificar se
 * |(Xi x Xi) - n| < tol.
 */

#include <stdio.h>
#include <math.h>

float raiz(float n, float tol)
{
	float x0 = 1.f, x1;
	do {
		x1 = (1. / 2) * (x0 + n / x0);
		x0 = x1;
	} while (fabs((x1 * x1) - n) >= tol);
	return x1;
}

int main(void)
{
	while (1) {
		float n, tol;
		printf("\nn, tol: ");
		scanf("%f %f", &n, &tol);
		printf("%f\n", raiz(n, tol));
	}
	return 0;
}
