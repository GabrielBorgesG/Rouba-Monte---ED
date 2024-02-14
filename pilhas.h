#ifndef _PILHAS_H_
#define _PILHAS_H_

#include "cartas.h"

typedef struct nodoPEnc{
   Carta carta;
   struct nodoPEnc *prox;
} NodoPEnc;

typedef struct pilha{
   NodoPEnc *topo;
} Pilha;

// Funcao que cria uma pilha
Pilha* criaPilha();

// Funcao para empilhar uma carta no topo da pilha (baralho)
void empilhaCarta(Pilha *pilha, Carta carta);

// Funcao para desempilhar uma carta do topo da pilha (baralho)
Carta desempilhaCarta(Pilha *pilha);

// Imprime os montes
void imprimePilha(Pilha *pilha, int x, int y);

// Checa se a pilha e vazia
int vaziaPilha(Pilha *pilha);

// Destroi a pilha
void destroiPilha(Pilha *pilha);

#endif