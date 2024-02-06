#ifndef _LISTA_CIRC_H_
#define _LISTA_CIRC_H_

typedef struct{
    int chave;
    PilhaEnc monte;
    ListaEnc2 mao;
}Jogador;

typedef Jogador Info;

typedef struct nodoLEnc{
    Info info;
    struct nodoLEnc *prox;
}NodoLEnc;

typedef struct{
    struct nodoLEnc *prim;
}ListaCircEnc;

// Funcao que cria uma lista
ListaCircEnc* criaListaCircEnc();

// Funcao que destroi uma lista
void destroiListaCircEnc(ListaCircEnc *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaCircEnc(ListaCircEnc *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaCircEnc(ListaCircEnc *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc* buscaInfoListaCircEnc(ListaCircEnc* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaCircEnc(ListaCircEnc* lista, int chave);

#endif
