/*
 * Considerando as declarações do tipo Aluno do exercício anterior, implemente uma
 * função que tenha como valor de retorno a média final obtida pelos alunos de de-
 * terminada turma. A nota final de cada aluno é dada pela média das três provas.
 *
 *      float media_turma (int n, Aluno** turmas, char turma);
 */

#include <stdio.h>
#include <stdlib.h>

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

static float calcula_media(Aluno * a)
{
	return (a->p1 + a->p2 + a->p3) / 3;
}

float media_turma(int n, Aluno ** turmas, char turma)
{
	float media = 0;
	int alunos = 0;
	for (int i = 0; i < n; i++) {
		if (turma == turmas[i]->turma) {
			media += calcula_media(turmas[i]);
			alunos++;
		}
	}
	return alunos ? media / alunos : 0;
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
	char turma;
	int n;
	float media;
	Aluno **turmas;
	printf("Entre com o numero de alunos da turma: ");
	scanf("%d", &n);
	turmas = (Aluno **) aloca(n * sizeof(Aluno *));
	for (int i = 0; i < n; i++) {
		turmas[i] = cria_aluno();
	}
	printf("\nEntre com a turma: ");
	scanf(" %c", &turma);
	media = media_turma(n, turmas, turma);
	printf("\nA media da turma '%c' e %.1f\n", turma, media);
	libera_turmas(n, turmas);
	return 0;
}
