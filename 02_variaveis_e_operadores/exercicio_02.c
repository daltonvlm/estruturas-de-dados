/*
 * Escreva um programa que calcule o preço da gasolina por litro no Brasil se aqui fosse
 * adotado o mesmo preço cobrado nos Estados Unidos. O programa deve capturar
 * dois valores fornecidos via teclado: o preço do galão de gasolina praticado nos
 * Estados Unidos (em dólares) e a taxa de conversão do dólar para o real. O programa
 * então deve exibir o preço do litro de gasolina correspondente em reais. Sabe-se que
 * um galão tem 3.7854 litros.
 */

#include <stdio.h>

int main(void)
{
	float prc_gas, prc_gal, tx;
	float vlm_gal = 3.7854f;
	printf("preco do galao: ");
	scanf("%f", &prc_gal);
	printf("taxa de conversao: ");
	scanf("%f", &tx);
	prc_gal *= tx;
	prc_gas = prc_gal / vlm_gal;
	printf("preco por litro: R$%.2f\n", prc_gas);
	return 0;
}
