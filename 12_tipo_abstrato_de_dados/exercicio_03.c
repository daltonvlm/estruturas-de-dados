/*
 * Defina a interface e implemente um TAD para representar números complexos.
 * Sabe-se que um número complexo é representado por a + bi, onde a e b são números
 * reais e i a unidade imaginária. O TAD deve implementar as seguintes operações:
 *
 * 	(a)	Função para criar um número complexo, dados a e b.
 * 	(b)	Função para liberar um número complexo previamente criado.
 * 	(c)	Função para somar dois números complexos, retornando um novo número com
 * 		o resultado da operação. Sab-se que:
 *
 * 			(a + bi) + (c + di) = (a + c) + (b + d)i
 *
 * 	(d) Função para subtrair dois números complexos, retornando um novo número
 * 		com o resultado da operação. Sabe-se que:
 *
 * 			(a + bi) - (c + di) = (a - c) + (b - d)i
 *
 * 	(e)	Função para multiplicar dois números complexos, retornando um novo número
 * 		com o resultado da operação. Sabe-se que:
 *
 * 			(a + bi)(c + di) = (ac - bd) + (bc + ad)i
 *
 * 	(f) Função para dividir dois números complexos, retornando um novo número
 * 		com o resultado da operação. Sabe-se que:
 *
 * 			(a + bi)/(c + di) = (ac + bd)/(c^2 + d^2) + ((bc - ad)/(c^2 + d^2))i
 *
 * 	Escreva um programa que use números complexos para testar sua implementação.
 */
