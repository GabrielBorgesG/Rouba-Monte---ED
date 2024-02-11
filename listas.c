#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

//------Lista-Duplamente-Encadeada------//

ListaEnc2* criaListaEnc2(){
    ListaEnc2* lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
    if (lista != NULL) // Idealmente, sempre checar!
        lista->prim = NULL; // Representacao de lista vazia

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
}

Carta removeCartaListaEnc2(ListaEnc2* lista, int pos){
   NodoLEnc2 *aux = lista->prim; 
   Carta info;
   for(int i = 0; i < pos; i++)
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
   }

   return info;
}

void imprimeListaEnc2(ListaEnc2* lista){
    NodoLEnc2* aux;
    for(aux = lista->prim; aux != NULL; aux = aux->prox)
        printf("%d%c ", aux->carta.valor, NAIPES[aux->carta.naipe]);
}