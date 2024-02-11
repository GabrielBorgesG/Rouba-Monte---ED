#include "pilhas.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* criaPilha(){
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));

    if (pilha == NULL){ // Idealmente, sempre checar!
        fprintf(stderr, "Error: Failed to allocate memory for a stack.\n");
        exit(EXIT_FAILURE);
    }

    pilha->topo = NULL;
    return pilha;
}

// Função para empilhar uma carta no topo da pilha (baralho)
void empilhaCarta(Pilha *pilha, Carta carta) {
    NodoPEnc *novo = (NodoPEnc*)malloc(sizeof(NodoPEnc));
    if (novo == NULL){ // Idealmente, sempre checar!
        fprintf(stderr, "Error: Failed to allocate memory for a card.\n");
        exit(EXIT_FAILURE);
    }
    novo->carta = carta;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

// Função para desempilhar uma carta do topo da pilha (baralho)
Carta desempilhaCarta(Pilha* pilha){
   NodoPEnc *aux = pilha->topo; 
   Carta carta = aux->carta;
   pilha->topo = aux->prox;
   free(aux);
   return carta;
}

void imprimePilha(Pilha *pilha) {
    NodoPEnc *aux = pilha->topo; // Ponteiro auxiliar para percorrer a pilha
    while (aux != NULL) {
        printf("%d%c ", aux->carta.valor, NAIPES[aux->carta.naipe]);
        aux = aux->prox; // Avança para o próximo nó
    }
}