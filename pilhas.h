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

Pilha* criaPilha();

void empilhaCarta(Pilha *pilha, Carta carta);

Carta desempilhaCarta(Pilha *pilha);

int vaziaPilha(Pilha *pilha);

void imprimePilha(Pilha *pilha);

int vaziaPilha(Pilha *pilha);

#endif