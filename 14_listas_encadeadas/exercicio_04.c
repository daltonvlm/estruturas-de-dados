/*
 * Implemente uma função que receba duas listas encadeadas de valores reais e trans-
 * fira para o final da primeira lista os elementos da segunda. No final, a primeira lista
 * representará a concatenação das duas listas e a segunda lista estará vazia. Essa
 * função deve obedecer ao protótipo:
 *
 * 		void concatena (Lista* l1, Lista* l2);
 */

void concatena(Lista * l1, Lista * l2)
{
	ListaNo **p = &l1->prim;
	while (*p) {
		p = &(*p)->prox;
	}
	*p = l2->prim;
	l2->prim = NULL;
}
