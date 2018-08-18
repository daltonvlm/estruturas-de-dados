/*
 * Implemente um jogo de adivinhação. O computador "escolhe" (gera aleatória-
 * mente) um número entre 1 e 1024, e o usuário tenta adivinhar o número escolhido.
 * Para cada tentativa do usuário, o programa deve exibir na tela:
 *
 * . o número -1, se o número gerado for menor do que o número fornecido pelo usuário;
 * . o número 1, se o número gerado for maior que o número fornecido pelo usuário;
 * . o número 0, se o número gerado for igual ao fornecido pelo usuário. Neste
 *   caso, o programa deve exibir o número de tentativas usadas pelo usuário para
 *   acertar a escolha do computador e finalizar a execução.
 *
 * Implemente e teste este jogo, verificando a média de tentativas que você precisa
 * para acertar o número escolhido pelo computador.
 * 
 * Em seguida, implemente o jogo no qual o usuário e computador trocam de funções.
 * Agora, o usuário pensa num número entre 1 e 1024 e o computador tenta acertar.
 * Para cada tentativa feita pelo computador, o usuário deve entrar com os números
 * -1, 1 ou 0, indicando que o número pensado é menor, maior ou igual ao número
 *  exibido pelo computador, respectivamente.
 *
 *  Logicamente, as tentativas feitas pelo computador devem seguir uma determinada
 *  estratégia. Você seria capaz de implementar uma estratégia adequada? Saiba que
 *  uma boa estratégia garante que o computador precisa de no máximo 10 tentativas
 *  para acertar o número!
 *
 *  Quem é melhor nete jogo de adivinhação: você ou o computador?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 1024

void usuario_adivinha(void)
{
	int jogos = 0;
	int total_palpites = 0;
	char opcao = 'N';

	srand(time(NULL));
	do {
		int escolha = rand() % (MAX - MIN + 1) + MIN;
		int palpites = 0;
		int palpite;

		jogos++;
		printf("Numero entre %d e %d sorteado, tente adivinhar!\n", MIN,
		       MAX);
		do {
			printf("\nPalpite: ");
			scanf("%d", &palpite);
			palpites++;

			if (escolha < palpite) {
				puts("-1");
			} else if (escolha > palpite) {
				puts("1");
			} else {
				puts("0");
			}
		} while (palpite != escolha);

		total_palpites += palpites;

		printf("\nAcertou!\nPalpites: %d\n", palpites);
		printf("Deseja continuar [sN]? ");
		scanf(" %c", &opcao);
	} while ('s' == opcao);

	float media = (float)total_palpites / jogos;
	printf("\nJogos: %d\nTotal de palpites: %d\nMedia: %f\n", jogos,
	       total_palpites, media);
}

void computador_adivinha(void)
{
	int jogos = 0;
	int total_palpites = 0;
	char opcao = 'N';

	do {
		int escolha;
		int palpites = 0;
		int palpite;
		int min = MIN;
		int max = MAX;

		jogos++;
		printf("\nEscolha um numero entre %d e %d: ", MIN, MAX);
		scanf("%d", &escolha);
		do {
			int resposta;

			if (min > max) {
				printf("\nO jogador está trapaceando!");
				palpites = 1;
				break;
			}
			palpites++;
			palpite = (min + max) / 2;
			printf("%d? ", palpite);
			scanf("%d", &resposta);

			if (-1 == resposta) {
				max = palpite - 1;
			} else {
				min = palpite + 1;
			}
		} while (palpite != escolha);

		total_palpites += palpites;

		printf("\nComputador acertou!\nPalpites: %d\n", palpites);
		printf("Deseja continuar [sN]? ");
		scanf(" %c", &opcao);
	} while ('s' == opcao);

	float media = (float)total_palpites / jogos;
	printf("\nJogos: %d\nTotal de palpites: %d\nMedia = %f\n", jogos,
	       total_palpites, media);
}

int main(void)
{
	//usuario_adivinha();
	computador_adivinha();
	return 0;
}
