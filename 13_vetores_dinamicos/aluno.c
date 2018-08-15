#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
	char nome[81];
	float p1, p2, p3;
};

Aluno *aluno_cria(char *nome, float p1, float p2, float p3)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	if (!a) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	strcpy(a->nome, nome);
	a->p1 = p1;
	a->p2 = p2;
	a->p3 = p3;
	return a;
}

const char *aluno_getnome(Aluno * a)
{
	return a->nome;
}

void aluno_getnotas(Aluno * a, float *p1, float *p2, float *p3)
{
	*p1 = a->p1;
	*p2 = a->p2;
	*p3 = a->p3;
}

void aluno_libera(Aluno * a)
{
	free(a);
}
