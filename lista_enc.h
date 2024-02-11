#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_

typedef enum {
    C,  //=0
    E,  //=1
    O,  //=2
    P  //=3
}Naipe;

typedef enum {
    AS = 1,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    VALETE = 11,
    DAMA = 12,
    REI = 13
}Valor;

typedef struct carta{
    Valor valor;
    Naipe naipe;
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
