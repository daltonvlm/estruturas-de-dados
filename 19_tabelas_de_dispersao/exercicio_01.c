/*
 * Implemente um tipo abstrato de dado para representar uma tabela de dispersão
 * genérica, isto é, que sirva para armazenar qualquer tipo de informação. Para tanto,
 * a informação armazenada deverá ser do tipo void*. Na criação, o cliente deverá
 * fornecer a função de dispersão a ser usada, que recebe como parâmetro a chave de
 * busca, também representada pelo tipo void*:
 *
 * 		typedef struct hashgen HashGen;
 *
 * 		typedef int (*HashFunc) (void* key);
 *
 * 		HashGen* hgen_cria (HashFunc hfunc);
 * 		void hgen_libera (HashGen* tab);
 * 		void hgen_insere (HashGen* tab, void* key, void* info);
 * 		void* hgen_busca (HashGen* tab, void* key);
 *
 * Dica: Na implementação, podemos criar um tipo elemento que agrupa as infor-
 * mações de cada elemento armazenado na tabela. Considerando o tratamento de
 * colisão com lista encadeada, este tipo e o tipo da tabela de dispersão podem ser
 * dados por:
 *
 * 		typedef struct elemento Elemento;
 * 		struct elemento {
 * 			void* key;
 * 			void* info;
 * 			Elemento* prox;
 * 		};
 *
 * 		#define N 101
 * 		struct hashgen {
 * 			HashFunc hash;
 * 			Elemento* tab[N];
 * 		};
 *
 * Para testar seu código, reimplemente o programa que conta o número de ocorrências
 * de palavras em um texto usando o tipo genérico criado. Para isso, será necessário
 * implementar uma função para percorrer e processar (via calback) os elementos
 * armazenados na tabela.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashgen.h"

#define NPAL 64

typedef struct palavra Palavra;
struct palavra {
	int n;
	char s[NPAL];
};

typedef struct vetor Vetor;
struct vetor {
	int n;
	int dim;
	Palavra **v;
};

static int le_palavra(FILE * f, char *s)
{
	int i = 0;
	char c;
	while ((c = fgetc(f)) != EOF) {
		if (isalpha(c)) {
			break;
		}
	}
	if (EOF == c) {
		return 0;
	}
	s[i++] = c;
	while (i < NPAL - 1 && (c = fgetc(f)) != EOF && isalpha(c)) {
		s[i++] = c;
	}
	s[i] = '\0';
	return 1;
}

static int hash(void *p)
{
	char *chave = (char *)p;
	int h = 0;
	for (int i = 0; chave[i]; i++) {
		h += (i + 1) * chave[i];
	}
	return h;
}

static int cmp_chaves(void *p1, void *p2)
{
	char *chave_busca = (char *)p1;
	char *chave_orig = (char *)p2;
	return strcmp(chave_busca, chave_orig);
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

static Palavra *acessa(HashGen * tab, char *s)
{
	Palavra *p = hgen_busca(tab, s, cmp_chaves);
	if (!p) {
		p = (Palavra *) aloca(sizeof(Palavra));
		p->n = 0;
		strcpy(p->s, s);
		hgen_insere(tab, p->s, p, cmp_chaves);
	}
	return p;
}

static void *popula(void *info, void *dado)
{
	Palavra *p = (Palavra *) info;
	Vetor *vet = (Vetor *) dado;

	if (vet->n == vet->dim) {
		vet->dim *= 2;
		vet->v =
		    (Palavra **) realloc(vet->v, vet->dim * sizeof(Palavra *));
		if (!vet->v) {
			perror("");
			exit(EXIT_FAILURE);
		}
	}
	vet->v[vet->n++] = p;
	return NULL;
}

static int cmp_palavras(const void *v1, const void *v2)
{
	Palavra **p1 = (Palavra **) v1;
	Palavra **p2 = (Palavra **) v2;
	if ((*p1)->n == (*p2)->n) {
		return strcmp((*p1)->s, (*p2)->s);
	}
	return (*p2)->n - (*p1)->n;
}

static void imprime(HashGen * tab)
{
	Vetor *palavras = (Vetor *) aloca(sizeof(Vetor));
	palavras->n = 0;
	palavras->dim = 4;
	palavras->v = (Palavra **) aloca(palavras->dim * sizeof(Palavra *));

	hgen_percorre(tab, popula, palavras);
	qsort(palavras->v, palavras->n, sizeof(Palavra *), cmp_palavras);
	for (int i = 0; i < palavras->n; i++) {
		Palavra *p = palavras->v[i];
		printf("%s: %d\n", p->s, p->n);
	}
	free(palavras->v);
	free(palavras);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *f = fopen(argv[1], "rt");
	if (!f) {
		perror("");
		exit(EXIT_FAILURE);
	}
	char s[NPAL];
	HashGen *tab = hgen_cria(hash);
	while (le_palavra(f, s)) {
		Palavra *p = acessa(tab, s);
		p->n++;
	}
	fclose(f);
	imprime(tab);
	hgen_libera(tab, free);
	return 0;
}
