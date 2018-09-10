/*
 * Altere a função percorre e sua respectiva callback do tipo lista genérica apre-
 * sentado: em vez de retornar um valor inteiro, a callback deve retornar um tipo
 * void* qualquer. Se o valor retornado pela callback for diferente de NULL, a função
 * percorre deve ser interrompida e ter como valor de retorno o valor void* retor-
 * nado pela callback. Use essa nova versão da função percorre para implementar
 * uma busca na lista, dada uma chave de busca qualquer passada para a função
 * percorre via parâmetro que representa o dado extra (void* dado). Sua função
 * deve retornar a informação associada à chave de busca passada.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listagen.h"

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	float nota;
};

static void *imprime(void *info, void *dado)
{
	Aluno *a = (Aluno *) info;
	printf("%s: %.1f\n", a->nome, a->nota);
	return NULL;
}

static void *compara_nome(void *info, void *dado)
{
	Aluno *a = (Aluno *) info;
	char *nome = (char *)dado;
	return strcmp(nome, a->nome) ? NULL : info;
}

static void insere(ListaGen * lst, char *nome, float nota)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	if (!a) {
		perror("");
		exit(EXIT_FAILURE);
	}
	strcpy(a->nome, nome);
	a->nota = nota;
	lgen_insere(lst, a);
}

int main(void)
{
	char nome[81] = "None";
	Aluno *a;
	ListaGen *lst = lgen_cria();

	insere(lst, "Carlos", 7.5);
	insere(lst, "Rui", 8.2);
	insere(lst, "Marta", 7.8);
	insere(lst, "Ana", 9.3);
	insere(lst, "Paulo", 6.5);
	lgen_percorre(lst, imprime, NULL);

	printf("\nEntre com o nome para a consulta: ");
	scanf(" %80[^\n]", nome);
	printf("\nBuscando por '%s':\n", nome);
	a = lgen_percorre(lst, compara_nome, nome);

	if (a) {
		puts("Aluno encontrado:");
		printf("%s: %.1f\n", a->nome, a->nota);
	} else {
		puts("Aluno nao encontrado.");
	}

	lgen_libera(lst, free);
	return 0;
}
