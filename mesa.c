#include "mesa.h"
#include <stdio.h>
#include <stdlib.h>

Mesa* criaMesa(Pilha* baralho){
    Mesa* mesa;

    mesa = criaListaEnc2();

    Carta carta;

    for(int i = 0; i < TAMANHO_MESA; i++){
        carta = desempilhaCarta(baralho);
        insereCartaListaEnc2(mesa, carta);
    }

    return mesa;
}