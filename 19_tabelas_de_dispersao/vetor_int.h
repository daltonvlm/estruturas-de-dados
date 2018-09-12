#ifndef VETORINT_H
#define VETORINT_H

typedef struct vetor Vetor;
typedef int(*CmpFunc)(const void*,const void*);

Vetor*vet_cria(int n,CmpFunc cfunc);
void vet_libera(Vetor*vet);
void vet_insere(Vetor*vet,int v);
int vet_busca(Vetor*vet,int v);
void vet_ordena(Vetor*vet);

#endif
