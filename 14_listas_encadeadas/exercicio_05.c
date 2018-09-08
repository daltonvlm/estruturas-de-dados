/*
 * Considerando listas de valores inteiros, implemente uma função que receba como
 * parâmetros uma lista encadeada e um valor inteiro x, e retire da lista todas as
 * ocorrências de x. Essa função deve obedecer ao protótipo:
 *
 * 		void retira_n (Lista* l, int x);
 */

void retira_n(Lista * l, int x)
{
	ListaNo **p = &l->prim;
	while (*p) {
		if ((*p)->info == x) {
			ListaNo *t = *p;
			*p = (*p)->prox;
			free(t);
		} else {
			p = &(*p)->prox;
		}
	}
}
