#ifndef ABB_INT_H
#define ABB_INT_H

typedef struct arv Arv;
typedef struct arvno ArvNo;

Arv *abb_cria();
void abb_libera(Arv * a);
void abb_insere(Arv * a, int v);
void abb_retira(Arv * a, int v);
ArvNo *abb_busca(Arv * a, int v);
int abb_vazia(Arv * a);
void abb_imprime(Arv * a);
void abb_imprime_ordenado(Arv * a);

#endif
