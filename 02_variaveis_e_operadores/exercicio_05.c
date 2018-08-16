/*
 * Considerando a existência de notas (cédulas) nos valores R$ 100, R$ 50, R$ 20,
 * R$ 10, R$ 5, R$ 2 e R$ 1, escreva um programa que capture um valor inteiro
 * em reais (R$) e determine o menor número de notas para se obter o montante
 * fornecido. O programa deve exibir o número de notas para cada um dos valores de
 * nota existentes.
 */

#include <stdio.h>

int main(void)
{
	int c1, c2, c5, c10, c20, c50, c100;
	int v;
	printf("R$ ");
	scanf("%d", &v);
	c100 = v / 100;
	v -= c100 * 100;
	c50 = v / 50;
	v -= c50 * 50;
	c20 = v / 20;
	v -= c20 * 20;
	c10 = v / 10;
	v -= c10 * 10;
	c5 = v / 5;
	v -= c5 * 5;
	c2 = v / 2;
	v -= c2 * 2;
	c1 = v;
	printf("%d * R$100,00\n", c100);
	printf("%d * R$50,00\n", c50);
	printf("%d * R$20,00\n", c20);
	printf("%d * R$10,00\n", c10);
	printf("%d * R$5,00\n", c5);
	printf("%d * R$2,00\n", c2);
	printf("%d * R$1,00\n", c1);
	return 0;
}
