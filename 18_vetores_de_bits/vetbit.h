#ifndef VETBIT_H
#define VETBIT_H
typedef struct vetbit VetBit;

VetBit *vb_cria(int nmax);
void vb_libera(VetBit * s);
void vb_liga(VetBit * s, int i);
void vb_desliga(VetBit * s, int i);
int vb_acessa(VetBit * s, int i);
int vb_vazio(VetBit * s);
void vb_limpa(VetBit * s);

VetBit *vb_uniao(VetBit * a, VetBit * b);
VetBit *vb_inter(VetBit * a, VetBit * b);
VetBit *vb_compl(VetBit * s);
int vb_igual(VetBit * a, VetBit * b);
VetBit *vb_dif(VetBit * a, VetBit * b);
#endif
