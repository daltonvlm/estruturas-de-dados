#ifndef LISTAGEN_H
#define LISTAGEN_H

typedef struct listagen ListaGen;

ListaGen *lgen_cria(void);
void lgen_insere(ListaGen * lst, void *p);
void *lgen_percorre(ListaGen * lst, void *(*cb) (void *info, void *dado),
		    void *dado);
void lgen_libera(ListaGen * lst, void (*cb_libera) (void *));

#endif
