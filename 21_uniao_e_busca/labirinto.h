#ifndef LABIRINTO_H
#define LABIRINT_H
typedef struct labirinto Labirinto;
Labirinto *labirinto_cria(int nx, int ny);
void labirinto_libera(Labirinto * m);
void labirinto_imprime(Labirinto * m);
#endif
