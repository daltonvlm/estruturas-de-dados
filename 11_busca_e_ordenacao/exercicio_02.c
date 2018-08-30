/*
 * Considere um cadastro de pessoas que armazena nome e data de nascimento (re-
 * presentada por três inteiros: dia, mês, ano). O cadastro é representado por um
 * vetor de ponteiros para a estrutura a seguir, ordenado em ordem crescente de data
 * de nascimento:
 *
 * 		typedef struct pessoa Pessoa;
 * 		struct pessoa {
 * 			char nome[81];		// nome
 * 			int dia, mes, ano;	// data de nascimento
 * 		};
 *
 * Aplicando a técnica de busca binária (usando ou não a função bsearch da biblioteca
 * padrão), implemente uma função que verifique se alguém nasceu numa determinada
 * data. A função deve receber o número de elementos no vetor, o vetor de ponteiros
 * e a data que se deseja fazer a busca. Caso seja encontrada uma pessoa que tenha
 * nascido na data especificada, a função deve retornar o ponteiro para a estrutura
 * Pessoa correspontente. Se não existir uma pessoa no cadastro que tenha nascido
 * na data especificada, a função deve retornar NULL. A função deve obedecer ao
 * seguinte protótipo:
 *
 * 		Pessoa* busca (int n, Pessoa** v, int dia, int mes, int ano);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa {
	char nome[81];		// nome
	int dia, mes, ano;	// data de nascimento
};

static int compara_pessoa_data(Pessoa * info, Pessoa * elem)
{
	int ano = info->ano - elem->ano;
	int mes = info->mes - elem->mes;
	int dia = info->dia - elem->dia;
	return (ano ? ano : (mes ? mes : dia));
}

Pessoa *busca(int n, Pessoa ** v, int dia, int mes, int ano)
{
	int i = 0;
	int f = n - 1;
	Pessoa info = {.dia = dia,.mes = mes,.ano = ano };
	while (i <= f) {
		int m = (i + f) / 2;
		int cmp = compara_pessoa_data(&info, v[m]);
		if (cmp < 0) {
			f = m - 1;
		} else if (cmp > 0) {
			i = m + 1;
		} else {
			return v[m];
		}
	}
	return NULL;
}

int main(void)
{
	Pessoa vp[6] = {
		{"John McCarthy", 4, 9, 1927},
		{"Dennis Ritchie", 9, 9, 1941},
		{"Bjarne Stroustrup", 30, 12, 1950},
		{"James Gosling", 19, 5, 1955},
		{"Guido van Rossum", 31, 1, 1956},
		{"Yukihir Matsumoto", 14, 4, 1965}
	};
	Pessoa *vpp[6] = { vp, vp + 1, vp + 2, vp + 3, vp + 4, vp + 5 };
	char buf[121];
	int dia, mes, ano;
	while (1) {
		printf("Data (dia, mes, ano): ");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d %d %d", &dia, &mes, &ano);
		Pessoa *pp = busca(6, vpp, dia, mes, ano);
		puts(pp ? pp->nome : "Nenhuma pessoa encontrada.");
	}
	return 0;
}
