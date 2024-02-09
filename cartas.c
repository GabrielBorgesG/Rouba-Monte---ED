#include "cartas.h"
#include <stdio.h>
#include <stdlib.h>

void empilhaCarta(Pilha *monte, Carta *carta) {
    carta->prox = monte->topo;
    monte->topo = carta;
}

/* void embaralhaCartas(Pilha *baralho) {
    int totalCartas = 52;

    // Algoritmo de Fisher-Yates
    for (int i = totalCartas - 1; i > 0; i--) {
        int posicaoAleatoria = rand() % (i + 1);
        Carta cartaAux = baralho->topo[i];
        baralho->topo[i] = baralho->topo[posicaoAleatoria];
        baralho->topo[posicaoAleatoria] = cartaAux;
    }
}*/

Pilha* criaBaralho() {
    Pilha *baralho = (Pilha *) malloc(sizeof(Pilha));

    if (baralho != NULL) // Idealmente, sempre checar!
      baralho->topo = NULL;

    for (int naipe = C; naipe <= P; naipe++) {
        for (int valor = AS; valor <= REI; valor++) {
            Carta* carta = (Carta *) malloc(sizeof(Carta));
            carta->naipe = naipe;
            carta->valor = valor;
            empilhaCarta(baralho, carta);
        }
    }

    //embaralhaCartas(baralho);

    return baralho;
}

void imprimeBaralho(Pilha *baralho) {
   Carta *aux = baralho->topo;
   while(aux != NULL){
       printf("%d%c ", aux->valor, "CEOP"[aux->naipe]);
       aux = aux->prox;
   }
}

int main(){
    Pilha* baralho;
    baralho = criaBaralho();

   imprimeBaralho(baralho);

}