#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

struct vetor {

	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */

};

vetor_t* vetor_cria(void)
{
	struct vetor *vet = (struct vetor*)memo_aloca(sizeof(struct vetor));
	vet->n = 0;
	int i;
	for(i=0;i<20;i++)
    {
        vet->baralho[i] = (carta*)malloc(sizeof(carta));
    }
	return vet;
}

void vetor_destroi(vetor_t* vet)
{
	memo_libera(vet->baralho);
	memo_libera(vet);
}

int vetor_numelem(vetor_t *vet)
{
	return vet->n;
}

void vetor_insere_carta(vetor_t *vet, int indice, carta c)
{
    int aux = 20, i;
	if(indice > aux)
    {
        vet = (struct vetor*)realloc(vet, indice*sizeof(struct vetor));
        for(i=aux;i<indice;i++)
        {
            vet->baralho[i] = (carta*)malloc(sizeof(carta));
        }
        aux = indice;
    }
    vet->baralho[indice] = c;
	vet->n++;
}

carta vetor_remove_carta(vetor_t *vet, int indice)
{
	if(vet->baralho[indice]==NULL)
    {
        printf("ERRO NA REMOCAO");
        return NULL;
    }
    vet->baralho[indice]=NULL;
	vet->n--;
	return NULL;
}

carta vetor_acessa_carta(vetor_t *vet, int indice)
{
    carta c = vet->baralho[indice];
    if(c != NULL)
    {
        return c;
    }
    printf("CARTA NAO EXISTENTE!");
	return NULL;
}

bool vetor_valido(vetor_t *vet)
{
	/* TODO aqui */
	return false;
}
