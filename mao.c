#include "mao.h"
#include <stdio.h>
#include <stdlib.h>

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


