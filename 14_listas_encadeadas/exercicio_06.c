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

Lista *separa(Lista * l, int x)
{
	No *p = l->prim;
	Lista *r = (Lista *) malloc(sizeof(Lista));
	if (!r) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	r->prim = NULL;

	while (p && p->info != x) {
		p = p->prox;
	}
	if (p) {
		r->prim = p->prox;
		p->prox = NULL;
	}
	return r;
}

void imprime(Lista * lst)
{
	No *p = lst->prim;
	while (p) {
		printf("%d ", p->info);
		p = p->prox;
	}
	puts("");
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

	imprime(&lst);
	Lista *r = separa(&lst, 5);
	imprime(r);
	free(r);
	return 0;
}
