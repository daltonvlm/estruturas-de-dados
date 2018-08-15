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

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	char matricula[8];
	char turma;
	float p1;
	float p2;
	float p3;
};

#include <stdio.h>

#define MEDIA 6.f

void imprime_aprovados(int n, Aluno ** turmas)
{
	for (int i = 0; i < n; i++) {
		float m = (turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3) / 3;
		if (m >= MEDIA) {
			printf("\nMatricula: %s\n", turmas[i]->matricula);
			printf("Nome: %s\n", turmas[i]->nome);
			printf("Turma: %c\n", turmas[i]->turma);
			printf("Media: %.2f\n", m);
		}
	}
}

int main(void)
{
	Aluno joao = { "Joao", "20180101", 'A', 6.2, 8.0, 9.5 };
	Aluno bia = { "Bia", "20180102", 'A', 8.3, 5.0, 8.0 };
	Aluno carlos = { "Carlos", "20180201", 'A', 5.0, 7.0, 0.0 };
	Aluno marcia = { "Marcia", "20180103", 'A', 6.0, 6.0, 5.5 };
	Aluno rodrigo = { "Rodrigo", "20180202", 'A', 7.2, 4.0, 4.5 };
	Aluno *turma[] = { &joao, &bia, &carlos, &marcia, &rodrigo };

	imprime_aprovados(5, turma);
	return 0;
}
