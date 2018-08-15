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

#include<stdio.h>
#include<stdlib.h>

void libera(int n, float **mat)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}

float **converte_a(int m, int n, float *mat)
{
	float **r = (float **)malloc(m * sizeof(float *));

	if (r != NULL) {
		for (int i = 0; i < m; i++) {
			r[i] = (float *)malloc(n * sizeof(float));

			if (NULL == r[i]) {
				libera(i, r);
				r = NULL;
				break;
			}

			for (int j = 0; j < n; j++) {
				r[i][j] = mat[i * n + j];
			}
		}
	}
	return r;
}

float *converte_b(int m, int n, float **mat)
{
	float *r = (float *)malloc(m * n * sizeof(float));

	if (r != NULL) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				r[i * n + j] = mat[i][j];
			}
		}
	}
	return r;
}

float **cria_mat(int m, int n)
{
	float **mat = (float **)malloc(m * sizeof(float *));

	if (mat != NULL) {
		for (int i = 0; i < m; i++) {
			mat[i] = (float *)malloc(n * sizeof(float));

			if (NULL == mat[i]) {
				libera(i, mat);
				mat = NULL;
				break;
			}
			for (int j = 0; j < n; j++) {
				mat[i][j] = 0;
			}
		}
	}
	return mat;
}

float *cria_vet(int m, int n)
{
	float *r = (float *)malloc(m * n * sizeof(float));

	if (r != NULL) {
		for (int i = 0; i < m * n; i++) {
			r[i] = 0;
		}
	}
	return r;
}

void imprime_mat(int m, int n, float **mat)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.2f ", mat[i][j]);
		}
		puts("");
	}
}

void imprime_vet(int m, int n, float *v)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.2f ", v[i * n + j]);
		}
		puts("");
	}
}

int main(void)
{
	int m = 3, n = 4;
	float **mat;
	float *vet = cria_vet(m, n);

	if (NULL == vet) {
		return 1;
	}

	for (int i = 0; i < m * n; i++) {
		vet[i] = i;
	}
	puts("vet:");
	imprime_vet(m, n, vet);

	mat = converte_a(m, n, vet);
	if (NULL == mat) {
		return 1;
	}
	puts("\nvet -> mat:");
	imprime_mat(m, n, mat);
	free(vet);

	vet = converte_b(m, n, mat);
	if (NULL == vet) {
		return 1;
	}
	puts("\nmat -> vet");
	imprime_vet(m, n, vet);
	free(vet);
	libera(m, mat);

	return 0;
}
