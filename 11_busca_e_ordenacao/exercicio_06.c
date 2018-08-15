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

#include <stdio.h>

typedef struct aluno Aluno;
struct aluno {
	char mat[8];
	char nome[81];
	float cr;
};

static void quick_sort(int n, Aluno * v)
{
	if (n < 2) {
		return;
	}
	int a = 1;
	int b = n - 1;

	while (a <= b) {
		while (a < n && v[a].cr <= v[0].cr) {
			a++;
		}
		while (v[b].cr > v[0].cr) {
			b--;
		}
		if (a < b) {
			Aluno t = v[a];
			v[a] = v[b];
			v[b] = t;
		}
	}
	Aluno t = v[0];
	v[0] = v[b];
	v[b] = t;
	quick_sort(b, v);
	quick_sort(n - a, v + a);
}

void mediano(int n, Aluno * v)
{
	quick_sort(n, v);
	puts(v[n / 2].nome);
}

int main(void)
{
	Aluno va[7] = {
		{"Mat f", "Aluno F", 6.f},
		{"Mat b", "Aluno B", 2.f},
		{"Mat e", "Aluno E", 5.f},
		{"Mat c", "Aluno C", 3.f},
		{"Mat a", "Aluno A", 1.f},
		{"Mat g", "Aluno G", 7.f},
		{"Mat d", "Aluno D", 4.f}
	};

	for (int i = 0; i < 7; i++) {
		printf("%s\t%s\t%.2f\n", va[i].mat, va[i].nome, va[i].cr);
	}
	puts("");

	mediano(7, va);
	return 0;
}

/*
#include <stdio.h>

typedef struct aluno Aluno;
struct aluno {
	char mat[8];		// matrícula do aluno
	char nome[81];		// nome do aluno
	float cr;		// coeficiente de rendimento
};

static void ordena(int n, Aluno * v)
{
	if (n < 2)
		return;
	Aluno x = v[0];
	int a = 1;
	int b = n - 1;
	do {
		while (a < n && v[a].cr <= x.cr)
			a++;
		while (v[b].cr > x.cr)
			b--;
		if (a < b) {
			Aluno t = v[a];
			v[a] = v[b];
			v[b] = t;
		}
	} while (a <= b);
	v[0] = v[b];
	v[b] = x;
	ordena(b, v);
	ordena(n - a, v + a);
}

void mediano(int n, Aluno * v)
{
	Aluno m = v[n / 2];
	printf("%s\n", m.nome);
}

int main(void)
{
	int n = 7;
	Aluno a = { "0001", "Aluno A", 5 };
	Aluno b = { "0002", "Aluno B", 3.5 };
	Aluno c = { "0003", "Aluno C", 9.5 };
	Aluno d = { "0004", "Aluno D", 7 };
	Aluno e = { "0005", "Aluno E", 8 };
	Aluno f = { "0006", "Aluno F", 5.5 };
	Aluno g = { "0007", "Aluno G", 6 };
	Aluno v[] = { a, b, c, d, e, f, g };

	ordena(n, v);
	for (int i = 0; i < n; i++)
		printf("%s %s %g\n", v[i].mat, v[i].nome, v[i].cr);
	mediano(n, v);
	return 0;
}
*/
