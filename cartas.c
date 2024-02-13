#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

#include "cartas.h"

void imprimeCartaJogador(Carta carta, int x, int y){
    gotoxy(x, y); printf(" -----\n");
    if(carta.valor == 1){
        gotoxy(x, y+1); printf("|%c    | \n", 'A');
    }else if(carta.valor == 10){
        gotoxy(x, y+1); printf("|%d   | \n", carta.valor);
    }else if(carta.valor > 10){
        gotoxy(x, y+1); printf("|%c    | \n", "JQK"[carta.valor - 11]);
    }else{ 
        gotoxy(x, y+1); printf("|%d    | \n", carta.valor);
    }
    gotoxy(x, y+2); printf("|  /  | \n");
    gotoxy(x, y+3); printf("|    %c| \n", NAIPES[carta.naipe]);
    gotoxy(x, y+4); printf(" -----");
}