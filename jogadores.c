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

int pegaMesa(Jogador* j, ListaEnc2 *mesa, Carta cartaMao){
     NodoLEnc2* atualMesa = mesa->prim;
     int posMesa = 1; // Índice da carta na mesa
     while (atualMesa != NULL) {
          if (cartaMao.valor == atualMesa->carta.valor) {
               // Remover carta da mesa
               Carta cartaMesa = removeCartaListaEnc2(mesa, posMesa);
               // Adicionar ambas as cartas à pilha do jogador
               empilhaCarta(j->monte, cartaMesa);
               empilhaCarta(j->monte, cartaMao);
               return 1;
          }
          atualMesa = atualMesa->prox;
          posMesa++;
     }
     return 0;
}

void escolheCartaMao(Jogador* j, ListaEnc2 *mesa, int posMao){
     //Recupera carta da mao pela posicao escolhida
     Carta cartaMao = removeCartaListaEnc2(j->mao, posMao);

     //Tenta pegar a mesa com a carta escolhida
     int retorno = pegaMesa(j, mesa, cartaMao);

     //Caso nao consiga, a carta vai para a mesa
     if(!retorno)
          insereCartaListaEnc2(mesa, cartaMao);
}

void roubaMonte(Jogador *j1, Jogador *j2, int posMao){

     //J1 = jogador ladrao
     Carta cartaj1 = removeCartaListaEnc2(j1->mao, posMao);
     //J2 = jogador roubado
     if(cartaj1.valor == j2->monte->topo->carta.valor){
          //Salvando o topo da pilha
          Carta cartaj2 = desempilhaCarta(j2->monte);
          //Estrutura auxiliar
          Carta carta;
          while (!vaziaPilha(j2->monte)){
               //Retirar a carta do monte do adversário
               carta = desempilhaCarta(j2->monte);
               //Adicionar a carta ao próprio monte
               empilhaCarta(j1->monte, carta);
          }

          //Colocando os topos
          empilhaCarta(j1->monte, cartaj2);
          empilhaCarta(j1->monte, cartaj1);

     }
     else{
          //Caso das cartas não serem iguais
          insereCartaListaEnc2(j1->mao, cartaj1);
     }
}

void imprimeJogadores(OrdemJogadas* ordenacao){
     NodoLEnc* aux = ordenacao->prim;
     printf("-------------------------------\n");
     if(ordenacao->prim != NULL){
          do{
               printf("ID: %d\n", aux->jogador->id);
               printf("Mao: ");
               imprimeListaEnc2(aux->jogador->mao);
               printf("Monte: ");
               imprimePilha(aux->jogador->monte);
               printf("\n");
               aux = aux->prox;
          }while (aux != ordenacao->prim);
     }
     printf("-------------------------------\n");
}
