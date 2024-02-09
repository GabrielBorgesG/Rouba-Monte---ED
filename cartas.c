#include "cartas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void empilhaCarta(Pilha *monte, Carta *carta) {
    carta->prox = monte->topo;
    monte->topo = carta;
}

void embaralhaCartas(Pilha *baralho) {
    Pilha *temp = NULL; // pilha temporária para ajudar no embaralhamento
    Carta *cartaAtual = NULL; // ponteiro para a carta atual
    Carta *cartaAleatoria = NULL; // ponteiro para a carta aleatória
    int tamanho = 0; // variável para armazenar o tamanho do baralho
    int posicaoAleatoria = 0; // variável para armazenar a posição aleatória
    
    // Obtém o tamanho do baralho
    for (temp = baralho; temp != NULL; temp = temp->topo) {
        tamanho++;
    }
    
    // Itera sobre o baralho, sorteando uma posição aleatória para cada carta
    for (temp = baralho, tamanho--; tamanho > 0; tamanho--) {
        srand(time(NULL) + temp->topo->valor + tamanho); // atualiza a semente de rand()
        posicaoAleatoria = rand() % (tamanho + 1); // sorteia uma posição aleatória entre 0 e tamanho
        
        // Encontra a carta atual e a carta aleatória
        for (cartaAtual = temp, tamanho = 0; tamanho < posicaoAleatoria; tamanho++) {
            cartaAleatoria = cartaAtual;
            cartaAtual = cartaAtual->topo;
        }
        
        // Troca as cartas atual e aleatória
        if (cartaAtual != cartaAleatoria) {
            Carta *proximoDaAleatoria = cartaAleatoria->prox;
            Carta *proximoDaAtual = cartaAtual->prox;
            
            // Conecta a carta aleatória com a próxima carta da carta atual
            cartaAleatoria->prox = proximoDaAtual;
            
            // Conecta a carta atual com a próxima carta da carta aleatória
            cartaAtual->prox = proximoDaAleatoria;
            
            // Desconecta a carta atual do baralho
            if (temp->topo == cartaAtual) {
                temp->topo = cartaAtual;
            }
            
            // Desconecta a carta aleatória do baralho
            if (temp->topo == cartaAleatoria) {
                temp->topo = cartaAleatoria;
            }
        }
    }
}

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

    embaralhaCartas(baralho);

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