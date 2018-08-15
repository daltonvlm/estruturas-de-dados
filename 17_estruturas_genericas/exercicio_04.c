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

typedef struct {
	char nome[81];
	float nota;
} Aluno;

static void insere_aluno(ArvGen * a, char *nome, float nota)
{
	Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
	if (!aluno) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	strcpy(aluno->nome, nome);
	aluno->nota = nota;
	agen_insere(a, &nota, aluno);
}

static int cmp_nota(void *chave, void *info)
{
	float *nota = (float *)chave;
	Aluno *aluno = (Aluno *) info;
	if (*nota < aluno->nota) {
		return 1;
	}
	return -1;
}

static int imprime(void *info, void *dado)
{
	Aluno *a = (Aluno *) info;
	printf("%s: %.1f\n", a->nome, a->nota);
	return 0;
}

static int imprime_maior8(void *info, void *dado)
{
	Aluno *a = (Aluno *) info;
	if (a->nota > 8) {
		printf("%s: %.1f\n", a->nome, a->nota);
	}
	return 0;
}

int main(void)
{
	ArvGen *a = agen_cria(cmp_nota);

	insere_aluno(a, "Carlos", 7.5);
	insere_aluno(a, "Rui", 8.2);
	insere_aluno(a, "Marta", 7.8);
	insere_aluno(a, "Ana", 9.3);
	insere_aluno(a, "Paulo", 6.5);
	insere_aluno(a, "Pedro", 5.0);
	insere_aluno(a, "Paulo", 3.0);
	insere_aluno(a, "João", 4.0);
	insere_aluno(a, "Matues", 2.0);
	insere_aluno(a, "Marcos", 1.0);
	insere_aluno(a, "Mariana", 8.0);
	insere_aluno(a, "Juliana", 6.0);
	insere_aluno(a, "Cristiane", 7.0);
	insere_aluno(a, "Tais", 9.0);
	insere_aluno(a, "Fernanda", 10);

	agen_percorre(a, imprime, NULL);
	puts("");
	agen_percorre(a, imprime_maior8, NULL);

	agen_libera(a, free);
	return 0;
}
