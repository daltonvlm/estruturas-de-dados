/*
 * Usando apenas as operações definidas pela TAD Matriz, implemente uma função
 * que, dada uma matriz, cria dinamicamente a matriz transposta correspondente.
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz *mat_transposta(Matriz * mat)
{
	int m = mat_colunas(mat);
	int n = mat_linhas(mat);
	Matriz *t = mat_cria(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			float v = mat_acessa(mat, j, i);
			mat_atribui(t, i, j, v);
		}
	}
	return t;
}

static void mat_imprime(Matriz * mat)
{
	for (int i = 0; i < mat_linhas(mat); i++) {
		for (int j = 0; j < mat_colunas(mat); j++) {
			printf("%5.2f ", mat_acessa(mat, i, j));
		}
		puts("");
	}
}

int main(void)
{
	float cont = .0f;
	Matriz *mat, *t;

	mat = mat_cria(2, 3);
	for (int i = 0; i < mat_linhas(mat); i++) {
		for (int j = 0; j < mat_colunas(mat); j++) {
			mat_atribui(mat, i, j, cont++);
		}
	}

	t = mat_transposta(mat);
	mat_imprime(mat);
	puts("");
	mat_imprime(t);

	mat_libera(mat);
	mat_libera(t);
	return 0;
}
