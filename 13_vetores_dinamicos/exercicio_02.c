/*
 * Altere a implementação da cadeia de caracteres dinâmica apresentada. A fim de
 * minimizar o número de realocações, implemente a seguinte estratégia:
 *
 * 	. Se for necessário aumentar a dimensão, isto é, se n >= nmax, redimensione o
 *	  vetor para o tamanho max(n,2nmax).
 *
 * 	. Se for necessário diminuir a dimensão, caracterizado quando n < 0.5nmax,
 *	  redimensione o vetor para 0.5nmax.
 *
 * 	. Acrescente a função redimensiona na interface; esta função permite ao cliente
 * 	  ajustar a dimensão do vetor para apenas o espaço efetivamente usado para
 * 	  representar a cadeia.
 */
