/*
 * Implemente uma função que receba como parâmetro uma lista encadeada e inverta o
 * encadeamento de seus nós. Após a execução dessa função, cada nó da lista vai estar
 * apontando para o nó que originalmente era seu antecessor, e o último nó da lista
 * passará a ser o primeiro nó da lista invertida, conforme ilustrado na Figura 14.12.
 *
 * (Figura no livro)
 *
 * Essa função deve obedecer ao protótipo:
 *
 * 		void inverte (Lista* l);
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

void inverte(Lista * l)
{
	No *ant = NULL;
	for (No * p = l->prim; p; p = l->prim) {
		l->prim = p->prox;
		p->prox = ant;
		ant = p;
	}
	l->prim = ant;
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
	inverte(&lst);
	imprime(&lst);

	return 0;
}
