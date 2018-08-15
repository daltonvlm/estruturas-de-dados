#ifndef VETORPONTOS_H
#define VETORPONTOS_H

#include "ponto.h"
#include "heap.h"

typedef struct vetorpontos VetorPontos;

VetorPontos *vetorpontos_cria(void);
void vetorpontos_insere(VetorPontos * vp, Ponto * p);
void vetorpontos_libera(VetorPontos * vp, void (*libera) (void *));
Heap *vetorpontos_cria_arestas(VetorPontos * vp);

#endif
