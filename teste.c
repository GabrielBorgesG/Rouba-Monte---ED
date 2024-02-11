#include "cartas.h"
#include "pilhas.h"
#include "listas.h"

#include "baralho.h"
#include "mao.h"
#include "mesa.h"
#include "jogadores.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    Pilha* baralho;
    OrdemJogadas* ordenacao;
    Mesa* mesa;

    baralho = criaBaralho();

    embaralhaBaralho(baralho);

    printf("Baralho: ");
    imprimePilha(baralho);
    printf("\n");

    int nJogadores = 4;

    ordenacao = criaOrdemJogadas(baralho, nJogadores);

    imprimeJogadores(ordenacao);

    printf("\n");

    mesa = criaMesa(baralho);

    imprimeListaEnc2(mesa);

}