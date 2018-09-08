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

float raiz(float n, float tol)
{
	float x = 1;
	do {
		x = (x + n / x) / 2;
	} while (fabs(x * x - n) >= tol);
	return x;
}
