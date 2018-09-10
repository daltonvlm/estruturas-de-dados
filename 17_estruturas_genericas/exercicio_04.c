/*
 * Use o TAD que representa uma árvore genérica de busca para armazenar dados de
 * alunos, conforme foi discutido. No entanto, ordene os alunos por valor decrescente
 * de notas. Implemente um código para listar todos os alunos que tiveram notas maior
 * que 8.0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvgen.h"

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	float nota;
};

static int aluno_cmp_nota_dec(void *chave, void *info)
{
	float *nota = (float *)chave;
	Aluno *aluno = (Aluno *) info;
	// return aluno->nota - *nota;
	if (*nota <= aluno->nota) {
		return 1;
	}
	return 0;
}

static int imprime_maiores(void *info, void *dado)
{
	Aluno *aluno = (Aluno *) info;
	float *nota = (float *)dado;
	if (aluno->nota > *nota) {
		printf("%s: %.1f\n", aluno->nome, aluno->nota);
	}
	return 0;
}

static void insere(ArvGen * a, char *nome, float nota)
{
	Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
	if (!aluno) {
		perror("");
		exit(EXIT_FAILURE);
	}
	strcpy(aluno->nome, nome);
	aluno->nota = nota;
	agen_insere(a, &aluno->nota, aluno);
}

int main(void)
{
	float nota;
	char nome[81];
	ArvGen *a = agen_cria(aluno_cmp_nota_dec);

	puts("Informe nome e nota do aluno (Ctrl+D para encerrar)");
	while (1) {
		printf("\nNome: ");
		if (1 == scanf(" %80[^\n]", nome)) {
			printf("Nota: ");
			if (1 == scanf("%f", &nota)) {
				insere(a, nome, nota);
				continue;
			}
		}
		break;
	}
	nota = -1;
	puts("\nAlunos cadastrados:");
	agen_percorre(a, imprime_maiores, &nota);

	nota = 8;
	printf("\nAlunos com notas maiores que %.1f\n", nota);
	agen_percorre(a, imprime_maiores, &nota);

	agen_libera(a, free);
	return 0;
}
