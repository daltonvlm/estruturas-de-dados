/*
 * Escreva uma função que verifique se uma matriz quadrada de dimensão N x N,
 * onde N representa uma constante simbólica, é uma matriz identidade. Numa matriz
 * identidade, os elementos da diagonal principal são iguais a 1.0 e os demais são iguais
 * a 0.0. A função deve retornar 1 se a matriz dada for identidade e 0 caso contrário,
 * e deve seguir o seguinte protótipo:
 *
 *      int identidade (double A[][N]);
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

int identidade(double A[][N])
{
	for (int i = 0; i < N; i++) {
		if (A[i][i] != 1) {
			return 0;
		}
		for (int j = 0; j < i; j++) {
			if (A[i][j] != 0 || A[j][i] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

static void imprime(double A[][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%5.2f ", A[i][j]);
		}
		puts("");
	}
}

int main(void)
{
	srand(time(NULL));

	puts("\nGerando matriz identidade...");
	while (1) {
		int max = 6;
		double m[N][N];

		for (int i = 0; i < N; i++) {
			m[i][i] = rand() % max;
			for (int j = 0; j < i; j++) {
				m[i][j] = rand() % max;
				m[j][i] = rand() % max;
			}
		}

		if (identidade(m)) {
			imprime(m);
			getchar();
			puts("Gerando matriz identidade...");
		}
	}
	return 0;
}
