/*
 * A série de Fibonacci é formada pela seguinte sequência de números:
 *
 *                                  0,1,2,3,5,8,13,21,...
 *
 * O primeiro número da série é 0, o segundo é 1 e os demais são a soma dos dois nú-
 * meros anteriores. Podemos então definir o valor de um termo da série de Fibonacci
 * como sendo:
 *
 *                             | 0                      se i = 0
 *                      F(i) = | 1                      se i = 1
 *                             | F(i - 2) + F(i - 1)    se i > 1
 *
 * Escreva uma função recursiva que retorna o valor do i-ésimo termo da série de
 * Fibonacci. Faça uma função main para imprimir os primeiros 13 termos da série
 * de Fibonacci. Note que a implementação recursiva para a determinação de um
 * termo da série de Fibonacci não é eficiente computacionalmente: um mesmo termo
 * é avaliado múltiplas vezes. Por exemplo, F(3) é avaliado 55 vezes na avaliação do
 * termo F(13)!
 */

#include <stdio.h>

int fibonacci(int i)
{
	if (i < 2) {
		return i;
	}
	return fibonacci(i - 1) + fibonacci(i - 2);
}

int main(void)
{
	for (int i = 0; i < 13; i++) {
		printf("f(%d) = %d\n", i, fibonacci(i));
	}
	return 0;
}
