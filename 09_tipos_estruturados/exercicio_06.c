/*
 * Considerando as declarações do tipo Aluno do exercício anterior, implemente uma
 * função que tenha como valor de retorno a média final obtida pelos alunos de de-
 * terminada turma. A nota final de cada aluno é dada pela média das três provas.
 *
 *      float media_turma (int n, Aluno** turmas, char turma);
 */

#include <stdio.h>

typedef struct aluno Aluno;
struct aluno {
	char nome[81];
	char matricula[8];
	char turma;
	float p1;
	float p2;
	float p3;
};

float media_turma(int n, Aluno ** turmas, char turma)
{
	int c = 0;
	float m = .0f;

	for (int i = 0; i < n; i++) {
		if (turmas[i]->turma == turma) {
			c++;
			m += (turmas[i]->p1 + turmas[i]->p2 +
			      turmas[i]->p3) / 3;
		}
	}

	if (c) {
		return m / c;
	}
	return 0;
}

int main(void)
{
	Aluno joao = { "Joao", "20180101", 'A', 6.2, 8.0, 9.5 };
	Aluno bia = { "Bia", "20180102", 'B', 8.3, 5.0, 8.0 };
	Aluno carlos = { "Carlos", "20180201", 'A', 5.0, 7.0, 0.0 };
	Aluno marcia = { "Marcia", "20180103", 'A', 6.0, 6.0, 5.5 };
	Aluno rodrigo = { "Rodrigo", "20180202", 'B', 7.2, 4.0, 4.5 };
	Aluno *turma[] = { &joao, &bia, &carlos, &marcia, &rodrigo };

	printf("Media da turma 'A': %.2f\n", media_turma(5, turma, 'A'));
	return 0;
}
