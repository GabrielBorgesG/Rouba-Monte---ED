#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_

#define TAM_MAX_NOME 7
// Como os naipes são copas, paus, espadas e ouros, então a maior palavra é ESPADAS (7)

typedef struct{
   int numero;
   char naipe[TAM_MAX_NOME];
} Carta;

typedef Carta Info;

typedef struct nodoLEnc{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct{
   struct nodoLEnc *prim;
} ListaEnc;

#endif
