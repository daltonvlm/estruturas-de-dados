#ifndef ARV_H
#define ARV_H

typedef struct arvno ArvNo;
typedef struct arv Arv;

Arv *arv_cria(ArvNo * raiz);
ArvNo *arv_criano(char c, ArvNo * esq, ArvNo * dir);
void arv_libera(Arv * a);
void arv_imprime(Arv * a);
int arv_pertence(Arv * a, char c);
ArvNo *arv_busca(Arv * a, char c);
int arv_altura(Arv * a);

#endif
