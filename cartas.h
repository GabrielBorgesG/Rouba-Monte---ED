#ifndef _CARTAS_H_
#define _CARTAS_H_

typedef enum {
    C,  //=0
    E,  //=1
    O,  //=2
    P  //=3
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
    DAMA = 12,
    REI = 13
} Valor;

typedef struct carta{
    Valor valor;
    Naipe naipe;
    struct carta *prox;
} Carta;

typedef Carta Info;

typedef struct nodoLEnc{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct pilha{
   NodoLEnc *topo;
} Pilha;

Pilha* criaBaralho();

void empilhaCarta(Pilha *monte, Info info);

int vaziaPilha(Pilha *pilha);

Info desempilhaCarta(Pilha *monte);

void swap(Carta *a, Carta *b);

void embaralhaCartas(Carta baralho[], int totalCartas);

void criarBaralhoEstatico(Carta baralho[52]);

void imprimeBaralho(Pilha *baralho);

#endif