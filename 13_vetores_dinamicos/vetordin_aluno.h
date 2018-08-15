#ifndef VETORDIN_ALUNO_H
#define VETORDIN_ALUNO_H

#include "aluno.h"

typedef struct vetordin VetorDin;

VetorDin *vd_cria(void);
void vd_insere(VetorDin * vd, char *nome, float p1, float p2, float p3);
int vd_tam(VetorDin * vd);
Aluno *vd_acessa(VetorDin * vd, int i);
void vd_libera(VetorDin * vd);

#endif
