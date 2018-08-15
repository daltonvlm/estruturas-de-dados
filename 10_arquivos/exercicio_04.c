/*
 * Considere um tipo que representa um aluno de um curso, definido pela estrutura a
 * seguir:
 *
 *      typedef struct aluno Aluno;
 *      struct aluno {
 *          char mat[8];        // matricula do aluno
 *          char nome[81];      // nome do aluno
 *          float cr;           // coeficiente de rendimento
 *      };
 *
 * Considere ainda a existência de um arquivo texto no qual se tem a lista dos alunos
 * do curso. A primeira informação do arquivo é um número inteiro que indica a
 * quantidade de alunos listados no arquivo. A seguir, em cada linha, encontra-se
 * os dados de cada um dos alunos listados: número de matrícula, nome entre aspas
 * simples e coeficiente de rendimento. Um exemplo de um arquivo com uma lista de
 * alunos é apresentado a seguir:
 *
 *      ********************************************
 *      * 4                                        *
 *      * 0011234   'Fulano Pereira'    8.6        *
 *      * 0111224   'Beltrano Silva'    7.1        *
 *      * 0421233   'Sicrano Santos'    5.6        *
 *      * 0314231   'Fulana Souza'      9.4        *
 *      ********************************************
 *
 * Escreva uma função em C que leia um arquivo com este formato e crie dinamica-
 * mente um vetor de Aluno. Essa função recebe como parâmetro o nome do arquivo
 * de entrada. Ela deve então ler o número de alunos existentes, alocar dinamica-
 * mente o vetor e ler o conteúdo do arquivo para o vetor. A função recebe ainda um
 * parâmetro adicional que representa um ponteiro de uma variável inteira, no qual
 * deve-se armazenar o número de alunos existentes. A função deve retornar o vetor
 * alocado (e devidamente preenchido), obedecendo ao seguinte protótipo:
 *
 *      Aluno* carrega (char* arquivo, int *n);
 *
 * Se ocorrer erro na abertura do arquivo, a função deve retornar NULL. Se o arquivo
 * existir, considere que existe pelo menos um aluno listado e que não existem linhas
 * em branco no arquivo. Considere ainda que os nomes dos alunos não terão mais
 * do que 80 caracteres.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno {
	char mat[8];
	char nome[81];
	float cr;
};

Aluno *carrega(char *arquivo, int *n)
{
	char buf[121];
	int i = 0;
	FILE *f = fopen(arquivo, "rt");
	Aluno *alunos = NULL;

	if (!f) {
		return NULL;
	}

	/* Busca a primeira linha com a quantidade de alunos */
	while (fgets(buf, sizeof(buf), f)) {
		if (1 == sscanf(buf, "%d", n)) {
			break;
		}
	}

	if (feof(f)) {
		fclose(f);
		return NULL;
	}

	alunos = (Aluno *) malloc(*n * sizeof(Aluno));
	if (!alunos) {
		fclose(f);
		return NULL;
	}

	while (fgets(buf, sizeof(buf), f) && i < *n) {
		char mat[8];
		char nome[81];
		float cr;

		if (3 == sscanf(buf, " %7s '%80[^']' %f", mat, nome, &cr)) {
			strcpy(alunos[i].mat, mat);
			strcpy(alunos[i].nome, nome);
			alunos[i].cr = cr;
			i++;
		}
	}
	fclose(f);
	return alunos;
}

int main(void)
{
	int n;
	Aluno *alunos = carrega("alunos.txt", &n);

	if (alunos) {
		for (int i = 0; i < n; i++) {
			printf("\nMatricula: %s\n", alunos[i].mat);
			printf("Nome: %s\n", alunos[i].nome);
			printf("CR: %.2f\n", alunos[i].cr);
		}
		free(alunos);
	}
	return 0;
}
