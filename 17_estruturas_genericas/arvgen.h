#ifndef ARVGEN_H
#define ARVGEN_H
typedef struct arvgen ArvGen;

ArvGen *agen_cria(int (*cb) (void *chave, void *info));
void agen_insere(ArvGen * a, void *chave, void *info);
void *agen_busca(ArvGen * a, void *chave);
int agen_percorre(ArvGen * a, int (*cb) (void *info, void *dado), void *dado);
void agen_libera(ArvGen * a, void (*cb) (void *));
#endif
