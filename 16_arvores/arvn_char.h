#ifndef ARVN_CHAR_H
#define ARVN_CHAR_H

typedef struct arvnno ArvnNo;
typedef struct arvn Arvn;

ArvnNo *arvn_criano(char c);
void arvn_insere(ArvnNo * a, ArvnNo * sa);
Arvn *arvn_cria(ArvnNo * r);
void arvn_imprime(Arvn * a);
ArvnNo *arvn_busca(Arvn * a, char c);
void arvn_libera(Arvn * a);
int arvn_altura(Arvn * a);

#endif
