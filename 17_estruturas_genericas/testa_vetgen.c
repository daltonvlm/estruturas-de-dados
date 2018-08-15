#include <stdio.h>
#include <stdlib.h>
#include "vetgen.h"

typedef struct {
	char *nome;
	float nota;
} Aluno;

static void insere_aluno(VetorGen * v, char *nome, float nota)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	if (!a) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	a->nome = nome;
	a->nota = nota;
	vgen_insere(v, a);
}

static int imprime(void *info, void *dado)
{
	Aluno *a = (Aluno *) info;
	printf("%s: %.1f\n", a->nome, a->nota);
	return 0;
}

int main(void)
{
	VetorGen *v = vgen_cria();
	Aluno *a;

	insere_aluno(v, "Carlos", 7.5);
	insere_aluno(v, "Rui", 8.2);
	insere_aluno(v, "Marta", 7.8);
	insere_aluno(v, "Ana", 9.3);
	insere_aluno(v, "Paulo", 6.5);

	printf("tamanho = %d\n", vgen_tam(v));

	a = (Aluno *) vgen_acessa(v, 2);
	if (a) {
		printf("Nome: %s, nota: %.1f\n", a->nome, a->nota);
	}
	vgen_percorre(v, imprime, NULL);

	vgen_libera(v, free);
	return 0;
}
