#ifndef PILHA_FLOAT_H
#define PILHA_FLOAT_H
typedef struct pilha Pilha;

Pilha *pilha_cria(void);
void pilha_push(Pilha * p, float info);
float pilha_pop(Pilha * p);
int pilha_vazia(Pilha * p);
void pilha_libera(Pilha * p);
void pilha_imprime(Pilha * p);
#endif
