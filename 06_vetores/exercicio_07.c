/*
 * A média ponderada de um conjunto de valores é expressa por:
 *
 *                              m = (S: ViWi / S: wi)
 *
 * onde Wi representa os pesos associados aos valores.
 * 
 * Escreva uma função para calcular a média ponderada de um conjunto de valores.
 * A função deve receber como parâmetros os vetores dos valores e dos pesos, e deve
 * retornar a média calculada. Essa função deve obedecer ao protótipo a seguir.
 *
 *      float ponderada (int n, float *v, float *w);
 */

float ponderada(int n, float *v, float *w)
{
	float p = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		p += v[i] * w[i];
		s += w[i];
	}
	return p / s;
}
