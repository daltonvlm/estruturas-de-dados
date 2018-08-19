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

#define N 5

int identidade(double A[][N])
{
	for (int i = 0; i < N; i++) {
		if (A[i][i] != 1) {
			return 0;
		}
		for (int j = 0; j < i; j++) {
			if (A[i][j] || A[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

void imprime(double A[][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%.1f ", A[i][j]);
		}
		puts("");
	}
}

int main(void)
{
	double mat[N][N];
	srand(time(NULL));
	puts("\nGerando matriz identidade...");
	while (1) {
		for (int i = 0; i < N; i++) {
			mat[i][i] = rand() % 2;
			for (int j = 0; j < i; j++) {
				mat[i][j] = rand() % 2;
				mat[j][i] = rand() % 2;
			}
		}
		if (identidade(mat)) {
			imprime(mat);
			printf("\nTecle Enter para continuar: ");
			getchar();
			puts("\nGerando matriz identidade...");
		}
	}
	return 0;
}
