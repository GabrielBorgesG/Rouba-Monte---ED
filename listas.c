#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

//------Lista-Duplamente-Encadeada------//

ListaEnc2* criaListaEnc2(){
    ListaEnc2* lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
    if (lista != NULL) // Idealmente, sempre checar!
        lista->prim = NULL; // Representacao de lista vazia
    lista->tam = 0;

    return lista;
}

// Insere uma carta em uma lista
void insereCartaListaEnc2(ListaEnc2* lista, Carta carta){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo == NULL){ // Idealmente, sempre checar!
    fprintf(stderr, "Error: Failed to allocate memory for a card.\n");
    exit(EXIT_FAILURE);
   }

   novo->carta = carta;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   lista->tam++;
}

// Remove uma carta de uma lista
Carta removeCartaListaEnc2(ListaEnc2* lista, int pos){
   NodoLEnc2 *aux = lista->prim; 
   Carta info;
   for(int i = 1; i < pos; i++)
      aux = aux->prox;

   if (aux != NULL){
      if (aux->ant == NULL){
         lista->prim = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = NULL;   
      }else{
         aux->ant->prox = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = aux->ant;            
      }
      info = aux->carta;
      free(aux);
      lista->tam--;
   }

   return info;
}

Carta buscaCartaListaEnc2(ListaEnc2* lista, int pos){
   NodoLEnc2 *aux = lista->prim;
   for(int i = 1; i < pos; i++){
      aux = aux ->prox;
   }
   return aux->carta;
}

// Imprime as cartas no tabuleiro (mesa e mao)
void imprimeListaEnc2(ListaEnc2* lista, int y){
    NodoLEnc2* aux;
    int x = (TAMANHO_TELA_X - 7*(lista->tam))/2; // calcula a posição x inicial
    for(aux = lista->prim; aux != NULL; aux = aux->prox){
      imprimeCartaJogador(aux->carta, x, y);
      x += 7; // move para a próxima posição x
    }
}

// Funcao que destroi uma lista
void destroiListaEnc2(ListaEnc2 *lista){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}