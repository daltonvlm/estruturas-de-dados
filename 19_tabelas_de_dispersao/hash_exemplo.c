#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno {
	int mat;
	char nome[81];
	char email[43];
	char turma;
	Aluno *prox;
};

typedef struct hash Hash;
struct hash {
	int n;
	int dim;
	Aluno **v;
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

static int hash(Hash * tab, int mat)
{
	return mat % tab->dim;
}

static int hash2(Hash * tab, int mat)
{
	return tab->dim - 2 - mat % (tab->dim - 2);
}

Hash *hsh_cria(void)
{
	Hash *tab = (Hash *) aloca(sizeof(Hash));
	tab->n = 0;
	tab->dim = 7;
	tab->v = (Aluno **) aloca(tab->dim * sizeof(Aluno *));
	for (int i = 0; i < tab->dim; i++) {
		tab->v[i] = NULL;
	}
	return tab;
}

void hsh_libera(Hash * tab)
{
	for (int i = 0; i < tab->dim; i++) {
		free(tab->v[i]);
	}
	free(tab->v);
	free(tab);
}

Aluno *hsh_busca(Hash * tab, int mat)
{
	int h0 = hash(tab, mat);
	int h2 = hash2(tab, mat);
	int h = h0;
	do {
		if (tab->v[h]->mat == mat) {
			return tab->v[h];
		}
		h = (h + h2) % tab->dim;
	} while (h != h0);
	return NULL;
}

static void redimensiona(Hash * tab)
{
	int max_ant = tab->dim;
	Aluno **ant = tab->v;
	tab->n = 0 tab->dim *= 1.947;
	tab->v = (Aluno **) aloca(tab->dim * sizeof(Aluno *));
	for (int i = 0; i < tab->dim; i++) {
		tab->v[i] = NULL;
	}
	for (int i = 0; i < max_ant; i++) {
		if (ant[i]) {
			hsh_insere(tab, ant[i]);
		}
	}
	free(ant);
}

Aluno *hsh_insere(Hash * tab, Aluno * a)
{
	if (tab->n > 0.75 * tab->dim) {
		redimensiona(tab);
	}
	int h0 = hash(tab, a->mat);
	int h2 = hash2(tab, a->mat);
	int h = h0;

	do {
		if (!tab->v[h] || tab->v[h]->mat == a->mat) {
			break;
		}
		h = (h + h2) % tab->dim;
	} while (h != h0);

	// Retornou ao indice inicial e sem encontrar espaco livre ou aluno de mesma matricula
	if (tab->v[h] && tab->v[h]->mat != mat) {
		return NULL;
	}
	free(tab->v[h]);
	tab->v[h] = a;
	tab->n++;
	return a;
}

int main(void)
{
	int mat;
	Aluno *eu;
	Hash *tab = hsh_cria();

	hsh_insere(tab, 123450, "Maria", "maria@email.com", '?');
	hsh_insere(tab, 123450, "Joao", "joao@email.com", '?');
	mat = 123450;
	eu = hsh_busca(tab, mat);
	if (eu) {
		printf("%s: %s (%d) - %c\n", eu->nome, eu->email, eu->mat,
		       eu->turma);
	} else {
		printf("Matricula '%d' nao encontrada.\n", mat);
	}
	hsh_libera(tab);

	return 0;
}
