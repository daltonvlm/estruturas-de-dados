#ifndef HASHINT_H
#define HASHINT_H

typedef struct hash Hash;
typedef int (*HashFunc) (int);

Hash *hsh_cria(int n, HashFunc hfunc);
void hsh_libera(Hash * hsh);
void hsh_insere(Hash * hsh, int v);
int hsh_busca(Hash * hsh, int v);

#endif
