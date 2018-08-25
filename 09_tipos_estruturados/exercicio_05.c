/*
 * Considerando as declarações a seguir para representar o cadastro de alunos de uma
 * disciplina, implemente uma função que exiba na tela o número de matrícula, o
 * nome, a turma e a média de todos os alunos que foram aprovados na disciplina.
 *
 *      typedef struct aluno Aluno;
 *      struct aluno {
 *          char nome[81];
 *          char matricula[8];
 *          char turma;
 *          float p1;
 *          float p2;
 *          float p3;
 *      };
 *
 * Assuma que o critério para aprovação é dado pela média das três provas (p1, p2 e
 * p3). A função recebe como parâmetros o número de alunos e um vetor de ponteiros
 * para os dados dos alunos. Essa função deve obedecer ao protótipo:
 * 
 *      void imprime_aprovados (int n, Aluno** turmas);
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MEDIA 6

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	char matricula[8];
	char turma;
	float p1;
	float p2;
	float p3;
};

static void check(void *p)
{
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	check(p);
	return p;
}

static void le_aluno(Aluno * a)
{
	printf("\nEntre com o nome: ");
	scanf(" %80[^\n]", a->nome);
	printf("Entre com a matricula: ");
	scanf(" %7[^\n]", a->matricula);
	printf("Entre com a turma: ");
	scanf(" %c", &a->turma);
	printf("Entre com as 3 notas: ");
	scanf("%f%f%f", &a->p1, &a->p2, &a->p3);
}

static Aluno *cria_aluno(void)
{
	Aluno *a = (Aluno *) aloca(sizeof(Aluno));
	le_aluno(a);
	return a;
}

static void imprime_aluno(Aluno * a, float media)
{
	printf("\nMatricula: %s\n", a->matricula);
	printf("Nome: %s\n", a->nome);
	printf("Turma: %c\n", a->turma);
	printf("Media: %.1f\n", media);
}

static float calcula_media(Aluno * a)
{
	return (a->p1 + a->p2 + a->p3) / 3;
}

void imprime_aprovados(int n, Aluno ** turmas)
{
	float media;
	puts("\nAprovados:");
	for (int i = 0; i < n; i++) {
		media = calcula_media(turmas[i]);
		if (media >= MEDIA) {
			imprime_aluno(turmas[i], media);
		}
	}
}

static void libera_turmas(int n, Aluno ** turmas)
{
	for (int i = 0; i < n; i++) {
		free(turmas[i]);
	}
	free(turmas);
}

int main(void)
{
	int n;
	Aluno **turmas;
	printf("Entre com o numero de alunos da turma: ");
	scanf("%d", &n);
	turmas = (Aluno **) aloca(n * sizeof(Aluno *));
	for (int i = 0; i < n; i++) {
		turmas[i] = cria_aluno();
	}
	imprime_aprovados(n, turmas);
	libera_turmas(n, turmas);
	return 0;
}
