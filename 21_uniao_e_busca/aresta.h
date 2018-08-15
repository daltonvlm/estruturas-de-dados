#ifndef ARESTA_H
#define ARESTA_H

#include "ponto.h"

typedef struct aresta Aresta;

Aresta *aresta_cria(Ponto * p, Ponto * q);
void aresta_libera(Aresta * a, void (*libera) (void *));
float aresta_pega_distancia(Aresta * a);
void aresta_pega_pontos(Aresta*a,Ponto**p,Ponto**q);
void aresta_imprime(Aresta*a);

#endif
