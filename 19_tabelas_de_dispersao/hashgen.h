#ifndef HASHGEN_H
#define HASHGEN_H
typedef struct hashgen HashGen;

typedef int (*HashFunc) (void *key);

HashGen *hgen_cria(HashFunc hfunc);
void hgen_libera(HashGen * tab, void (*libera) (void *key, void *info));
void hgen_insere(HashGen * tab, void *key, void *info);
void *hgen_busca(HashGen * tab, void *key, int (*cmp) (void *, void *));
void *hgen_percorre(HashGen * tab,
		    void *(*cb) (void *key, void *info, void *dado),
		    void *dado);
#endif
