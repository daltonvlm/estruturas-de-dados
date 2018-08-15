/*
 * Modifique o módulo, implementando uma lista de prioridade genérica, insto é, que
 * armazena qualquer valor usando qualquer chave de ordenação. Para tanto, o cliente
 * passa a inserir na estrutura apenas ponteiros genéricos (void*), e fica responsável
 * também por fornecer uma função de comparação, dados dois ponteiros inseridos na
 * estrutura. Essa função de comparação pode, por exemplo, ser fornecida na criação
 * do heap:
 *
 * 		Heap* heap_cria (int (*cmp) (const void* obj1, const void* obj2));
 */
