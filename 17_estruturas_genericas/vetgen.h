#ifndef VETGEN_H
#define VETGEN_H
typedef struct vetorgen VetorGen;

VetorGen *vgen_cria(void);
void vgen_insere(VetorGen * v, void *p);
int vgen_tam(VetorGen * v);
void *vgen_acessa(VetorGen * v, int i);
int vgen_percorre(VetorGen * v, int (*cb) (void *info, void *dado), void *dado);
void vgen_libera(VetorGen * v, void (*cb) (void *));
#endif
