/*
 * Escreva funções para lidar com matrizes triangulares inferiores de dimensão n x n,
 * onde todos os elementos abaixo da diagonal são iguais a zero e não devem ser
 * alocados. No entanto, um acesso a um elemento abaixo da diagonal deve retornar
 * o valor zero. Escreva as seguintes funções, usando a estratégia de vetor de ponteiros
 * para armazenar a matriz.
 *
 *  (a) Função para criar uma matriz, onde n representa a dimensão da matriz, ini-
 *  cialmente com os valores todos iguais a zero:
 *
 *          float** ti_cria (int n);
 *
 *  (b) Função para atribuir o valor de um elemento da matriz, assumindo que i >= j:
 *          
 *          void ti_atribui (int i, int j, float x);
 *
 *  (c) Função para acessar o valor de um elemento da matriz, inclusive elementos
 *      acima da diagonal:
 *
 *          float ti_acessa (int i, int j);
 *
 *  (d) Função para liberar a memória da matriz alocada:
 *
 *          void ti_libera (int n, float** mat);
 *
 * Escreva uma função main para testar as funções implementadas.
 */

/* 
 * Alguns cabeçalhos estão incompletos.
 * No entanto, creio que seja possível inferir a intenção do autor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void check(void *p)
{
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

float **ti_cria(int n)
{
	float **mat = (float **)aloca(n * sizeof(float *));
	for (int i = 0; i < n; i++) {
		mat[i] = (float *)aloca((i + 1) * sizeof(float));
		for (int j = 0; j <= i; j++) {
			mat[i][j] = 0;
		}
	}
	return mat;
}

void ti_atribui(int i, int j, float x, float **mat)
{
	if (i >= j) {
		mat[i][j] = x;
	}
}

float ti_acessa(int i, int j, float **mat)
{
	return i >= j ? mat[i][j] : 0;
}

void ti_libera(int n, float **mat)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}

int main(void)
{
	int n = 3;
	float **mat = (float **)ti_cria(n);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = rand() % 10;
			printf("Gerado valor %d\n", x);
			ti_atribui(i, j, x, mat);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.1f ", ti_acessa(i, j, mat));
		}
		puts("");
	}
	ti_libera(n, mat);
	return 0;
}
