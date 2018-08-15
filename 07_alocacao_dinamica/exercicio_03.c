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
 * Acredito que alguns cabeçalhos das funções apresentadas no enunciado estejam incompletos.
 * No entanto, creio que seja possível inferir a intenção do autor.
 */

#include<stdio.h>
#include<stdlib.h>

float **ti_cria(int n);
void ti_atribui(int i, int j, float **mat, float x);
float ti_acessa(int i, int j, float **mat);
void ti_libera(int n, float **mat);

int main(void)
{
	int n = 4;
	float **mat = ti_cria(n);

	for (int i = 0, c = 1; i < n; i++) {
		for (int j = 0; j < n; j++, c++) {
			ti_atribui(i, j, mat, c);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5.2f ", ti_acessa(i, j, mat));
		}
		puts("");
	}

	ti_libera(n, mat);
	return 0;
}

float **ti_cria(int n)
{
	float **mat = (float **)malloc(n * sizeof(float *));

	if (mat != NULL) {
		for (int i = 0; i < n; i++) {

			mat[i] = (float *)malloc((n - i) * sizeof(int));
			if (NULL == mat[i]) {
				ti_libera(i, mat);
				mat = NULL;
				break;
			}

			for (int j = 0; j < n - i; j++) {
				mat[i][j] = 0;
			}
		}
	}
	return mat;
}

void ti_atribui(int i, int j, float **mat, float x)
{
	if (i <= j) {
		mat[i][j - i] = x;
	}
}

float ti_acessa(int i, int j, float **mat)
{
	if (i > j) {
		return 0;
	}
	return mat[i][j - i];
}

void ti_libera(int n, float **mat)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}
