#ifndef VETORDIN_H
#define VETORDIN_H

typedef struct vetordin VetorDin;

VetorDin *vd_cria(void);
void vd_insere(VetorDin * vd, float x);
int vd_tam(VetorDin * vd);
float vd_acessa(VetorDin * vd, int i);
void vd_libera(VetorDin * vd);

#endif
