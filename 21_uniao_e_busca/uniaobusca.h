#ifndef UNIAOBUSCA_H
#define UNIAOBUSCA_H
typedef struct uniaobusca UniaoBusca;

UniaoBusca *ub_cria(int n);
void ub_libera(UniaoBusca * ub);
int ub_busca(UniaoBusca * ub, int x);
int ub_uniao(UniaoBusca * ub, int x, int y);
#endif
