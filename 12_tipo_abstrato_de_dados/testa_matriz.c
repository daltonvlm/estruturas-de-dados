#include<stdio.h>
#include"matriz.h"

int main(void)
{
	float cont = .0f;
	Matriz *mat = mat_cria(5, 5);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mat_atribui(mat, i, j, cont++);
		}
	}

	printf("Matriz %d x %d:\n", mat_linhas(mat), mat_colunas(mat));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%5.2f ", mat_acessa(mat, i, j));
		}
		puts("");
	}

	mat_libera(mat);
	return 0;
}
