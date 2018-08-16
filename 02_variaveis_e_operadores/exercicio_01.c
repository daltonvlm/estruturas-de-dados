/*
 * Escreva um programa que, dado o valor do raio via teclado, calcule e imprima o
 * volume da esfera correspondente. Sabe-se que o volume da esfera é dado por 4/3pir^3,
 * onde r representa o raio da esfera. Note que a linguagem C não disponibiliza um
 * operador de exponenciação (potenciação). Para calcular o valor de r^3 podemos
 * multiplicar o valor do raio por si mesmo duas vezes ou fazer o uso da função pow da
 * biblioteca padrão matemática (#include <math.h>).
 */

#include <stdio.h>

int main(void)
{
	float r, v;
	printf("r: ");
	scanf("%f", &r);
	v = 4.0 / 3 * 3.1415 * r * r * r;
	printf("v: %f\n", v);
	return 0;
}
