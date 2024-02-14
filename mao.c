#include "mao.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

Mao* criaMao(Pilha *baralho){
    Mao* mao;
    mao = criaListaEnc2();

    Carta carta;

    for(int i = 0; i < TAMANHO_MAO; i++){
        carta = desempilhaCarta(baralho);
        insereCartaListaEnc2(mao, carta);
    }

    return mao;
}

// Funcao que imprime os indices acima das cartas da mao
void imprimeIndicesCarta(Mao* mao, int y, int CartaSelecionada){
    NodoLEnc2* aux;
    int i = 1;
    int x = (TAMANHO_TELA_X - 7*(mao->tam))/2; // calcula a posicao x inicial
    for(aux = mao->prim; aux != NULL; aux = aux->prox){
      gotoxy(x, y);
      if(i == CartaSelecionada){
         textcolor(LIGHTBLUE);
         printf("  [%d]  ", i);
         textcolor(WHITE); // Reseta a cor do texto
      }else{
         printf("  [%d]  ", i);
      }
      i++;
      x += 7;
    }
}
