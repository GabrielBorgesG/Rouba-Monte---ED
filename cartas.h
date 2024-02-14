#ifndef _CARTAS_H_
#define _CARTAS_H_

#define TAMANHO_BARALHO 52
#define NAIPES "CEOP"

//CONSTANTES TELA DO CONSOLE//
#define TAMANHO_TELA_X 120
#define TAMANHO_TELA_Y 30
/////////////////////////////

typedef enum {
    C,  // Copas
    E,  // Espadas
    O,  // Ouro
    P  //  Paus
} Naipe;

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
} Valor;

typedef struct carta{
    Naipe naipe;
    Valor valor;
} Carta;

// Imprime na tela uma carta
void imprimeCartaJogador(Carta carta, int x, int y);

#endif