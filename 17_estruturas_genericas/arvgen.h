/* Árvore binária de busca genérica */
#ifndef ARVGEN_H
#define ARVGEN_H

typedef struct arvgen ArvGen;

ArvGen *agen_cria(int (*cb_cmp) (void *chave, void *info));
void agen_insere(ArvGen * a, void *chave, void *info);
void agen_retira(ArvGen * a, void *chave, void (*cb_libera) (void *));
void *agen_busca(ArvGen * a, void *chave);
int agen_percorre(ArvGen * a, int (*cb) (void *, void *), void *dado);
void agen_libera(ArvGen * a, void (*cb_libera) (void *));

#endif
