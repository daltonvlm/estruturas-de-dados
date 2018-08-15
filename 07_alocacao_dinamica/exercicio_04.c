/*
 * Repita as implementações do exercício anterior para uma matriz triangular supe-
 * rior. Nota: é mais fácil alocar os elementos abaixo da diagonal, e usar o acesso
 * transposto aos elementos.
 */

#include<stdio.h>
#include<stdlib.h>

float **ts_cria(int n);
void ts_atribui(int i, int j, float **mat, float x);
float ts_acessa(int i, int j, float **mat);
void ts_libera(int n, float **mat);

int main(void)
{
	int n = 4;
	float **mat = ts_cria(n);

	if (mat != NULL) {
		for (int i = 0, c = 1; i < n; i++) {
			for (int j = 0; j < n; j++, c++) {
				ts_atribui(i, j, mat, c);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%5.2f ", ts_acessa(i, j, mat));
			}
			puts("");
		}

		ts_libera(n, mat);
	}
	return 0;
}

float **ts_cria(int n)
{
	float **mat = (float **)malloc(n * sizeof(float *));

	if (NULL != mat) {
		for (int i = 0; i < n; i++) {
			mat[i] = (float *)malloc((i + 1) * sizeof(float));

			if (NULL == mat[i]) {
				ts_libera(i, mat);
				mat = NULL;
				break;
			}

			for (int j = 0; j <= i; j++) {
				mat[i][j] = 0;
			}
		}
	}
	return mat;
}

void ts_atribui(int i, int j, float **mat, float x)
{
	if (i >= j) {
		mat[i][j] = x;
	}
}

float ts_acessa(int i, int j, float **mat)
{
	if (i < j) {
		return 0;
	}
	return mat[i][j];
}

void ts_libera(int n, float **mat)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}
