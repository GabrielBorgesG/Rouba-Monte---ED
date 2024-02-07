#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_

typedef struct carta{
    int num; // 1 a 13
    int naipe; // 1 a 4
}Carta;

typedef Carta Info;

typedef struct nodoLEnc{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct{
   struct nodoLEnc *prim;
} ListaEnc;

#endif
