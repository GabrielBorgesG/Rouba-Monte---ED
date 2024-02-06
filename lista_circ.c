#include "lista_circ.h"
#include <stdio.h>
#include <stdlib.h>

void imprimeListaCircEnc(ListaCircEnc *lista){
    NodoLEnc *aux = lista->prim;
    printf("-----------------------------------------\n");
    if (lista->prim != NULL)
    do{
    printf("%d | %s (%s)\n", aux->info.chave,
    }while(aux != lista->prim);
    printf("-----------------------------------------\n");
}

int insereInicioListaCircEnc(ListaCircEnc *lista, Info info){
     NodoLEnc *aux;
     NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
     if (novo == NULL) // Idealmente, sempre checar!
        return 0;
     novo->info = info;
     if (lista->prim == NULL){
         lista->prim = novo;
         novo->prox = lista->prim;
     }else{
        aux = lista->prim;
        while(aux->prox != lista->prim)
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = lista->prim;
        lista->prim = novo;
    }
    return 1;
}
