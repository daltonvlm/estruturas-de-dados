#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct complexo Complexo;

Complexo *cmplx_cria(float a, float b);
void cmplx_libera(Complexo * c);
Complexo *cmplx_soma(Complexo * c1, Complexo * c2);
Complexo *cmplx_subtrai(Complexo * c1, Complexo * c2);
Complexo *cmplx_multiplica(Complexo * c1, Complexo * c2);
Complexo *cmplx_divide(Complexo * c1, Complexo * c2);
void cmplx_imprime(Complexo * c);

#endif
