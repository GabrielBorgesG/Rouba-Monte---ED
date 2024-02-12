#include "lista_enc_dupla.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc2* criaListaEnc2(){
   ListaEnc2 *lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
   if (lista != NULL) // Idealmente, sempre checar!
      lista->prim = NULL; // Representacao de lista vazia
   return lista;
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

// Funcao que imprime todos os nodos de uma lista
void imprimeListaEnc2(ListaEnc2 *lista){
   NodoLEnc2 *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%d | %d\n", aux->info.valor,
                               aux->info.naipe);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaEnc2(ListaEnc2* lista, int chave){
   NodoLEnc2 *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->info.chave == chave)
         return aux;
   return NULL; 
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaEnc2(ListaEnc2 *lista, Info info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo == NULL) // Idealmente, sempre checar!
      return 0; 
   novo->info = info;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   return 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaEnc2(ListaEnc2* lista, int valor){
   NodoLEnc2 *aux = lista->prim; 
   while(aux != NULL && aux->info.valor != chave){
      aux = aux->prox;
   }
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
      free(aux);
      return 1;
   }
   return 0; // Nao encontrou
}

// Função que insere um nodo novo numa posição específica
int inserePosListaEnc2(ListaEnc2 *lista, Info info, int pos){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   if (novo == NULL){
      return 0;
   }
   novo->info = info;
   NodoLEnc2 *ant, *aux;

   int cont = 0, tam = 0;

   if(pos < 0 || (lista->prim == NULL && pos != 0)){ // Posições inválidas
      return 0;
   }
   
   //Confere tamanho
   for(aux = lista->prim; aux != NULL; aux = aux->prox){
      tam++;
   }
   if(pos > tam){ // Posição ultrapassa o tamanho da lista - Posição inválida
      return 0;
   }

   if(pos == 0){ // Deve ser colocado como primeiro elemento
      insereInicioListaEnc2(lista, info);
      return 1;
   }

   // Chega na POS
   aux = lista->prim;
   while(cont < pos){
      ant = aux;  
      aux = aux->prox;
      cont++;
   }

   novo->prox = ant->prox;
   if(aux == NULL){ // Deve ser colocado na última POS possível
      novo->ant = ant;
   }
   else{ // Deve ser colocado numa posição interna da lista
      novo->ant = aux->ant;
      aux->ant = novo;
   }
   ant->prox = novo;

   return 1;  
}

// Função que concatena duas listas em uma terceira lista, que é retornada
ListaEnc2* concatenaListaEnc2(ListaEnc2 *lista1, ListaEnc2 *lista2){
   ListaEnc2 *lista_conc;
   lista_conc = criaListaEnc2();

   NodoLEnc2 *aux;

   // Primeiro fará a cópia da lista 2 para que fique no final da lista_conc
   aux = lista2->prim;
   if(aux != NULL){
      while(aux->prox != NULL){ // Chega ao final da lista
         aux = aux->prox;
      }
   }
   // A cópia é feita do fim para o início
   while(aux != NULL){
      insereInicioListaEnc2(lista_conc, aux->info);
      aux = aux->ant;
   }

   // Depois fará a cópia da lista 1 para que fique no início da lista_conc
   aux = lista1->prim;
   if(aux != NULL){
      while(aux->prox != NULL){ // Chega ao final da lista
         aux = aux->prox;
      }
   }
   // A cópia é feita do fim para o início
   while(aux != NULL){
      insereInicioListaEnc2(lista_conc, aux->info);
      aux = aux->ant;
   }
   return lista_conc;
}

// Função que imprime uma lista duplamente encadeada ao contrário
void imprimeInversoListaEnc2(ListaEnc2 *lista){
   NodoLEnc2 *aux;
   for(aux = lista->prim; aux->prox != NULL; aux = aux->prox);
   for(; aux != NULL; aux = aux->ant){
      printf("%d | %s (%s)\n", aux->info.chave, aux->info.nome, aux->info.email);
   }
}
