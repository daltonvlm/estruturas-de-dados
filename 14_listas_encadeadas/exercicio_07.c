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

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

Lista *merge(Lista * l1, Lista * l2)
{
	Lista *merge = (Lista *) aloca(sizeof(Lista));
	No **p = &merge->prim;
	while (l1->prim && l2->prim) {
		No *t1 = l1->prim;
		No *t2 = l2->prim;

		l1->prim = t1->prox;
		l2->prim = t2->prox;

		t1->prox = t2;
		*p = t1;
		p = &t2->prox;
	}
	*p = l1->prim ? l1->prim : l2->prim;
	l1->prim = NULL;
	l2->prim = NULL;
	/*
	 * Trechos comentados omitidos devido ao fato do código de exemplo não usar alocação dinâmica
	 * de memória.
	 */
	// free(l1);
	// free(l2);
	return merge;
}

static void imprime(Lista * lst)
{
	for (No * p = lst->prim; p; p = p->prox) {
		printf("%.2f -> ", p->info);
	}
	puts("NULL");
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
