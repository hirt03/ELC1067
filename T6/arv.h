#ifndef _ARV_H_
#define _ARV_H_
#include <stdbool.h>

/* enumerador para operador ou operando */
typedef enum {OPERADOR, OPERANDO} op_tipo_t;

typedef struct op_t {
	op_tipo_t tipo;			/* tipo operador ou operando */
	/* union de operador/operando: apenas um deles pode ser usado */
	/* nunca usar ambos ao mesmo tempo */
	union {
		double operando;
		char operador;
	} u;
} op_t;

typedef struct _arv {
	struct _arv* esq;
	struct _arv* dir;

	/* o tipo do nó será operador ou operando */
	op_t dado;
} arv_t;

/* criar uma árvore com o operador ou operando */
arv_t* arv_cria(op_t op);

/* insere um novo dado na árvore a esquerda */
arv_t* arv_insere_esquerda(arv_t* arv, arv_t* op);

/* insere um novo dado na árvore a direita */
arv_t* arv_insere_direita(arv_t* arv, arv_t* op);

/* imprime a árvore em pré-ordem: raiz, esquerda, e direita */
void arv_imprime_pre_ordem(arv_t* arv);

/* imprime a árvore em ordem: esquerda, raiz, e direita */
void arv_imprime_em_ordem(arv_t* arv);

/* imprime a árvore em pós-ordem: esquerda, direita, e raiz */
void arv_imprime_pos_ordem(arv_t* arv);

/*  destroi toda a árvore */
void arv_destroi(arv_t* arv);

#endif /* _ARV_H_ */
