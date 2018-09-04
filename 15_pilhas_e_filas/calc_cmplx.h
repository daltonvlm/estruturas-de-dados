#ifndef CALC_CMPLX_H
#define CALC_CMPLX_H

#include "complexo.h"

typedef struct calc Calc;

Calc *calc_cria(void);
void calc_operando(Calc * c, float a, float b);
void calc_operador(Calc * c, char op);
void calc_libera(Calc * c);

#endif
