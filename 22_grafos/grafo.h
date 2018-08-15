#ifndef GRAFO_H
#define GRAFO_H

typedef struct grafo Grafo;

void grafo_dfs(Grafo * g, int v);
void grafo_bfs(Grafo * g, int v);
#endif
