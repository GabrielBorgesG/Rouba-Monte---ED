#include "pilhas.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

Pilha* criaPilha(){
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));

    if (pilha == NULL){ // Idealmente, sempre checar!
        fprintf(stderr, "Error: Failed to allocate memory for a stack.\n");
        exit(EXIT_FAILURE);
    }

    pilha->topo = NULL;
    return pilha;
}

// Funcao para empilhar uma carta no topo da pilha (baralho)
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

// Funcao para desempilhar uma carta do topo da pilha (baralho)
Carta desempilhaCarta(Pilha* pilha){
   NodoPEnc *aux = pilha->topo; 
   Carta carta = aux->carta;
   pilha->topo = aux->prox;
   free(aux);
   return carta;
}

void imprimePilha(Pilha *pilha, int x, int y) {
    NodoPEnc *aux = pilha->topo; // Ponteiro auxiliar para percorrer a pilha
    if(aux == NULL){
        gotoxy(x, y); printf(" -----\n");
        gotoxy(x, y+1); printf("|\\   /| \n", 'A');
        gotoxy(x, y+2); printf("|  -  | \n");
        gotoxy(x, y+3); printf("|/   \\| \n");
        gotoxy(x, y+4); printf(" -----\n");

    }else imprimeCartaJogador(aux->carta, x, y);
}

int vaziaPilha(Pilha *pilha){
    return (pilha->topo == NULL);
}

void destroiPilha(Pilha *pilha){
   NodoPEnc *aux = pilha->topo;
   while(aux != NULL){
       NodoPEnc *tmp = aux->prox;
       free(aux);
       aux = tmp;
   }
   free(pilha);
}