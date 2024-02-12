#include <stdio.h>
#include <stdlib.h>

#include "cartas.h"
#include "pilhas.h"
#include "listas.h"

#include "baralho.h"
#include "mao.h"
#include "mesa.h"
#include "jogadores.h"

int main(){
    Pilha* baralho;
    OrdemJogadas* ordenacao;
    Mesa* mesa;

    baralho = criaBaralho();

    embaralhaBaralho(baralho);

    printf("Baralho: ");
    imprimePilha(baralho);
    printf("\n");

    int nJogadores = 2;
    int posMao;
    NodoLEnc* rodada;

    ordenacao = criaOrdemJogadas(baralho, nJogadores);

    imprimeJogadores(ordenacao);

    printf("\n");

    mesa = criaMesa(baralho);


    for(rodada = ordenacao->prim; rodada != NULL; rodada = rodada->prox){ // Loop infinito
        
        printf("-------JOGADOR %d------", rodada->jogador->id);

        printf("\nMesa: ");

        imprimeListaEnc2(mesa);

        printf("\n");

        do{
            printf("Escolha carta na mao: ");
            scanf("%d", &posMao);
        }while(posMao < 1 || posMao > TAMANHO_MAO);

        escolheCartaMao(rodada->jogador, mesa, posMao);

        imprimeJogadores(ordenacao);

        if(mesa->prim == NULL){
            mesa = criaMesa(baralho);
        }

        if(rodada->jogador->mao->prim == NULL)
            rodada->jogador->mao = criaMao(baralho);    

        if(vaziaPilha(baralho)){
            printf("Fim do Jogo");
            break;
        }     

        printf("\n");
    
    }

}