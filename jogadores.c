#include "jogadores.h"
#include <stdio.h>
#include <stdlib.h>

void insereJogador(OrdemJogadas* ordenacao, Jogador* jogador){
     NodoLEnc* aux;
     NodoLEnc* novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));

     if (novo == NULL){ // Idealmente, sempre checar!
        fprintf(stderr, "Error: Failed to allocate memory for a player.\n");
        exit(EXIT_FAILURE);
    }

     novo->jogador = jogador;
     
     if(ordenacao->prim == NULL){
          ordenacao->prim = novo;
          novo->prox = ordenacao->prim;
     }else{
          aux = ordenacao->prim;
          while(aux->prox != ordenacao->prim)
               aux = aux->prox;
          aux->prox = novo;
          novo->prox = ordenacao->prim;
     }
}

ListaCircEnc* criaListaCircEnc(){
    ListaCircEnc* lista = (ListaCircEnc*)malloc(sizeof(ListaCircEnc));
    if (lista != NULL) // Idealmente, sempre checar!
        lista->prim = NULL; // Representacao de lista vazia

    return lista;
}

OrdemJogadas* criaOrdemJogadas(Pilha* baralho, int nJogadores){
   OrdemJogadas* ordenacao;
   ordenacao = criaListaCircEnc();

   for(int id = ID1; id <= nJogadores; id++){
        Jogador* jogador = (Jogador*)malloc(sizeof(Jogador));
        jogador->id = id;
        jogador->mao = criaMao(baralho);
        //jogador.monte = criaMonte(baralho);
        insereJogador(ordenacao, jogador);
   }

   return ordenacao;
}

void imprimeJogadores(OrdemJogadas* ordenacao){
     NodoLEnc* aux = ordenacao->prim;
     printf("-------------------------------\n");
     if(ordenacao->prim != NULL)
          do{
               printf("ID: %d\n", aux->jogador->id);
               aux = aux->prox;
               imprimeListaEnc2(aux->jogador->mao);
               printf("\n");
          }while (aux != ordenacao->prim);
     printf("-------------------------------\n");
}
