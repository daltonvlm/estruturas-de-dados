#ifndef STRDIN_H
#define STRDIN_H

typedef struct strdin StrDin;

StrDin *sd_criavazia(void);
StrDin *sd_criacopia(const char *s);
void sd_atribui(StrDin * sd, const char *s);
void sd_concatena(StrDin * sd, const char *s);
const char *sd_acessa(StrDin * sd);
void sd_libera(StrDin * sd);
void sd_redimensiona(StrDin * sd);

#endif
