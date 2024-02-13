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
    int pontuacao;
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

int buscaMesa(ListaEnc2* mesa, Carta cartaMao);

void pegaMesa(Jogador* j, ListaEnc2 *mesa, Carta cartaMao, int posMesa);

Jogador* buscaMontes(NodoLEnc* rodada, Carta cartaMao);

void escolheCartaMao(Jogador *j, ListaEnc2 *mesa, Carta cartaMao);

void roubaMonte(Jogador *j1, Jogador *j2, Carta cartaMao);

void imprimeJogadores(OrdemJogadas* ordenacao);

#endif