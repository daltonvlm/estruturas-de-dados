#ifndef LISTA2_INT_H
#define LISTA2_INT_H

typedef struct lista2 Lista2;

Lista2 *lst2_cria(void);
void lst2_libera(Lista2 * lst);
void lst2_insere_inicio(Lista2 * lst, int info);
void lst2_insere_final(Lista2 * lst, int info);
void lst2_retira(Lista2 * lst, int info);
int lst2_vazia(Lista2 * lst);

#endif
