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

typedef struct vetpalavra VetPalavra;
struct vetpalavra {
	int n;
	int dim;
	Palavra **v;
};

static int cb_hash(void *key)
{
	char *s = (char *)key;
	int h = 0;
	for (int i = 0; s[i]; i++) {
		h += s[i];
	}
	return h;
}

static void cb_libera(void *v1, void *v2)
{
	free(v2);
}

static int cb_cmp_palavra(const void *v1, const void *v2)
{
	Palavra **p1 = (Palavra **) v1;
	Palavra **p2 = (Palavra **) v2;

	int dif = (*p2)->n - (*p1)->n;

	if (!dif) {
		return strcmp((*p1)->s, (*p2)->s);
	}
	return dif;
}

static void *cb_insere(void *k, void *v, void *d)
{
	Palavra *p = (Palavra *) v;
	VetPalavra *vp = (VetPalavra *) d;

	if (vp->n < vp->dim) {
		vp->v[vp->n++] = p;
		return NULL;
	}
	return d;
}

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

static void imprime(int np, HashGen * tab)
{
	VetPalavra *vp = (VetPalavra *) aloca(sizeof(VetPalavra));
	vp->n = 0;
	vp->dim = np;
	vp->v = (Palavra **) aloca(vp->dim * sizeof(Palavra *));

	hgen_percorre(tab, cb_insere, vp);
	qsort(vp->v, np, sizeof(Palavra *), cb_cmp_palavra);

	for (int i = 0; i < np; i++) {
		printf("%s = %d\n", vp->v[i]->s, vp->v[i]->n);
	}

	free(vp->v);
	free(vp);
}

static int cb_cmp_string(void *v1, void *v2)
{
	char *k = (char *)v1;
	char *s = (char *)v2;
	return strcmp(k, s);
}

static int le_arquivo(FILE * fp, char *s)
{
	int i = 0;
	int c;
	while ((c = fgetc(fp)) != EOF) {
		if (isalpha(c)) {
			break;
		}
	}
	if (EOF == c) {
		return 0;
	}
	s[i++] = c;
	while (i < NPAL - 1 && ((c = fgetc(fp)) != EOF) && isalpha(c)) {
		s[i++] = c;
	}
	s[i] = '\0';
	return 1;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char s[NPAL];
	int np = 0;
	FILE *fp = fopen(argv[1], "rt");
	HashGen *tab = hgen_cria(cb_hash);

	if (!fp) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}

	while (le_arquivo(fp, s)) {
		Palavra *p = (Palavra *) hgen_busca(tab, s, cb_cmp_string);
		if (!p) {
			np++;
			p = (Palavra *) aloca(sizeof(Palavra));
			p->n = 0;
			strcpy(p->s, s);
			hgen_insere(tab, p->s, p);
		}
		p->n++;
	}
	fclose(fp);

	imprime(np, tab);
	hgen_libera(tab, cb_libera);
	return 0;
}
