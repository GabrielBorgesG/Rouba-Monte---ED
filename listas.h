#ifndef _LISTAS_H_
#define _LISTAS_H_

#include "cartas.h"

//Lista Duplamente Encadeada

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

// Insere uma carta em uma lista
void insereCartaListaEnc2(ListaEnc2* lista, Carta carta);

// Remove uma carta de uma lista
Carta removeCartaListaEnc2(ListaEnc2* lista, int pos);

//
Carta buscaCartaListaEnc2(ListaEnc2* lista, int pos);

// Imprime as cartas no tabuleiro (mesa e mao)
void imprimeListaEnc2(ListaEnc2* lista, int y);

// Funcao que destroi uma lista
void destroiListaEnc2(ListaEnc2 *lista);

#endif