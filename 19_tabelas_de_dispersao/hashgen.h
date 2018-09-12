#ifndef HASHGEN_H
#define HASHGEN_H

typedef struct hashgen HashGen;
typedef int (*HashFunc) (void *chave);

HashGen *hgen_cria(HashFunc hfunc);
void hgen_libera(HashGen * tab, void (*cb_libera) (void *info));
void hgen_insere(HashGen * tab, void *chave, void *info,
		 int (*cb_cmp) (void *chave1, void *chave2));
void *hgen_busca(HashGen * tab, void *chave,
		 int (*cb_cmp) (void *chave1, void *chave2));
void *hgen_percorre(HashGen * tab, void *(*cb) (void *info, void *dado),
		    void *dado);

#endif
