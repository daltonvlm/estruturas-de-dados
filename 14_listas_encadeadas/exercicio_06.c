/*
 * Considerando listas de valores inteiros, implemente uma função que receba como
 * parâmetro uma lista encadeada e um valor inteiro x e divida a lista em duas, de
 * tal forma que a segunda lista, criada dentro da função, comece no primeiro nó logo
 * após a primeira ocorrência de x na lista original. A função deve ter como valor
 * de retorno a lista criada, mesmo que ela seja vazia. A Figura 14.10 ilustra este
 * procedimento.
 *
 * Essa função deve obedecer ao protótipo:
 * 		
 * 		Lista* separa (Lista* l, int x);
 *
 * (Figura no livro)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
	int info;
	No *prox;
};

struct lista {
	No *prim;
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

Lista *separa(Lista * l, int x)
{
	No *p = l->prim;
	Lista *l2 = (Lista *) aloca(sizeof(Lista));
	l2->prim = NULL;

	while (p && p->info != x) {
		p = p->prox;
	}
	if (p) {
		l2->prim = p->prox;
		p->prox = NULL;
	}
	return l2;
}

void imprime(Lista * lst)
{
	for (No * p = lst->prim; p; p = p->prox) {
		printf("%d -> ", p->info);
	}
	puts("NULL");
}

int main(void)
{
	No no9 = { 9, NULL };
	No no8 = { 8, &no9 };
	No no7 = { 7, &no8 };
	No no6 = { 6, &no7 };
	No no5 = { 5, &no6 };
	No no4 = { 4, &no5 };
	No no3 = { 3, &no4 };
	No no2 = { 2, &no3 };
	No no1 = { 1, &no2 };
	No no0 = { 0, &no1 };
	Lista lst = { &no0 };
	Lista *lst2 = separa(&lst, 4);
	imprime(&lst);
	imprime(lst2);
	free(lst2);
	return 0;
}
