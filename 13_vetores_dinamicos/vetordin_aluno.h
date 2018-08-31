#ifndef VETORDIN_ALUNO_H
#define VETORDIN_ALUNO_H

#include "aluno.h"

typedef struct vetordin_aluno VDAluno;

VDAluno *vda_cria(void);
void vda_insere(VDAluno * vda, Aluno * a);
int vda_tam(VDAluno * vda);
Aluno *vda_acessa(VDAluno * vda, int i);
void vda_libera(VDAluno * vda, int libera_alunos);

#endif
