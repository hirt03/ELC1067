#ifndef _CARTA_H_
#define _CARTA_H_
#include <stdlib.h> // para NULL
#include <stdbool.h> // para bool

/* definicao do tipo carta */
typedef struct _carta* carta;

typedef enum {
    PAUS,
    ESPADAS,
    COPAS,
    OUROS
} naipe;

typedef enum {
    AS = 1,
    VALETE = 11,
    DAMA,
    REI
} valor;

/* fun��es que permitem realizar opera��es sobre uma carta */

/* retorna uma nova carta, criado a partir do valor v e naipe n.
 * a carta ser� criada fechada.
 * Se v ou n forem inv�lidos, retorna NULL.
 */
carta carta_cria(valor v, naipe n);

/* destr�i a carta c */
void carta_destroi(carta c);

/* retorna o valor da carta c. */
valor carta_valor(carta c);
char *carta_valor_str(carta c);

/* retorna o naipe da carta c. */
naipe carta_naipe(carta c);
char *carta_naipe_str(carta c);

/* abre a carta c */
void carta_abre(carta c);

/* fecha a carta c */
void carta_fecha(carta c);

/* retorna true se a carta c estiver aberta. */
bool carta_aberta(carta c);

/* retorna true se c for uma carta v�lida */
bool carta_valida(carta c);

#endif
