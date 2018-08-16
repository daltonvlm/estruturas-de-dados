/*
 * Escreva um programa que capture do teclado o número de segundos transcorridos
 * num evento e imprima o tempo no formato hora-minuto-segundo: h:m:s, onde hora
 * e minuto são exibidos com dois dígitos, preenchidos com zero à esquerda ("%02d"), e
 * segundo exibido com duas casas decimais, também preenchido com zero à esquerda
 * (%05.2f).
 */

#include <stdio.h>

int main(void)
{
	int HORA = 3600;
	int MINUTO = 60;
	int h, m, s;
	printf("t: ");
	scanf("%d", &s);
	h = s / (HORA);
	s = s - h * HORA;
	m = s / MINUTO;
	s = s - m * MINUTO;
	printf("t: %02d:%02d:%05.2f\n", h, m, (float)s);
	return 0;
}
