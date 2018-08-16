/*
 * Escreva um programa para fazer conversões entre diferentes unidades. As opções
 * do programa devem ser exibidas em forma de um menu apresentado na tela, em dois
 * níveis. No primeiro nível, o usuuário escolhe a classe de unidade; no segundo nível,
 * o usuário escolhe a conversão que deseja, fornecendo então o valor a ser convertido.
 * Por fim, o programa exibe o valor resultante na tela. As opções apresentadas no
 * menu podem ser:
 *
 * 1. Peso
 *      1. Libra -> Quilograma
 *      2. Quilograma -> Libra
 *      3. Onça -> Grama
 *      4. Grama -> Onça
 * 
 * 2. Volume
 *      1. Galão -> Litro
 *      2. Litro -> Galão
 *      3. Onça -> Mililitro
 *      4. Mililitro -> Onça
 *
 * 3. Comprimento
 *      1. Milha -> Quilômetro
 *      2. Quilômetro -> Milha
 *      3. Jardas -> Metro
 *      4. Metro -> Jardas
 *
 * Sabe-se que 1 libra equivale a 0.4536 kg, 1 onça a 28.3495 g, 1 galão a 3.7854 l,
 * 1 onça fluido a 29.5735 ml, 1 milha a 1.6093 Km e 1 jarda a 0.9144m.
 */

#include <stdio.h>

int main(void)
{
	int classe, conversao;
	int erro = 0;
	float v, r;

	printf("1. Peso\n");
	printf("    1. Libra -> Quilograma\n");
	printf("    2. Quilograma -> Libra\n");
	printf("    3. Onca -> Grama\n");
	printf("    4. Grama -> Onca\n\n");
	printf("2. Volume\n");
	printf("    1. Galao -> Litro\n");
	printf("    2. Litro -> Galao\n");
	printf("    3. Onca -> Mililitro\n");
	printf("    4. Mililitro -> Onca\n\n");
	printf("3. Comprimento\n");
	printf("    1. Milha -> Quilometro\n");
	printf("    2. Quilometro -> Milha\n");
	printf("    3. Jardas -> Metro\n");
	printf("    4. Metro -> Jardas\n\n");

	printf("Classe: ");
	scanf("%d", &classe);
	printf("Conversao: ");
	scanf("%d", &conversao);
	printf("Valor: ");
	scanf("%f", &v);

	switch (classe) {
	case 1:
		switch (conversao) {
		case 1:
			r = v * 0.4536;
			break;
		case 2:
			r = v / 0.4536;
			break;
		case 3:
			r = v * 28.3495;
			break;
		case 4:
			r = v / 28.3495;
			break;
		default:
			erro = 1;
		}
		break;
	case 2:
		switch (conversao) {
		case 1:
			r = v * 3.7854;
			break;
		case 2:
			r = v / 3.7854;
			break;
		case 3:
			r = v * 29.5735;
			break;
		case 4:
			r = v / 29.5735;
			break;
		default:
			erro = 1;
		}
		break;
	case 3:
		switch (conversao) {
		case 1:
			r = v * 1.6093;
			break;
		case 2:
			r = v / 1.6093;
			break;
		case 3:
			r = v * 0.9144;
			break;
		case 4:
			r = v / 0.9144;
			break;
		default:
			erro = 1;
		}
		break;
	default:
		erro = 2;
	}
	if (erro) {
		printf("Opcao invalida para %s\n",
		       erro % 2 ? "conversao" : "classe");
	} else {
		printf("Valor convertido: %f\n", r);
	}
	return 0;
}
