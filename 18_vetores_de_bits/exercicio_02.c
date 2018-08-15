/*
 * Altere a implementação das funções para que as operações entre conjuntos tratem
 * operandos com dimensões diferentes. Por exemplo, suponha fazer uma operação
 * entre dois conjuntos A e B com a dimensão de A maior que a de B. Neste caso,
 * elementos do vetor de A não terão correspondentes em B. Para tratar este caso,
 * podemos ter um valor adicional que representa o valor dos elementos ausentes no
 * vetor. Na criação, este valor será zero, pois podemos considerar que os elementos
 * não representados não estão presentes no conjunto. No entanto, se formos avaliar o
 * complemento deste conjunto, também temos que avaliar o complemento deste valor
 * dos ausentes. Nesta implementação, é como se nosso universo fosse ilimitado, mas
 * apenas alguns elementos estão inseridos no conjunto.
 */
