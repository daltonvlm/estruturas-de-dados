/*
 * Crie um TAD para representar vetor dinâmico genérico capaz de armazenar pon-
 * teiro para qualquer tipo. A interface deste TAD deve serguir o arquivo "vetgen.h":
 *
 * 		// Vetor genérico que armazena void
 * 		typedef struct vetorgen VetorGen;
 *
 *		// cria vetor vazio
 *		VetorGen* vgen_cria (void);
 *
 *		// insere novo elemento no final do vetor
 *		void vgen_insere (VetorGen* v, void* p);
 *
 *		// retorna o número de elementos do vetor
 *		int vgen_tam (VetorGen* v);
 *
 *		// retorna a informação associada ao elemento de índice i
 *		void* vgen_acessa (VetorGen* v, int i);
 *
 *		// percorre os elementos do vetor chamando a callback
 *		int vgen_percorre (VetorGen* v,
 *						   int (*cb) (void* info, void* dado),
 *						   void* dado
 *						   );
 *
 *		// libera a memória do vetor, chamando a callback
 *		void vgen_libera (VetorGen* v, void (*cb) (void*));
 */
