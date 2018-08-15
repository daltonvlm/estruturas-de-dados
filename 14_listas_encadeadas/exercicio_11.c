/*
 * Implemente as funções para retirar elementos do início e do final de uma lista
 * duplamente encadeada. Os protótipos das funções devem ser:
 * 
 * 		void retira_inicio (Lista2* l);
 * 		void retira_final (Lista2* l);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista2;

struct no {
	char *info;
	No *ant;
	No *prox;
};

struct lista {
	No *prim;
};

void retira_inicio(Lista2 * l)
{
	if (l->prim) {
		l->prim = l->prim->prox;
		if (l->prim) {
			l->prim->ant = NULL;
		}
	}
}

void retira_final(Lista2 * l)
{
	No **p = &l->prim;

	while (*p && (*p)->prox) {
		p = &(*p)->prox;
	}

	if (*p) {
		*p = NULL;
	}
}

static void imprime(Lista2 * lst)
{
	No *p = lst->prim;
	while (p) {
		puts(p->info);
		p = p->prox;
	}
	puts("");
}

int main(void)
{
	No v[10] = {
		{"zero", NULL, v + 1},
		{"um", v, v + 2},
		{"dois", v + 1, v + 3},
		{"tres", v + 2, v + 4},
		{"quatro", v + 3, v + 5},
		{"cinco", v + 4, v + 6},
		{"seis", v + 5, v + 7},
		{"sete", v + 6, v + 8},
		{"oito", v + 7, v + 9},
		{"nove", v + 8, NULL}
	};

	Lista2 lst = { v };

	imprime(&lst);
	retira_inicio(&lst);
	imprime(&lst);
	retira_final(&lst);
	imprime(&lst);

	return 0;
}
