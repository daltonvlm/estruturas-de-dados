#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[81];
	char mat[8];
	char turma;
	char email[41];
	float nota;
} Aluno;

static int compara_alunos_ptr(const void *p1, const void *p2)
{
	Aluno **a1 = (Aluno **) p1;
	Aluno **a2 = (Aluno **) p2;

	return strcmp((*a1)->nome, (*a2)->nome);
}

static int compara_notas_nomes(const void *p1, const void *p2)
{
	Aluno **a1 = (Aluno **) p1;
	Aluno **a2 = (Aluno **) p2;

	float d = (*a1)->nota - (*a2)->nota;

	if (d < 0) {
		return -1;
	}
	if (d > 0) {
		return 1;
	}
	return strcmp((*a1)->nome, (*a2)->nome);
}

static int compara_int(const void *v1, const void *v2)
{
	int *p1 = (int *)v1;
	int *p2 = (int *)v2;

	return *p1 - *p2;
}

void quick_sort(int n, int *v)
{
	if (n <= 1) {
		return;
	}

	int a = 1;
	int b = n - 1;
	int t;

	do {
		while (a < n && v[a] <= v[0]) {
			a++;
		}
		while (v[b] > v[0]) {
			b--;
		}
		if (a < b) {
			int t = v[a];
			v[a] = v[b];
			v[b] = t;
		}
	} while (a <= b);

	t = v[0];
	v[0] = v[b];
	v[b] = t;

	quick_sort(b, v);
	quick_sort(n - a, v + a);
}

int main(void)
{
	int vet[] = { 37, 25, 44, 33, 64, 86, 18, 12, 92, 48 };
	Aluno v[4] = {
		{"Nome C", "mat C", 'C', "c@email.com", .0f},
		{"Nome B", "mat B", 'B', "b@email.com", 6.f},
		{"Nome D", "mat D", 'D', "d@email.com", 6.f},
		{"Nome A", "mat A", 'A', "a@email.com", 6.f}
	};
	Aluno *p[4] = { v, v + 1, v + 2, v + 3 };

	quick_sort(10, vet);
	for (int i = 0; i < 10; i++) {
		printf("%d ", vet[i]);
	}
	puts("");

	qsort(p, 4, sizeof(Aluno *), compara_notas_nomes);
	for (int i = 0; i < 4; i++) {
		printf("Nome: %s\n", p[i]->nome);
	}

	return 0;
}
