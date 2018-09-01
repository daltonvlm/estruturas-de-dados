#ifndef LISTA_INT_H
#define LISTA_INT_H

typedef struct lista Lista;

Lista *lst_cria(void);
void lst_libera(Lista * lst);
void lst_libera_rec(Lista * lst);

void lst_insere(Lista * lst, int info);
void lst_insere_ordenado(Lista * lst, int info);
void lst_retira(Lista * lst, int info);
void lst_retira_rec(Lista * lst, int info);

int lst_vazia(Lista * lst);
int lst_pertence(Lista * lst, int info);
void lst_imprime(Lista * lst);
void lst_imprime_rec(Lista * lst);
void lst_imprime_rev(Lista * lst);

int lst_igual(Lista * lst1, Lista * lst2);
int lst_igual_rec(Lista * lst1, Lista * lst2);

#endif
