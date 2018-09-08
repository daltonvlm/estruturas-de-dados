/*
 * Considere uma estrutura para representar os dados de um aluno:
 *
 * 		typedef struct aluno Aluno;
 * 		struct aluno {
 * 			char nome[81];
 * 			float p1, p2, p3;	// notas em provas
 * 		};
 *
 * 
 * Considere ainda uma árvores binária de busca que armazena informações de alunos,
 * ordenada por ordem alfabética dos nomes:
 *
 * 		typedef struct arv Arv;
 * 		typedef struct arvno ArvNo;
 * 		struct arvno {
 * 			Aluno info;
 * 			ArvNo* esq;
 * 			ArvNo* dir;
 * 		};
 * 		struct arv {
 * 			ArvNo* raiz;
 * 		};
 *
 *
 * Pede-se:
 *
 * 	(a)	Implemente uma função para criar uma árvore vazia:
 * 		
 * 			Arv* aa_cria (void);
 *
 * 	(b)	Implemente uma função para inserir os dados de um novo aluno na estrutura:
 *
 * 			void aa_insere (Arv* a, char* nome,
 * 							float p1, float p2, float p3);
 *
 * 	(c)	Implemente uma função que, dado um nome de uma aluno, retorne a média
 * 		das notas das provas:
 *
 * 			float aa_media (Arv* a, char* nome);
 *
 * 	(d)	Implemente uma função para retirar um aluno da estrutura, dado o seu nome:
 *
 * 			void aa_retira (Arv* a, char* nome);
 *
 * 	(e)	Implemente uma função para liberar a estrutra da árvore de alunos:
 *
 * 			void aa_libera (Arv* a);
 */

static void *aloca(size_t n)
{
	void *p = malloc(n);
	if (!p) {
		perror("");
		exit(EXIT_FAILURE);
	}
	return p;
}

Arv *aa_cria(void)
{
	Arv *a = (Arv *) aloca(sizeof(Arv));
	a->raiz = NULL;
	return a;
}

void aa_insere(Arv * a, char *nome, float p1, float p2, float p3)
{
	ArvNo **p = &a->raiz;

	ArvNo *no = (ArvNo *) aloca(sizeof(ArvNo));
	strcpy(no->info.nome, nome);
	no->info.p1 = p1;
	no->info.p2 = p2;
	no->info.p3 = p3;

	while (*p) {
		int cmp = strcmp(nome, (*p)->info.nome);
		p = cmp <= 0 ? &(*p)->esq : &(*p)->dir;
	}
	*p = no;
}

static Aluno *busca_aluno(ArvNo * r, char *nome)
{
	if (r) {
		int cmp = strcmp(nome, r->info.nome);
		if (cmp < 0) {
			return busca_aluno(r->esq, nome);
		}
		if (cmp > 0) {
			return busca_aluno(r->dir, nome);
		}
		return &r->info;
	}
	return NULL;
}

float aa_media(Arv * a, char *nome)
{
	Aluno *p = busca_aluno(a->raiz, nome);
	if (p) {
		return (p->p1 + p->p2 + p->p3) / 3;
	}
	return -1;
}

static ArvNo **busca_arvno(ArvNo ** p, char *nome)
{
	int cmp;
	while (*p && (cmp = strcmp(nome, (*p)->info.nome))) {
		p = cmp < 0 ? &(*p)->esq : &(*p)->dir;
	}
	return p;
}

void aa_retira(Arv * a, char *nome)
{
	ArvNo **p = busca_arvno(&a->raiz, nome);
	if (*p) {
		do {
			ArvNo **q = &(*p)->esq;
			while (*q && (*q)->dir) {
				q = &(*q)->dir;
			}
			if (!(*q)) {
				break;
			}
			Aluno t = (*p)->info;
			(*p)->info = (*q)->info;
			(*q)->info = t;
			p = q;
		} while (*p);
		ArvNo *t = *p;
		*p = t->dir;
		free(t);
	}
}

static void libera(ArvNo * r)
{
	if (r) {
		libera(r->esq);
		libera(r->dir);
		free(r);
	}
}

void aa_libera(Arv * a)
{
	libera(a->raiz);
	free(a);
}
