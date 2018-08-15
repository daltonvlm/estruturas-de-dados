/*
 * Use o TAD do item anterior para armazenar dados de alunos:
 *
 * 		typedef struct aluno Aluno;
 * 		struct aluno {
 * 			char nome[81];
 * 			float nota;
 * 		};
 *
 * Implemente o código necessário para calcular a média das notas dos alunos arma-
 * zenados no vetor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetgen.h"

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	float nota;
};

static int soma(void *info, void *dado)
{
	float *s = (float *)dado;
	Aluno *a = (Aluno *) info;
	*s += a->nota;
	return 0;
}

static void insere_aluno(VetorGen * v, char *nome, float nota)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	if (!a) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	strcpy(a->nome, nome);
	a->nota = nota;
	vgen_insere(v, a);
}

int main(void)
{
	float m;
	VetorGen *v = vgen_cria();

	insere_aluno(v, "Carlos", 7.5);
	insere_aluno(v, "Rui", 8.2);
	insere_aluno(v, "Marta", 7.8);
	insere_aluno(v, "Ana", 9.3);
	insere_aluno(v, "Paulo", 6.5);

	vgen_percorre(v, soma, &m);
	printf("media = %.1f\n", m / vgen_tam(v));
	vgen_libera(v, free);
	return 0;
}
