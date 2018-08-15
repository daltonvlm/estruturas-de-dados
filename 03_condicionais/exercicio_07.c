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
	int usuario, computador;

	printf("pedra (0), papel (1), tesoura (2): ");
	scanf("%d", &usuario);

	srand(time(NULL));
	computador = rand() % 3;
	printf("computador: %d ", computador);

	if (0 == computador) {
		printf("(pedra)\n");
	} else if (1 == computador) {
		printf("(papel)\n");
	} else {
		printf("(tesoura)\n");
	}

	switch (usuario - computador) {
	case -1:
	case 2:
		printf("computador ganhou!\n");
		break;
	case 0:
		printf("empate!\n");
		break;
	case 1:
	case -2:
		printf("usuario ganhou!\n");
	}
	return 0;
}
