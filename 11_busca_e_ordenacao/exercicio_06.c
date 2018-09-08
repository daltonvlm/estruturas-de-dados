/*
 * Considere um tipo que represente um aluno de um curso, definido pela estrutura a
 * seguir:
 *
 * 		typedef struct aluno Aluno;
 * 		struct aluno {
 * 			char mat[8];		// matrícula do aluno
 * 			char nome[81];		// nome do aluno
 * 			float cr;			// coeficiente de rendimento
 * 		};
 *
 * Considere ainda um vetor de estrutura Aluno com um número ímpar de elemen-
 * tos. Implemente uma função que imprima na tela o nome de um aluno mediano.
 * O aluno mediano é definido da seguinte forma: dos alunos restantes, metade tem
 * coeficiente de rendimento menor ou igual ao do aluno mediano e metade tem coefi-
 * ciente de rendimento maior ou igual ao do aluno mediano. A função deve obedecer
 * ao seguinte protótipo:
 *
 * 		void mediano (int n, Aluno* v);
 *
 * Dica: Ordene o vetor em ordem de coeficiente de rendimento e considere o aluno
 * no meio vetor.
 */

static void ordena_alunos(int n, Aluno * v)
{
	if (n > 1) {
		int a = 0;
		int b = n - 1;
		Aluno x = v[0];
		do {
			while (v[a].cr <= x.cr && a < n) {
				a++;
			}
			while (v[b].cr > x.cr) {
				b--;
			}
			if (a < b) {
				Aluno t = v[a];
				v[a] = v[b];
				v[b] = t;
				a++;
				b--;
			}
		} while (a <= b);
		v[0] = v[b];
		v[b] = x;
		ordena_alunos(b, v);
		ordena_alunos(n - a, v + a);
	}
}

void mediano(int n, Aluno * v)
{
	ordena_alunos(n, v);
	printf("Aluno mediano: %s\n", v[n / 2].nome);
}
