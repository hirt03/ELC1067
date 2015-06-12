#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "arv.h"
#include "pilha.h"
#include "memo.h"

int main(int argc, char **argv)
{
	/* exemplo simples de árvore */
	arv_t* raiz, *operando, *operador;
	op_t n1, operacao;
	pilha_t* pilha;
	pilha = pilha_cria();
	int aux2, aux3, loop = 1;

	n1.tipo = OPERANDO;
	operacao.tipo = OPERADOR;

	while(loop == 1)
    {
       printf("Digite 1 para inserir operando, 2 para operador e 0 quando a funcao for terminada:\n");
       scanf("%d", &aux3);
	   if(aux3 == 1)
       {
           printf("Digite o operando:\n");
           scanf("%lf", &n1.u.operando);
           operando = arv_cria(n1);
           pilha_insere(pilha, operando);
       }
       if(aux3 == 2)
       {
           printf("Digite o operador:\n");
           scanf(" %c", &operacao.u.operador);
           operador = arv_cria(operacao);
           arv_t *aux = pilha_remove(pilha);
           operador = arv_insere_direita(operador, aux);
           aux = pilha_remove(pilha);
           operador = arv_insere_esquerda(operador, aux);
           pilha_insere(pilha, operador);
       }
       if(aux3 == 0)
       {
           loop = 0;
       }
   }


	printf("Digite 1 para imprimir em ordem, 2 para impirimir em pre-ordem e 3 para imprimir pos-ordem\n");
	scanf("%d", &aux2);
	if(aux2 == 1)
    {
        printf("Arvore em ordem:\n");
        arv_imprime_em_ordem(pilha->topo->arv);
    }
    if(aux2 == 2)
    {
        printf("Arvore pre-ordem:\n");
        arv_imprime_pre_ordem(pilha->topo->arv);
    }
    if(aux2 == 3)
    {
        printf("Arvore pos-ordem:\n");
        arv_imprime_pos_ordem(pilha->topo->arv);
    }
    raiz = pilha_remove(pilha);
	pilha_destroi(pilha);
	arv_destroi(raiz);
	memo_relatorio();
	}
