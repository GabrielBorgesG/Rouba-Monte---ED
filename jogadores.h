#ifndef _JOGADORES_H_
#define _JOGADORES_H_

#include "mao.h"
#include "pilhas.h"
#include "listas.h"

typedef enum {
    ID1 = 1, 
    ID2, 
    ID3, 
    ID4 
} ID;

typedef struct{
    ID id;
    Pilha* monte;
    Mao* mao;
} Jogador;

typedef struct nodoLEnc{
    Jogador* jogador;
    struct nodoLEnc *prox;
} NodoLEnc;

typedef struct{
    NodoLEnc *prim;
} ListaCircEnc;

typedef ListaCircEnc OrdemJogadas;

ListaCircEnc* criaListaCircEnc();

OrdemJogadas* criaOrdemJogadas(Pilha* baralho, int nJogadores);

void escolheCartaMao(Jogador *j, ListaEnc2 *mesa, int posMao);

void roubaMonte(Jogador *j1, Jogador *j2, int posMao);

void imprimeJogadores(OrdemJogadas* ordenacao);

#endif