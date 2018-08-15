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
	Aluno *a = (Aluno *) info;
	return strcmp(nome, a->nome);
}

static void insere_aluno(ArvGen * a, char *nome, float nota)
{
	Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
	if (!aluno) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	strcpy(aluno->nome, nome);
	aluno->nota = nota;
	agen_insere(a, nome, aluno);
}

static int cb_imprime(void *info, void *dado)
{
	int *pn = (int *)dado;
	if (!(*pn)--) {
		return 1;
	}
	Aluno *a = (Aluno *) info;
	printf("%s: %.1f\n", a->nome, a->nota);
	return 0;
}

int main(void)
{
	int n = 2;
	ArvGen *a = agen_cria(cmp_nome_aluno);

	insere_aluno(a, "Carlos", 7.5);
	insere_aluno(a, "Rui", 8.2);
	insere_aluno(a, "Marta", 7.8);
	insere_aluno(a, "Ana", 9.3);
	insere_aluno(a, "Paulo", 6.5);

	Aluno *p = (Aluno *) agen_busca(a, "Rui");
	printf("%g\n", p->nota);

	agen_percorre(a, cb_imprime, &n);
	agen_libera(a, free);
	return 0;
}
