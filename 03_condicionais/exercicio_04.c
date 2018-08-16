/*
 * Escreva  um programa que converta coordenadas polares (raio r e ângulo a) em
 * coordenadas cartesianas (abscissa x e ordenada y), de acordo com as fórmulas:
 *
 *                                    x = r cos(a)
 *                                    y = r sin(a)
 *
 * O programa deve capturar os valores em coordenadas polares e exibir as coor-
 * denadas cartesianas correspondentes. As funções sin e cos estão disponíveis na
 * biblioteca matemática padrão.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	float r, a, x, y;
	printf("r, a: ");
	scanf("%f %f", &r, &a);
	x = r * cos(a);
	y = r * sin(a);
	printf("(%f, %f)\n", x, y);
	return 0;
}
