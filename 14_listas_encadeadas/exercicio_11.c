/*
 * Implemente as funções para retirar elementos do início e do final de uma lista
 * duplamente encadeada. Os protótipos das funções devem ser:
 * 
 * 		void retira_inicio (Lista2* l);
 * 		void retira_final (Lista2* l);
 */

void retira_inicio(Lista2 * l)
{
	if (l->prim) {
		ListaNo *p = l->prim;
		if (p->prox) {
			p->prox->ant = NULL;
		} else {
			l->ult = NULL;
		}
		l->prim = p->prox;
		free(p);
	}
}

void retira_final(Lista2 * l)
{
	if (l->ult) {
		ListaNo *p = l->ult;
		if (p->ant) {
			p->ant->prox = NULL;
		} else {
			l->prim = NULL;
		}
		l->ult = p->ant;
		free(p);
	}
}
