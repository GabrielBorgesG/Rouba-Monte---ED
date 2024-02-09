#include "cartas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para empilhar uma carta no topo da pilha (baralho)
void empilhaCarta(Pilha *monte, Info info) {
    NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
   if (novo != NULL){ // Idealmente, sempre checar!
      novo->info = info;
      novo->prox = monte->topo;
      monte->topo = novo;
   }
}

// Função para desempilhar uma carta do topo da pilha (baralho)
Info desempilhaCarta(Pilha* pilha){
   NodoLEnc *aux = pilha->topo; 
   /* Aqui assumimos que desempilha eh 
   chamada apenas se a pilha nao eh vazia */
   Info info = aux->info;
   pilha->topo = aux->prox;
   free(aux);
   return info;
}

// Funcao que determina se uma pilha eh vazia
int vaziaPilha(Pilha *pilha){
   return (pilha->topo == NULL);
}

//Função auxiliar para trocar as variáveis
void swap(Carta *a, Carta *b) {
    Carta temp = *a;
    *a = *b;
    *b = temp;
}

//Função de embaralhar a lista estática
void embaralhaCartas(Carta baralho[], int totalCartas) {

    //inicializar numero aleatorio
    srand(time(NULL));
    
    //Começar pelo último elemento e trocar um por um
    for (int i = totalCartas - 1; i > 0; i--) {
        //gerar um índice randomico entre 0 e i
        int j = rand() % (i + 1);
        
        //trocar os números escolhidos aleatoriamente
        swap(&baralho[i], &baralho[j]);
    }
}

// Função auxiliar para criar um baralho ordenado
void criarBaralhoEstatico(Carta baralho[52]) {
    int i = 0;
    for (Naipe naipe = C; naipe <= P; naipe++) {
        for (Valor valor = AS; valor <= REI; valor++) {
            baralho[i].valor = valor;
            baralho[i].naipe = naipe;
            i++;
        }
    }
}

//Funcao que cria um baralho ja embaralhado
Pilha* criaBaralho() {
    Pilha *baralho = (Pilha *) malloc(sizeof(Pilha));

    if (baralho != NULL){    // Idealmente, sempre checar!
        baralho->topo = NULL;
    }


    int numCartas = 52;
    Carta baralhoEstatico[numCartas];
    //Criando a lista estática
    criarBaralhoEstatico(baralhoEstatico);

    //Embaralhando a lista estática
    embaralhaCartas(baralhoEstatico, numCartas);

    //Empilhando as cartas no monte
    for (int i = numCartas; i > 0; i--){
        empilhaCarta(baralho, baralhoEstatico[i]);
    }

    return baralho;
}

void imprimeBaralho(Pilha *baralho) {

    Info infoAux;
    while(!vaziaPilha(baralho)){
        infoAux = desempilhaCarta(baralho);
        printf("%d, %d \n", infoAux.valor, infoAux.naipe);
    }
   
}