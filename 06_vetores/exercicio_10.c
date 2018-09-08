/*
 * Considere histogramas como sendo o número de ocorrências de valores em diferentes
 * intervalos. Considere ainda um experimento laboratorial em que foram colhidos n
 * medições, todas elas maiores ou iguais a 0 e menores que 1. Escreva uma função
 * para preencher um vetor com 10 elementos que represente o histograma destas
 * medidas. O primeiro elemento do vetor deve armazenar o número de medidas
 * maiores ou iguais a 0 e menores que 0.1, o segundo elemento deve armazenar o
 * número de medidas maiores ou iguais a 0.1 e menores que 0.2 e assim por diante.
 *
 * A função deve receber o vetor, v, com as n medidas do experimento e deve preencher
 * o vetor h que, sabe-se, tem dimensão igual a 10. Por exemplo, se for passado como
 * entrada o vetor:
 *
 *      v = {0.11,0.2,0.03,0.56,0.323,0.345,0.234,0.56,0.6546,0.123,0.123,0.999}
 *
 * a função deve preencher o vetor h como:
 * 
 *                          h = {1,3,2,2,0,2,1,0,0,1}
 *
 * A função deve seguir o protótipo:
 *
 *      void histograma (int n, float *v, int *h);
 */

void histograma(int n, float *v, int *h)
{
	for (int i = 0; i < n; i++) {
		int x = 10 * v[i];
		h[x]++;
	}
}
