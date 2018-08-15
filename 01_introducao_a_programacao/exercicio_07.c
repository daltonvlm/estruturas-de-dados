/* 
 * Digite, compile e execute o programa em C para conversão de temperatura apre-
 * sentado.
 */

/* Programa para converter temperatura de Celsius para Fahrenheit */

#include <stdio.h>		/* biblioteca auxiliar de entrada e saída */

int main(void)
{
	float c;		/* espaço para armazenar temperatura em Celsius */
	float f;		/* espaço para armazenar temperatura em Fahrenheit */

	/* captura valor fornecido via teclado */
	printf("Entre com temperatura em Celsius: ");
	scanf("%f", &c);

	/* faz a conversão */
	f = 1.8 * c + 32;

	/* exibe resultado na tela */
	printf("Temperatura em Fahrenheit: %f\n", f);

	return 0;
}
