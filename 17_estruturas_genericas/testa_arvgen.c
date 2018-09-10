#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvgen.h"

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	float nota;
};

static int cmp_nome_aluno(void *chave, void *info)
{
	char *nome = (char *)chave;
	Aluno *aluno = (Aluno *) info;
	return strcmp(nome, aluno->nome);
}

static int cb_imprime(void *info, void *dado)
{
	Aluno *aluno = (Aluno *) info;
	printf("%s: %.1f\n", aluno->nome, aluno->nota);
	return 0;
}

static int cb_imprime_primeiros(void *info, void *dado)
{
	int *pn = (int *)dado;
	Aluno *aluno = (Aluno *) info;
	if (!(*pn)--) {
		return 1;
	}
	printf("%s: %.1f\n", aluno->nome, aluno->nota);
	return 0;
}

static void insere_aluno(ArvGen * a, char *nome, float nota)
{
	Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
	if (!aluno) {
		perror("");
		exit(EXIT_FAILURE);
	}
	strcpy(aluno->nome, nome);
	aluno->nota = nota;
	agen_insere(a, nome, aluno);
}

static void popula(ArvGen * a)
{
	char nome[81];
	puts("\nInserindo alunos:");
	while (1) {
		printf("\nEntre com o nome: ");
		if (scanf(" %80[^\n]", nome) != 1) {
			break;
		}
		insere_aluno(a, nome, 6);
	}
}

static void esvazia(ArvGen * a)
{
	char nome[81];
	puts("\nRetirando elementos:");
	while (1) {
		agen_percorre(a, cb_imprime, NULL);
		printf("\nEntre com o nome: ");
		if (scanf(" %80[^\n]", nome) != 1) {
			break;
		}
		agen_retira(a, nome, free);
	}
}

int main(void)
{
	ArvGen *a = agen_cria(cmp_nome_aluno);
	popula(a);
	esvazia(a);
	agen_libera(a, free);
	return 0;
}
