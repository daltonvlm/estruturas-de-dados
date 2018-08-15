#ifndef ABB_H
#define ABB_H
typedef struct arv Arv;
typedef struct arvno ArvNo;

Arv *abb_cria(void);
void abb_libera(Arv * a);
void abb_insere(Arv * a, int v);
void abb_retira(Arv * a, int v);
void abb_imprime(Arv * a);
void abb_imprime_ordenado(Arv * a);
ArvNo *abb_busca(Arv * a, int v);
#endif
