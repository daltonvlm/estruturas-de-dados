#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno *aluno_cria(char *nome, float p1, float p2, float p3);
const char *aluno_getnome(Aluno * a);
void aluno_getnotas(Aluno * a, float *p1, float *p2, float *p3);
void aluno_libera(Aluno * a);

#endif
