#include "pilha_enc.h"
#include "fila_enc.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma pilha
PilhaEnc* criaPilhaEnc(){
   PilhaEnc *pilha = (PilhaEnc*)malloc(sizeof(PilhaEnc));
   if (pilha != NULL) // Idealmente, sempre checar!
      pilha->topo = NULL;
   return pilha;
}

// Funcao que destroi uma pilha
void destroiPilhaEnc(PilhaEnc *pilha){
   NodoPEnc *aux = pilha->topo;
   while(aux != NULL){
       NodoPEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(pilha);
}

// Funcao que insere um elemento na pilha
void empilhaPilhaEnc(PilhaEnc *pilha, Info info){
   NodoPEnc *novo = (NodoPEnc*)malloc(sizeof(NodoPEnc));
   if (novo != NULL){ // Idealmente, sempre checar!
      novo->info = info;
      novo->prox = pilha->topo;
      pilha->topo = novo;
   }
}

// Funcao que remove um elemento da pilha
Info desempilhaPilhaEnc(PilhaEnc* pilha){
   NodoPEnc *aux = pilha->topo; 
   /* Aqui assumimos que desempilha eh 
   chamada apenas se a pilha nao eh vazia */
   Info info = aux->info;
   pilha->topo = aux->prox;
   free(aux);
   return info;
}

// Funcao que determina se uma pilha eh vazia
int vaziaPilhaEnc(PilhaEnc *pilha){
   return (pilha->topo == NULL);
}

// Função que inverte uma pilha
void invertePilhaEnc(PilhaEnc *pilha){
   if(!vaziaPilhaEnc(pilha)){
      PilhaEnc *pilha_aux, *pilha_aux2;
      pilha_aux = criaPilhaEnc();
      pilha_aux2 = criaPilhaEnc();

      while(!vaziaPilhaEnc(pilha)){
         empilhaPilhaEnc(pilha_aux, desempilhaPilhaEnc(pilha));
      }

      while(!vaziaPilhaEnc(pilha_aux)){
         empilhaPilhaEnc(pilha_aux2, desempilhaPilhaEnc(pilha_aux));
      }

      while(!vaziaPilhaEnc(pilha_aux2)){
         empilhaPilhaEnc(pilha, desempilhaPilhaEnc(pilha_aux2));
      }
      
      destroiPilhaEnc(pilha_aux);
      destroiPilhaEnc(pilha_aux2);
   }
}

// Função que inverte uma pilha usando FilaEnc
void invertePilhaEnc2(PilhaEnc *pilha){
   FilaEnc *fila_aux;
   fila_aux = criaFilaEnc();
   NodoPEnc *nodo_P_aux = pilha->topo;

   while(!vaziaPilhaEnc(pilha)){
      enfileiraFilaEnc(fila_aux, desempilhaPilhaEnc(pilha)); // Desempilha a Pilha, enquanto enfileira as info
   }

   while(!vaziaFilaEnc(fila_aux)){
      empilhaPilhaEnc(pilha, desenfileiraFilaEnc(fila_aux)); // Desenfileira a fila auxiliar, enquanto empilha as info
   }
}