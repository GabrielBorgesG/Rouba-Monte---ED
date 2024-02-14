#include "baralho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Pilha* criaBaralho() {
    Pilha *baralho;
    baralho = criaPilha();
    Carta carta;

    for (int naipe = C; naipe <= P; naipe++) {
        for (int valor = AS; valor <= REI; valor++) {
            carta.naipe = naipe;
            carta.valor = valor;
            empilhaCarta(baralho, carta);
        }
    }

    return baralho;
}

// Embaralha o baralho de cartas na pilha fornecida
void embaralhaBaralho(Pilha *baralho){
    int i, j;
    Carta temp;
    NodoPEnc* aux1;
    NodoPEnc* aux2;

    srand(time(NULL));

    for (i = TAMANHO_BARALHO - 1; i>=0; i--){
        aux1 = baralho->topo;
        aux2 = baralho->topo;
        j = rand() % (i + 1);       // Algoritmo de Fisher-Yates
        if (j != i){
            for(int l=0; l<i; l++)
                aux1 = aux1->prox;
            for(int k=0; k<j; k++)
                aux2 = aux2->prox;
            temp = aux1->carta;
            aux1->carta = aux2->carta;
            aux2->carta = temp;
        }
    }
}