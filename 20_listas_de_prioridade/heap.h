#ifndef HEAP_H
#define HEAP_H
typedef struct heap Heap;

Heap *heap_cria(int (*cmp) (const void *v1, const void *v2));
Heap *heap_constroi(int n, void **v,
		    int (*cmp) (const void *v1, const void *v2));
void heap_libera(Heap * h, void (*libera) (void *));
int heap_vazia(Heap * h);
void heap_insere(Heap * h, void *value);
void *heap_retira(Heap * h);
int heap_verifica(Heap * h);
#endif
