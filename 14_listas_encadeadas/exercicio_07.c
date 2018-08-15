/*
 * Implemente uma função que construa uma nova lista, intercalando os nós de outras
 * duas listas passadas como parâmetros. Essa função deve retornar a nova lista
 * resultante, criada dentro da função, conforme ilustrado na Figura 14.11.
 *
 * (Figura no livro)
 *
 * Ao final da função, as listas originais devem ficar vazias e ser liberadas. Se uma
 * lista tiver mais elementos que a outra, os elementos excedentes são transferidos na
 * mesma ordem para a nova lista. Essa função deve obedecer ao protótipo:
 *
 * 		Lista* merge (Lista* l1, Lista* l2);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
	float info;
	No *prox;
};

struct lista {
	No *prim;
};

Lista *merge(Lista * l1, Lista * l2)
{
	Lista *r = (Lista *) malloc(sizeof(Lista));
	No **p;

	if (!r) {
		perror("Erro");
		exit(EXIT_FAILURE);
	}
	p = &r->prim;

	while (l1->prim && l2->prim) {
		No *t1 = l1->prim;
		No *t2 = l2->prim;

		l1->prim = t1->prox;
		l2->prim = t2->prox;

		t1->prox = t2;
		*p = t1;
		p = &t2->prox;
	}

	if (l1->prim) {
		*p = l1->prim;
		l1->prim = NULL;
	} else {
		*p = l2->prim;
		l2->prim = NULL;
	}
	return r;
}

static void imprime(Lista * lst)
{
	No *p = lst->prim;

	printf("[ ");
	while (p) {
		printf("%.2f ", p->info);
		p = p->prox;
	}
	puts("]");
}

int main(void)
{
	No no9 = { 9, NULL };
	No no7 = { 7, &no9 };
	No no5 = { 5, &no7 };
	No no3 = { 3, &no5 };
	No no1 = { 1, &no3 };

	No no8 = { 8, NULL };
	No no6 = { 6, &no8 };
	No no4 = { 4, &no6 };
	No no2 = { 2, &no4 };
	No no0 = { 0, &no2 };

	Lista lst1 = { &no0 };
	Lista lst2 = { &no1 };
	Lista *lst;

	printf("Lista1: ");
	imprime(&lst1);
	printf("Lista2: ");
	imprime(&lst2);

	lst = merge(&lst1, &lst2);

	printf("Lista1: ");
	imprime(&lst1);
	printf("Lista2: ");
	imprime(&lst2);
	printf("Lista: ");
	imprime(lst);

	free(lst);

	return 0;
}
