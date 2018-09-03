/*
 * Considerando listas de valores inteiros, implemente uma função que receba como
 * parâmetros uma lista encadeada e um valor inteiro x, e retire da lista todas as
 * ocorrências de x. Essa função deve obedecer ao protótipo:
 *
 * 		void retira_n (Lista* l, int x);
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

void retira_n(Lista * l, int x)
{
	No **p = &l->prim;
	while (*p) {
		if ((*p)->info == x) {
			/* 
			 * Os trechos comentados foram omitidos pois o código de exemplo não usa alocação
			 * dinâmica.
			 */
			// No*t=*p;
			*p = (*p)->prox;
			// free(t);
		} else {
			p = &(*p)->prox;
		}
	}
}

int main(void)
{
	No no9 = { 9, NULL };
	No no8 = { 2, &no9 };
	No no7 = { 7, &no8 };
	No no6 = { 2, &no7 };
	No no5 = { 5, &no6 };
	No no4 = { 2, &no5 };
	No no3 = { 3, &no4 };
	No no2 = { 2, &no3 };
	No no1 = { 1, &no2 };
	No no0 = { 2, &no1 };
	Lista lst = { &no0 };
	retira_n(&lst, 2);
	for (No * p = lst.prim; p; p = p->prox) {
		printf("%d -> ", p->info);
	}
	puts("NULL");
	return 0;
}
