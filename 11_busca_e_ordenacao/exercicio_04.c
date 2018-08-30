/*
 * Considere a estrutura Aluno a seguir:
 *
 * 		typedef struct aluno Aluno;
 * 		struct aluno {
 * 			char nome[81];
 * 			float nota;
 * 		};
 *
 * Usando ordenação bolha, implemente uma função que ordene um vetor de alunos
 * em ordem alfabética dos nomes, seguindo o protótipo:
 *
 * 		void ordem_alfabetica (int n, Aluno* v);
 *
 * Escreva uma função main para testar sua função.
 */

#include <stdio.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	float nota;
};

void ordem_alfabetica(int n, Aluno * v)
{
	for (int i = n - 1; i > 0; i--) {
		int trocou = 0;
		for (int j = 0; j < i; j++) {
			if (strcmp(v[j].nome, v[j + 1].nome) > 0) {
				Aluno t = v[j];
				v[j] = v[j + 1];
				v[j + 1] = t;
				trocou = 1;
			}
		}
		if (!trocou) {
			return;
		}
	}
}

int main(void)
{
	Aluno v[6] = {
		{"Aluno C", 0},
		{"Aluno D", 0},
		{"Aluno A", 0},
		{"Aluno E", 0},
		{"Aluno B", 0},
		{"Aluno F", 0}
	};
	ordem_alfabetica(6, v);
	for (int i = 0; i < 6; i++) {
		puts(v[i].nome);
	}
	return 0;
}
