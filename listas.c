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

void imprimeListaEnc2(ListaEnc2* lista, int y){
    NodoLEnc2* aux;
    int x = (TAMANHO_TELA_X - 7*(lista->tam))/2; // calcula a posição x inicial
    for(aux = lista->prim; aux != NULL; aux = aux->prox){
      imprimeCartaJogador(aux->carta, x, y);
      x += 7; // move para a próxima posição x
    }
}

//Funcao que verifica se ha duas cartas de valores iguais em uma lista
int valoresIguaisListaEnc2(ListaEnc2* mao) {
    NodoLEnc2* aux1, *aux2;
    aux1 = mao->prim;
    int posMao = 1;

    // Percorre a lista com aux1
    while (aux1 != NULL && aux1->prox != NULL) {
        aux2 = aux1->prox;
        posMao++;

        // Para cada aux1, percorre o restante da lista com aux2
        while (aux2 != NULL) {
            // Se encontrar um valor igual, retorna 1
            if (aux1->carta.valor == aux2->carta.valor) {
                return posMao;
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }

    // Se não encontrar nenhum valor igual, retorna 0
    return 0;
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