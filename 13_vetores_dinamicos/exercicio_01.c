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

void le_alunos(VDAluno * vda, char *fname)
{
	char buf[121];
	char nome[81];
	float p1, p2, p3;
	FILE *fp = fopen(fname, "rt");

	if (!fp) {
		perror("");
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, sizeof(buf), fp)) {
		if (1 == sscanf(buf, " %80[^\n0-9]", nome)) {
			if (3 == fscanf(fp, "%f%f%f", &p1, &p2, &p3)) {
				vda_insere(vda, aluno_cria(nome, p1, p2, p3));
			}
		}
	}
	fclose(fp);
}

int main(void)
{
	int n;
	VDAluno *vda = vda_cria();

	le_alunos(vda, "alunos.txt");
	n = vda_tam(vda);
	for (int i = 0; i < n; i++) {
		aluno_imprime(vda_acessa(vda, i));
	}
	vda_libera(vda, 1);
	return 0;
}
