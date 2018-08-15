/*
 * Considere uma estrutura para representar os dados de um aluno:
 *
 * 		typedef struct aluno Aluno;
 * 		struct aluno {
 * 			char nome[81];
 * 			float p1, p2, p3;	// notas em provas
 * 		};
 *
 * 
 * Considere ainda uma árvores binária de busca que armazena informações de alunos,
 * ordenada por ordem alfabética dos nomes:
 *
 * 		typedef struct arv Arv;
 * 		typedef struct arvno ArvNo;
 * 		struct arvno {
 * 			Aluno info;
 * 			ArvNo* esq;
 * 			ArvNo* dir;
 * 		};
 * 		struct arv {
 * 			ArvNo* raiz;
 * 		};
 *
 *
 * Pede-se:
 *
 * 	(a)	Implemente uma função para criar uma árvore vazia:
 * 		
 * 			Arv* aa_cria (void);
 *
 * 	(b)	Implemente uma função para inserir os dados de um novo aluno na estrutura:
 *
 * 			void aa_insere (Arv* a, char* nome,
 * 							float p1, float p2, float p3);
 *
 * 	(c)	Implemente uma função que, dado um nome de uma aluno, retorne a média
 * 		das notas das provas:
 *
 * 			float aa_media (Arv* a, char* nome);
 *
 * 	(d)	Implemente uma função para retirar um aluno da estrutura, dado o seu nome:
 *
 * 			void aa_retira (Arv* a, char* nome);
 *
 * 	(e)	Implemente uma função para liberar a estrutra da árvore de alunos:
 *
 * 			void aa_libera (Arv* a);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
typedef struct arvno ArvNo;
typedef struct arv Arv;

struct aluno {
	char nome[81];
	float p1;
	float p2;
	float p3;
};

struct arvno {
	Aluno info;
	ArvNo *esq;
	ArvNo *dir;
};

struct arv {
	ArvNo *raiz;
};

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	return p;
}

Arv *aa_cria(void)
{
	Arv *a = (Arv *) aloca(sizeof(Arv));
	a->raiz = NULL;
	return a;
}

void aa_insere(Arv * a, char *nome, float p1, float p2, float p3)
{
	ArvNo **p = &a->raiz;
	ArvNo *novo = (ArvNo *) aloca(sizeof(ArvNo));

	strcpy(novo->info.nome, nome);
	novo->info.p1 = p1;
	novo->info.p2 = p2;
	novo->info.p3 = p3;

	while (*p) {
		if (strcmp(nome, (*p)->info.nome) < 0) {
			p = &(*p)->esq;
		} else {
			p = &(*p)->dir;
		}
	}
	*p = novo;
}

float aa_media(Arv * a, char *nome)
{
	float m = -1.f;
	ArvNo *p = a->raiz;
	while (p) {
		int cmp = strcmp(nome, p->info.nome);
		if (!cmp) {
			break;
		}
		if (cmp < 0) {
			p = p->esq;
		} else {
			p = p->dir;
		}
	}
	if (p) {
		m = (p->info.p1 + p->info.p2 + p->info.p3) / 3.f;
	}
	return m;
}

void aa_retira(Arv * a, char *nome)
{
	ArvNo **p = &a->raiz;
	while (*p) {
		int cmp = strcmp(nome, (*p)->info.nome);
		if (!cmp) {
			break;
		}
		if (cmp < 0) {
			p = &(*p)->esq;
		} else {
			p = &(*p)->dir;
		}
	}
	if (*p) {
		if ((*p)->esq) {
			ArvNo **q = &(*p)->esq;
			while ((*q)->dir) {
				q = &(*q)->dir;
			}
			if (*q == (*p)->esq) {
				(*q)->dir = (*p)->dir;
				free(*p);
				*p = *q;
			} else {
				ArvNo *t = (*q)->esq;
				(*q)->esq = (*p)->esq;
				(*q)->dir = (*p)->dir;
				free(*p);
				*p = *q;
				*q = t;
			}
		} else {
			ArvNo *t = *p;
			*p = (*p)->dir;
			free(t);
		}
	}
}

static void libera(ArvNo * r)
{
	if (r) {
		libera(r->esq);
		libera(r->dir);
		free(r);
	}
}

void aa_libera(Arv * a)
{
	libera(a->raiz);
	free(a);
}

static void imprime(ArvNo * r, int n)
{
	for (int i = 0; i < n; i++) {
		printf("|  ");
	}
	if (r) {
		printf("%s\n", r->info.nome);
		imprime(r->esq, n + 1);
		imprime(r->dir, n + 1);
	} else {
		puts("X");
	}
}

static void aa_imprime(Arv * a)
{
	imprime(a->raiz, 0);
	puts("");
}

int main(void)
{
	Arv *a = aa_cria();

	aa_insere(a, "Aluno D", 0, 0, 0);
	aa_insere(a, "Aluno B", 1, 1, 1);
	aa_insere(a, "Aluno F", 2, 2, 2);
	aa_insere(a, "Aluno A", 3, 3, 3);
	aa_insere(a, "Aluno C", 4, 4, 4);
	aa_insere(a, "Aluno E", 5, 5, 5);
	aa_insere(a, "Aluno G", 6, 6, 6);

	aa_imprime(a);
	getchar();

	aa_retira(a, "Aluno C");

	aa_imprime(a);

	aa_libera(a);
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
typedef struct arv Arv;
typedef struct arvno ArvNo;

struct aluno {
	char nome[81];
	float p1, p2, p3;
};
struct arv {
	ArvNo *raiz;
};
struct arvno {
	Aluno info;
	ArvNo *esq;
	ArvNo *dir;
};

void check(void *p)
{
	if (NULL == p) {
		fprintf(stderr, "erro: memoria nao alocada\n");
		exit(EXIT_FAILURE);
	}
}

// (a)
Arv *aa_cria(void)
{
	Arv *a = (Arv *) malloc(sizeof(Arv));
	check(a);
	a->raiz = NULL;
	return a;
}

ArvNo *insere(ArvNo * r, ArvNo * p)
{
	if (NULL == r)
		return p;
	if (strcmp(r->info.nome, p->info.nome) > 0)
		r->esq = insere(r->esq, p);
	else
		r->dir = insere(r->dir, p);
	return r;
}

// (b)
void aa_insere(Arv * a, char *nome, float p1, float p2, float p3)
{
	ArvNo *p = (ArvNo *) malloc(sizeof(ArvNo));
	check(p);
	strcpy(p->info.nome, nome);
	p->info.p1 = p1;
	p->info.p2 = p2;
	p->info.p3 = p3;
	a->raiz = insere(a->raiz, p);
}

float media(ArvNo * r, char *nome)
{
	if (NULL == r)
		return -1;

	int cmp = strcmp(r->info.nome, nome);

	if (0 == cmp)
		return (r->info.p1 + r->info.p2 + r->info.p3) / 3;
	if (cmp > 0)
		return media(r->esq, nome);
	return media(r->dir, nome);
}

// (c)
float aa_media(Arv * a, char *nome)
{
	return media(a->raiz, nome);
}

ArvNo *retira(ArvNo * r, char *nome)
{
	if (NULL == r)
		return NULL;

	int cmp = strcmp(nome, r->info.nome);

	if (cmp < 0)
		r->esq = retira(r->esq, nome);
	else if (cmp > 0)
		r->dir = retira(r->dir, nome);
	else {
		ArvNo *t;
		if (NULL == r->dir) {
			t = r->esq;
			free(r);
			r = t;
		} else {
			t = r->dir;
			while (t->dir != NULL)
				t = t->dir;
			Aluno x = t->info;
			t->info = r->info;
			r->info = x;

			r->dir = retira(r->dir, nome);
		}
	}
	return r;
}

// (d) 
void aa_retira(Arv * a, char *nome)
{
	a->raiz = retira(a->raiz, nome);
}

void libera(ArvNo * r)
{
	if (r != NULL) {
		libera(r->esq);
		libera(r->dir);
		free(r);
	}
}

void aa_libera(Arv * a)
{
	libera(a->raiz);
	free(a);
}

void aluno_imprime(Aluno * a)
{
	printf("%s:\t%g\t%g\t%g\n", a->nome, a->p1, a->p2, a->p3);
}

void imprime(ArvNo * r)
{
	if (r != NULL) {
		imprime(r->esq);
		aluno_imprime(&r->info);
		imprime(r->dir);
	}
}

void aa_imprime(Arv * a)
{
	imprime(a->raiz);
}

int main(void)
{
	Arv *a = aa_cria();

	aa_insere(a, "H", 4, 2, 2);
	aa_insere(a, "J", 5, 3, 10);
	aa_insere(a, "C", 10, 9, 8);
	aa_insere(a, "D", 0, 1, 7);
	aa_insere(a, "A", 5, 5, 5);
	aa_insere(a, "L", 10, 6, 8);

	aa_imprime(a);

	aa_libera(a);

	return 0;
}
*/
