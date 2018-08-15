#include <stdio.h>
#include "aluno.h"

int main(void)
{
	float p1, p2, p3;
	Aluno *a = aluno_cria("Joao", 6.5, 3.0, 9.2);

	aluno_getnotas(a, &p1, &p2, &p3);

	printf("Nome: %s\n", aluno_getnome(a));
	printf("Notas: %.2f %.2f %.2f\n", p1, p2, p3);

	aluno_libera(a);
	return 0;
}
