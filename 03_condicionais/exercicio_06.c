/*
 * Modifique o programa do jogo "par ou ímpar" apresentado para que, em vez de o
 * usuário, o computador escolha, de forma aleatória, se quer par ou ímpar. O usuário
 * apenas fornece seu número.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int escolha;		/* escolha do computador: 0=par, 1=ímpar */
	int usuario;		/* número fornecido pelo usuário */
	int computador;		/* número gerado pelo computador */

	srand(time(NULL));
	escolha = rand() % 2;
	printf("Eu (computador) escolhi %s.\n", escolha ? "impar" : "par");
	printf("Entre com o seu numero: ");
	scanf("%d", &usuario);

	/* gera número do computador e exibe */
	computador = rand() % 10;
	printf("Computador: %d\n", computador);

	/* testa se soma é par ou ímpar, com escolha do usuário */
	if (((usuario + computador) % 2) == escolha) {
		printf("Eu (computador) ganhei!\n");
	} else {
		printf("Voce (usuario) ganhou!\n");
	}
	return 0;
}
