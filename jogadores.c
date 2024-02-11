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
        jogador->monte = criaPilha();
        insereJogador(ordenacao, jogador);
   }

   return ordenacao;
}

void pegaMesa(Jogador *j, ListaEnc2 *mesa, int posMao){

     Carta cartaMao = removeCartaListaEnc2(j->mao, posMao);
     NodoLEnc2* atualMesa = mesa->prim;
     int posMesa = 0; // Índice da carta na mesa
     while (atualMesa != NULL) {
          if (cartaMao.valor == atualMesa->carta.valor) {
               // Remover carta da mesa
               Carta cartaMesa = removeCartaListaEnc2(mesa, posMesa);
               // Adicionar ambas as cartas à pilha do jogador
               empilhaCarta(j->monte, cartaMao);
               empilhaCarta(j->monte, cartaMesa);
               break;
          }
          atualMesa = atualMesa->prox;
          posMesa++;
     }

     //Caso cartas iguais não sejam encontradas a carta volta pra mão do jogador
     insereCartaListaEnc2(j->mao, cartaMao);
}

void roubaMonte(Jogador *j1, Jogador *j2){

     //J1 = jogador ladrao
     //J2 = jogador roubado
     if(j1->monte->topo->carta.valor == j2->monte->topo->carta.valor){
          //Salvando os topos das pilhas
          Carta cartaj1 = desempilhaCarta(j1->monte);
          Carta cartaj2 = desempilhaCarta(j2->monte);
          //Estrutura auxiliar
          Carta carta;
          while (!vaziaPilha(j2->monte)){
               //Retirar a carta do monte do adversário
               carta = desempilhaCarta(j2->monte);
               //Adicionar a carta ao próprio monte
               empilhaCarta(j1->monte, carta);
          }

          //Colocando os topos novamente
          empilhaCarta(j1->monte, cartaj1);
          empilhaCarta(j1->monte, cartaj2);

     }
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
