/*
 * Escreva um programa que implemente o jogo conhecido como pedra, papel, tesoura.
 * Neste jogo, o usuário e o computador escolhem entre pedra, papel ou tesoura. Sa-
 * bendo que pedra ganha de tesoura, papel ganha de pedra e tesoura ganha de papel,
 * exiba na tela o ganhador: usuário ou computador. Para esta implementação, as-
 * suma que o número 0 representa pedra, 1 representa papel e 2 representa tesoura.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int usuario;
	int computador;

	printf("Esolha pedra (0), papel (1) ou tesoura (2): ");
	scanf("%d", &usuario);

	srand(time(NULL));
	computador = rand() % 3;
	if (!computador) {
		printf("Computador: pedra\n");
	} else if (1 == computador) {
		printf("Computador: papel\n");
	} else {
		printf("Computador: tesoura\n");
	}

	switch (usuario - computador) {
	case 1:
	case -2:
		puts("Voce (usuario) ganhou!");
		break;
	case -1:
	case 2:
		puts("Eu (computador) ganhei!");
		break;
	default:
		puts("Empatamos!");
	}
	return 0;
}
