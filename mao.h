#ifndef _MAO_H_
#define _MAO_H_

#include "pilhas.h"
#include "listas.h"

#define TAMANHO_MAO 4

typedef ListaEnc2 Mao;

Mao* criaMao(Pilha *baralho);

// Funcao que imprime os indices acima das cartas da mao
void imprimeIndicesCarta(Mao* mao, int y, int CartaSelecionada);

#endif