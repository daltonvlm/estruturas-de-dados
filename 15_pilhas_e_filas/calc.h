#ifndef CALC_H
#define CALC_H
typedef struct calc Calc;

Calc *calc_cria(char *fmt);
void calc_operando(Calc * c, float v);
void calc_operador(Calc * c, char op);
void calc_libera(Calc * c);
#endif
