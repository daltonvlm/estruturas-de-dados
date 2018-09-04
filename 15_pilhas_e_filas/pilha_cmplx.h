#ifndef PILHA_CMPLX_H
#define PILHA_CMPLX_H

#include "complexo.h"

typedef struct pilha Pilha;

Pilha *pilha_cria(void);
void pilha_push(Pilha * p, Complexo * c);
Complexo *pilha_pop(Pilha * p);
int pilha_vazia(Pilha * p);
void pilha_libera(Pilha * p);
void pilha_imprime(Pilha * p);

#endif
