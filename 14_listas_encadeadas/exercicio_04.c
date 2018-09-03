/*
 * Implemente uma função que receba duas listas encadeadas de valores reais e trans-
 * fira para o final da primeira lista os elementos da segunda. No final, a primeira lista
 * representará a concatenação das duas listas e a segunda lista estará vazia. Essa
 * função deve obedecer ao protótipo:
 *
 * 		void concatena (Lista* l1, Lista* l2);
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

void concatena(Lista * l1, Lista * l2)
{
	No **p = &l1->prim;
	while (*p) {
		p = &(*p)->prox;
	}
	*p = l2->prim;
	l2->prim = NULL;
}

void imprime(Lista * lst)
{
	for (No * p = lst->prim; p; p = p->prox) {
		printf("%.2f -> ", p->info);
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
	No no4 = { 4, NULL };
	No no3 = { 3, &no4 };
	No no2 = { 2, &no3 };
	No no1 = { 1, &no2 };
	No no0 = { 0, &no1 };
	Lista lst1 = { &no0 };
	Lista lst2 = { &no5 };
	concatena(&lst1, &lst2);
	imprime(&lst1);
	imprime(&lst2);
	return 0;
}
