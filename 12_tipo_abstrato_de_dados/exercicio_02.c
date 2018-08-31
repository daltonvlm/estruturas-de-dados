/*
 * Usando apenas as operações definidas pela TAD Matriz, implemente uma função
 * que, dada uma matriz, cria dinamicamente a matriz transposta correspondente.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

static Matriz *mat_transp(Matriz * mat)
{
	int lin = mat_colunas(mat);
	int col = mat_linhas(mat);
	Matriz *tp = mat_cria(lin, col);
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			float x = mat_acessa(mat, j, i);
			mat_atribui(tp, i, j, x);
		}
	}
	return tp;
}

static void mat_imprime(Matriz * mat)
{
	int lin = mat_linhas(mat);
	int col = mat_colunas(mat);
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			printf("%g ", mat_acessa(mat, i, j));
		}
		puts("");
	}
}

static void mat_popula(Matriz * mat, int max)
{
	int lin = mat_linhas(mat);
	int col = mat_colunas(mat);
	for (int i = 0; i < lin; i++) {
		mat_atribui(mat, i, i, rand() % max);
		for (int j = 0; j < i; j++) {
			mat_atribui(mat, i, j, rand() % max);
			mat_atribui(mat, j, i, rand() % max);
		}
	}
}

int main(void)
{
	Matriz *mat, *tp;
	mat = mat_cria(2, 3);

	srand(time(NULL));
	mat_popula(mat, 10);
	puts("Matriz:");
	mat_imprime(mat);
	tp = mat_transp(mat);
	puts("\nTransposta:");
	mat_imprime(tp);
	mat_libera(mat);
	mat_libera(tp);
	return 0;
}
