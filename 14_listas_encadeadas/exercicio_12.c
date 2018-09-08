/*
 * Implemente funções para inserir e retirar um elemento de uma lista circular dupla-
 * mente encadeada.
 */

static void *aloca(int n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

void insere(Lista * lst, int info)
{
	ListaNo *p = (ListaNo *) aloca(sizeof(ListaNo));
	p->info = info;
	p->ant = p->prox = p;
	if (lst->prim) {
		p->prox = lst->prim;
		p->ant = lst->prim->ant;
		p->ant->prox = p;
		p->prox->ant = p;
	}
	lst->prim = p;
}

void retira(Lista * lst, int info)
{
	if (lst->prim) {
		ListaNo **p = &lst->prim;
		do {
			if ((*p)->info == info) {
				break;
			}
			p = &(*p)->prox;
		} while ((*p) != lst->prim);
		if ((*p)->info == info) {
			ListaNo *t = *p;
			if (t == t->prox) {
				*p = NULL;
			} else {
				t->ant->prox = t->prox;
				t->prox->ant = t->ant;
				*p = t->prox;	// Uma possível duplicação ncessária para o caso de *p == lst->prim
			}
			free(t);
		}
	}
}
