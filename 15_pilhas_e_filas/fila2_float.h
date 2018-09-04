#ifndef FILA2_FLOAT_H
#define FILA2_FLOAT_H
typedef struct fila2 Fila2;

Fila2 *fila2_cria(void);
void fila2_insere_ini(Fila2 * f, float v);
void fila2_insere_fim(Fila2 * f, float v);
float fila2_retira_ini(Fila2 * f);
float fila2_retira_fim(Fila2 * f);
int fila2_vazia(Fila2 * f);
void fila2_libera(Fila2 * f);
void fila2_imprime(Fila2 * f);
#endif
