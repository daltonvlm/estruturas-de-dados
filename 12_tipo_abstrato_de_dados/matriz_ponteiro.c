#include "matriz.h"

#include<stdio.h>
#include<stdlib.h>

struct matriz {
	int m;
	int n;
	float **v;
};

static void *aloca(int nbytes)
{
	void *p = malloc(nbytes);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

Matriz *mat_cria(int m, int n)
{
	Matriz *mat = (Matriz *) aloca(sizeof(Matriz));
	mat->m = m;
	mat->n = n;
	mat->v = (float **)aloca(m * sizeof(float *));

	for (int i = 0; i < m; i++) {
		mat->v[i] = (float *)aloca(n * sizeof(float));
	}
	return mat;
}

void mat_libera(Matriz * mat)
{
	for (int i = 0; i < mat->m; i++) {
		free(mat->v[i]);
	}
	free(mat);
}

float mat_acessa(Matriz * mat, int i, int j)
{
	return mat->v[i][j];
}

void mat_atribui(Matriz * mat, int i, int j, float v)
{
	mat->v[i][j] = v;
}

int mat_linhas(Matriz * mat)
{
	return mat->m;
}

int mat_colunas(Matriz * mat)
{
	return mat->n;
}
