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
} ID; // ID do jogador

typedef struct{
    ID id;
    Pilha* monte;
    Mao* mao;
} Jogador; // Cada jogador possui um ID, um monte e uma mao

typedef struct nodoLEnc{
    Jogador* jogador;
    struct nodoLEnc *prox;
} NodoLEnc;

typedef struct{
    NodoLEnc *prim;
} ListaCircEnc;

typedef ListaCircEnc OrdemJogadas;

ListaCircEnc* criaListaCircEnc();

// Cria os jogadores dentro da lista circular
OrdemJogadas* criaOrdemJogadas(Pilha* baralho, int nJogadores);

// Verifica se ha uma carta de mesmo valor na mesa e na mao
int buscaMesa(ListaEnc2* mesa, Carta cartaMao);

// Pega uma carta da mesa
void pegaMesa(Jogador* j, ListaEnc2 *mesa, Carta cartaMao, int posMesa);

// Verifica se ha uma carta de mesmo valor na mao e no monte de algum jogador, esse eh retornado
Jogador* buscaMontes(NodoLEnc* rodada, Carta cartaMao);

// Rouba o monte de um jogador
void roubaMonte(Jogador *j1, Jogador *j2, Carta cartaMao);

void destroiOrdemJogadas(OrdemJogadas* ordenacao);

#endif