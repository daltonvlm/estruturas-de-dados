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

static int imprime_soma(void *info, void *dado)
{
	Aluno *a = (Aluno *) info;
	float *s = (float *)dado;
	printf("%s: %.1f\n", a->nome, a->nota);
	*s += a->nota;
	return 0;
}

static void insere(VetorGen * vg, char *nome, float nota)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	if (!a) {
		perror("");
		exit(EXIT_FAILURE);
	}
	strcpy(a->nome, nome);
	a->nota = nota;
	vgen_insere(vg, a);
}

int main(void)
{
	float m = 0;
	float nota;
	char nome[81];
	VetorGen *vg = vgen_cria();

	puts("Informe nome e nota do aluno (Ctrl+D para encerrar)");
	while (1) {
		printf("\nNome: ");
		if (1 == scanf(" %80[^\n]", nome)) {
			printf("Nota: ");
			if (1 == scanf("%f", &nota)) {
				insere(vg, nome, nota);
				continue;
			}
		}
		break;
	}
	vgen_percorre(vg, imprime_soma, &m);
	m /= vgen_tam(vg);
	printf("Media dos alunos: %.1f\n", m);
	vgen_libera(vg, free);
	return 0;
}
