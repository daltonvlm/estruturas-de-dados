/*
 * Repita as implementações do exercício anterior para uma matriz triangular supe-
 * rior. Nota: é mais fácil alocar os elementos abaixo da diagonal, e usar o acesso
 * transposto aos elementos.
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

float **ts_cria(int n)
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

void ts_atribui(int i, int j, float x, float **mat)
{
	if (i <= j) {
		mat[j][i] = x;
	}
}

float ts_acessa(int i, int j, float **mat)
{
	return i <= j ? mat[j][i] : 0;
}

void ts_libera(int n, float **mat)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}

int main(void)
{
	int n = 3;
	float **mat = (float **)ts_cria(n);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = rand() % 10;
			printf("Gerado valor %d\n", x);
			ts_atribui(i, j, x, mat);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.1f ", ts_acessa(i, j, mat));
		}
		puts("");
	}
	ts_libera(n, mat);
	return 0;
}
