/*
 * Altere o programa em C apresentado para que ele faça a conversão inversa: capture
 * do teclado um valor de temperatura em Fahrenheit e exiba na tela o valor em Celsius
 * correspondente.
 */

#include <stdio.h>

int main(void)
{
	float f;
	float c;
	printf("Entre com a temperatura em Fahrenheit: ");
	scanf("%f", &f);
	c = (f - 32) / 1.8;
	printf("Temperatura em Celsius: %f\n", c);
	return 0;
}
