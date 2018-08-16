/*
 * Escreva um programa que converta um valor de ângulo dado em radianos para o
 * valor corresondente expresso em graus, minutos e segundos. Sabe-se que 1 radiano
 * equivale a 57.29578 graus. Escolha um formato de saída apropriado.
 */

#include <stdio.h>

int main(void)
{
	int g, m, s;
	float a;
	printf("radiano: ");
	scanf("%f", &a);
	a *= 57.29578;
	g = a;
	a -= g;
	a *= 60;
	m = a;
	a -= m;
	a *= 60;
	s = a;
	printf("grau: %ḍ°%d'%d''\n", g, m, s);
	return 0;
}
