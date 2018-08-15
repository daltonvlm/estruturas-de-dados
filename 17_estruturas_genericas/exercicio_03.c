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

typedef struct {
	char *nome;
	float nota;
} Aluno;

static void insere_aluno(ListaGen * lst, char *nome, float nota)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	if (!a) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	a->nome = nome;
	a->nota = nota;
	lgen_insere(lst, a);
}

static void *busca_aluno(void *info, void *dado)
{
	Aluno *a = (Aluno *) info;
	char *nome = (char *)dado;
	return strcmp(nome, a->nome) ? NULL : info;
}

int main(void)
{
	Aluno *a;
	char *nome = "Joao";
	ListaGen *lst = lgen_cria();

	insere_aluno(lst, "Carlos", 7.5);
	insere_aluno(lst, "Rui", 8.2);
	insere_aluno(lst, "Marta", 7.8);
	insere_aluno(lst, "Ana", 9.3);
	insere_aluno(lst, "Paulo", 6.5);

	a = (Aluno *) lgen_percorre(lst, busca_aluno, nome);
	if (a) {
		printf("%s: %.1f\n", a->nome, a->nota);
	} else {
		printf("Aluno '%s' nao encontrado.\n", nome);
	}

	lgen_libera(lst, free);
	return 0;
}
