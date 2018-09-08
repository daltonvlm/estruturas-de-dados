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
