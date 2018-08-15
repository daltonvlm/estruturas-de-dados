/* TAD: Círculo */
#ifndef CIRCULO_H
#define CIRCULO_H

/* Dependência de módulos */
#include "ponto.h"

/* Tipo exportado */
typedef struct circulo Circulo;

/* Funções exportadas */

/*
 * Função cria
 * Aloca e retorna um círculo de centro (x, y) e raio r
 */
Circulo *circ_cria(float x, float y, float r);

/*
 * Função libera
 * Libera a memória de um círculo previamente criado
 */
void circ_libera(Circulo * c);

/*
 * Função área
 * Retorna o valor da área do círculo
 */
float circ_area(Circulo * c);

/*
 * Função interior
 * Verifica se um dado ponto p está dentro do círculo
 */
int circ_interior(Circulo * c, Ponto * p);

#endif
