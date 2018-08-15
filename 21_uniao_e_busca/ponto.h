#ifndef PONTO_H
#define PONTO_H
typedef struct ponto Ponto;

Ponto *ponto_cria(float x, float y, int id);
void ponto_libera(Ponto * p);
float ponto_distancia(Ponto * p, Ponto * q);
int ponto_pega_id(Ponto*p);
void ponto_imprime(Ponto*p,char*fmt);
#endif
