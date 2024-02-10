#ifndef _LISTA_ENC_DUPLA_H_
#define _LISTA_ENC_DUPLA_H_

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

typedef struct{
    Valor valor;
    Naipe naipe;
}Info;

typedef struct nodoLEnc2{
   Info info;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

typedef struct ListaEnc2{
   NodoLEnc2 *prim;
} ListaEnc2;

// Funcao que cria uma lista
ListaEnc2* criaListaEnc2();

// Funcao que destroi uma lista
void destroiListaEnc2(ListaEnc2 *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaEnc2(ListaEnc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaEnc2(ListaEnc2 *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaEnc2(ListaEnc2* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaEnc2(ListaEnc2* lista, int chave);

// Função que insere um nodo novo numa posição específica 
int inserePosListaEnc2(ListaEnc2 *lista, Info info, int pos);

// Função que concatena duas listas em uma terceira lista, que é retornada
ListaEnc2* concatenaListaEnc2(ListaEnc2 *lista1, ListaEnc2 *lista2);

// Função que imprime uma lista duplamente encadeada ao contrário
void imprimeInversoListaEnc2(ListaEnc2 *lista);

#endif
