#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno {
	char nome[81];
	float p1, p2, p3;
};

Aluno *aluno_cria(char *nome, float p1, float p2, float p3)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	if (!a) {
		perror("");
		exit(EXIT_FAILURE);
	}
	strcpy(a->nome, nome);
	a->p1 = p1;
	a->p2 = p2;
	a->p3 = p3;
	return a;
}

void aluno_libera(Aluno * a)
{
	free(a);
}

void aluno_imprime(Aluno * a)
{
	printf("\nNome: %s\n", a->nome);
	printf("P1: %.1f\n", a->p1);
	printf("P2: %.1f\n", a->p2);
	printf("P3: %.1f\n", a->p3);
}
