#ifndef _LISTAS_H_
#define _LISTAS_H_

#include "cartas.h"

//------Lista-Duplamente-Encadeada------//

typedef struct nodoLEnc2{
   Carta carta;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

typedef struct listaEnc2{
   NodoLEnc2 *prim;
   int tam;
} ListaEnc2;

ListaEnc2* criaListaEnc2();

void insereCartaListaEnc2(ListaEnc2* lista, Carta carta);

Carta removeCartaListaEnc2(ListaEnc2* lista, int pos);

Carta buscaCartaListaEnc2(ListaEnc2* lista, int pos);

void imprimeListaEnc2(ListaEnc2* lista, int y);

void imprimeIndicesCarta(ListaEnc2* lista, int y, int cartaSelecionada);

int valoresIguaisListaEnc2(ListaEnc2* lista);

// Funcao que destroi uma lista
void destroiListaEnc2(ListaEnc2 *lista);

#endif