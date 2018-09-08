/*
 * Escreva:
 *
 *  (a) Uma função para converter uma matriz representada por um vetor numa ma-
 *  triz representada por um vetor de ponteiros:
 *      
 *      float** converte_a (int m, int n, float* mat);
 *
 *  (b) Uma função para converter uma matriz representada por um vetor de pontei-
 *      ros numa matriz representada por um vetor:
 *
 *      float* converte_b (int m, int n, float** mat);
 *
 * Escreva também as funções para criar as matrizes e implemente uma função main
 * para testar as conversões.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro:");
		exit(EXIT_FAILURE);
	}
	return p;
}

float **converte_a(int m, int n, float *mat)
{
	float **resp = (float **)aloca(m * sizeof(float *));
	for (int i = 0; i < m; i++) {
		resp[i] = (float *)aloca(n * sizeof(float));
		for (int j = 0; j < n; j++) {
			resp[i][j] = mat[i * n + j];
		}
	}
	return resp;
}

float *converte_b(int m, int n, float **mat)
{
	float *resp = (float *)aloca(m * n * sizeof(float));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			resp[i * n + j] = mat[i][j];
		}
	}
	return resp;
}

static void libera_mat(int m, float **mat)
{
	for (int i = 0; i < m; i++) {
		free(mat[i]);
	}
	free(mat);
}

int main(void)
{
	int m = 3, n = 3;
	float vet[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	float *v, **mat;

	mat = converte_a(m, n, vet);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%.1f ", mat[i][j]);
		}
		puts("");
	}
	v = converte_b(m, n, mat);
	for (int i = 0; i < m * n; i++) {
		printf("%.1f ", v[i]);
	}
	puts("");
	libera_mat(m, mat);
	free(v);
	return 0;
}
