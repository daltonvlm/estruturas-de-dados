/*
 * Considere as equações de movimento para calcular a posição (s) e a velocidade (v)
 * de uma partícula em determinado instante t, dado sua aceleração a, posição inicial
 * s0 e velocidade inicial v0, de acordo com as fórumulas:
 *
 *                                  s = s0 + v0t + (at^2)/2
 *                                  v = v0 + at
 *
 * Escreva um programa em C completo que capture os valores de s0, v0, a e t, fornecidos
 * pelo usuário via teclado, e calcule e exiba os valores de s e v. Todos os valores
 * tratados no programa devem ser números reais (float ou double).
 */

#include <stdio.h>

int main(void)
{
	float s0, v0, a, t, s, v;
	printf("s0, v0, a, t: ");
	scanf("%f %f %f %f", &s0, &v0, &a, &t);
	s = s0 + v0 * t + (a * t * t) / 2;
	v = v0 + a * t;
	printf("s = %f\n", s);
	printf("v = %f\n", v);
	return 0;
}
