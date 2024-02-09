#ifndef _CARTAS_H_
#define _CARTAS_H_

typedef enum {
    C,
    E,
    O,
    P
} Naipe;

typedef enum {
    AS = 1,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    VALETE = 11,
    DAMA,
    REI
} Valor;

typedef struct carta{
    Valor valor;
    Naipe naipe;
    struct carta *prox;
} Carta;

typedef struct pilha{
   Carta *topo;
} Pilha;

Pilha* criaBaralho();

void empilhaCarta(Pilha *monte, Carta *carta);

void embaralhaCartas(Pilha *baralho);

void imprimeBaralho(Pilha *baralho);

#endif