#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor_int.h"

struct vetor {
	int n;
	int dim;
	int *v;
	CmpFunc cfunc;
};

static void*aloca(size_t n){
	void*p=malloc(n);
	if(!p){
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

Vetor*vet_cria(int n, CmpFunc cfunc){
	Vetor*vet=(Vetor*)aloca(sizeof(Vetor));
	vet->n=0;
	vet->dim=n;
	vet->cfunc = cfunc;
	vet->v=(int*)aloca(vet->dim*sizeof(int));
	memset(vet->v,-1,vet->dim*sizeof(int));
	return vet;
}

void vet_libera(Vetor*vet){
	free(vet->v);
	free(vet);
}

void vet_insere(Vetor*vet,int v){
	if(vet->n<vet->dim){
		vet->v[vet->n++]=v;
	}
}

int vet_busca(Vetor*vet,int v){
	return !!bsearch(&v,vet->v,vet->n,sizeof(int),vet->cfunc);
}

void vet_ordena(Vetor*vet){
	qsort(vet->v,vet->n,sizeof(int),vet->cfunc);
}
