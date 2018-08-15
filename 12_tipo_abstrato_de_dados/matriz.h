/* TAD: matriz m por n */
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

Matriz *mat_cria(int m, int n);
void mat_libera(Matriz * mat);
float mat_acessa(Matriz * mat, int i, int j);
void mat_atribui(Matriz * mat, int i, int j, float v);
int mat_linhas(Matriz * mat);
int mat_colunas(Matriz * mat);

#endif
