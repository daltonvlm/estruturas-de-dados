/*
 * Considere uma estrutura que armazene dados de um aluno:
 *
 * 		typedef struct aluno Aluno;
 * 		struct aluno {
 * 			char nome[81];		// nome
 * 			float p1, p2, p3;	// notas
 * 		};
 *
 * Pede-se:
 *
 * 	(a)	Implemente um tipo abstrato de dados para representar vetores dinâmicos que
 * 		armazenem dados de aluno. O vetor deve ser de ponteiros para Aluno e deve
 * 		alocar uma estrutura que representa os dados de um aluno apenas para as
 * 		posições efetivamente usadas pelo vetor.
 *
 * 	(b)	Escreva um programa para testar seu tipo abstrato. Neste programa, deve-
 * 		se ler um arquivo texto de entrada com o seguinte formato, para cada aluno
 * 		listado: nome em uma linha e as três notas na linha seguinte. Considere que
 * 		o número total de alunos listados no arquivo não é informado (isto é, deve-se
 * 		ler os dados para descobrir o total). Os dados lidos devem ser armazenados
 * 		no vetor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "vetordin_aluno.h"

VetorDin *le_arquivo(char *arquivo)
{
	char buf[121];
	FILE *f = fopen(arquivo, "rt");
	VetorDin *vd = vd_cria();

	if (!f) {
		vd_libera(vd);
		perror("Erro");
		exit(EXIT_FAILURE);
	}

	while (fgets(buf, sizeof(buf), f)) {
		char nome[81];
		float p1, p2, p3;

		if (sscanf(buf, " %80[^\n]", nome) == 1) {
			if (!fgets(buf, sizeof(buf), f)) {
				break;
			}
			if (sscanf(buf, "%f %f %f", &p1, &p2, &p3) == 3) {
				vd_insere(vd, nome, p1, p2, p3);
			}
		}
	}
	fclose(f);
	return vd;
}

int main(void)
{
	float p1, p2, p3;
	Aluno *a;
	VetorDin *vd = le_arquivo("alunos.txt");

	for (int i = 0; i < vd_tam(vd); i++) {
		a = vd_acessa(vd, i);
		aluno_getnotas(a, &p1, &p2, &p3);
		printf("Nome: %s\n", aluno_getnome(a));
		printf("Notas: %.2f %.2f %.2f\n", p1, p2, p3);
	}
	vd_libera(vd);
	return 0;
}
