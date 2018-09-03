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
	No *ult;
};

void retira_inicio(Lista2 * l)
{
	if (l->prim) {
		No *p = l->prim;
		if (p->prox) {
			p->prox->ant = NULL;
		} else {
			l->ult = NULL;
		}
		l->prim = p->prox;
		/*
		 * Trecho de código omitido pois o exemplo não usa alocação dinâmica.
		 */
		// free(p);
	}
}

void retira_final(Lista2 * l)
{
	if (l->ult) {
		No *p = l->ult;
		if (p->ant) {
			p->ant->prox = NULL;
		} else {
			l->prim = NULL;
		}
		l->ult = p->ant;
		/*
		 * Trecho de código omitido pois o exemplo não usa alocação dinâmica.
		 */
		// free(p);
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
	Lista2 lst = { v, v + 9 };
	imprime(&lst);
	retira_inicio(&lst);
	imprime(&lst);
	retira_final(&lst);
	imprime(&lst);
	return 0;
}
