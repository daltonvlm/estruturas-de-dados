/*
 * Considerando as declarações do tipo Aluno do exercício anterior, implemente uma
 * função que tenha como valor de retorno a média final obtida pelos alunos de de-
 * terminada turma. A nota final de cada aluno é dada pela média das três provas.
 *
 *      float media_turma (int n, Aluno** turmas, char turma);
 */

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
