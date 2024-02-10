/* JOGO ROUBA-MONTE

Requisitos Basicos:
    O monte de cartas (baralho) deve ser representado por uma pilha.
    A ordenacao das jogadas deve ser representada por uma lista circular.
    Cada monte deve ser representado por uma pilha.
    As cartas de cada jogador devem ser representada por uma lista (simples ou dupla).
*/

//BIBLIOTECAS

#include "lista_enc_dupla.h"
#include "pilha_enc.h"
#include "lista_circ.h"
#include "lista_enc.h"
#include "cartas.h"

#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//DEFINICOES
#define FPS 8
#define LARGURA 880
#define ALTURA (520+(FONTE*6))
#define ARESTA_BLOCO 20
#define NUM_BLOC_LARGURA_MAPA 44
#define NUM_BLOC_ALTURA_MAPA 26
#define FONTE 20 //Fonte da letra
#define VOLUME 0.2 //Vai de 0.0 a 1.0
#define NUMEROS_DE_CARTAS 13
#define NUMEROS_DE_NAIPES 4
#define ESPADAS 1
#define PAUS 2
#define COPAS 3
#define OUROS 4
#define NUM_CARTAS_POR_JOGADOR 4

// ESTRUTURAS

// FUNCOES

void SetupWindow(){
    InitWindow(LARGURA, ALTURA, "ROUBA MONTE");
    SetTargetFPS(FPS);
    HideCursor();
    InitAudioDevice();
    //ToggleFullscreen();
}

//Função que conta o número de cartas do jogador
int quantasCartas(ListaCircEnc* ordem, int chave_jogador){
    //IMPLEMENTAR AINDA
}

// Esta função vai avaliar as cartas do jogador específico e comparar todas as suas cartas com as cartas da mesa
// e as cartas do topo das pilhas dos outros jogadores. Se houver correspondência de NÚMERO, as cartas saem da MESA
// e da MAO do jogador e vão para o monte do jogador
void rodada(ListaCircEnc* ordem, ListaEnc2 *mesa, int num_cartas_na_mesa, int chave_jogador){
    int quantas_cartas = quantasCartas(ordem, chave_jogador);
    for(i = 0, i < num_cartas_na_mesa; i++){
        for(j = 0, j < num_cartas_do_jogador; j++){
            if(){
            }
        }
    }
}

//SOM
void AmbientSound(Sound Ambiente){
    if(!IsSoundPlaying(Ambiente))
    {
        PlaySound(Ambiente);
    }
}

//PROGRAMA PRINCIPAL
int main(void){

//DEFINICOES
    int i, j, num_cartas_na_mesa = 0;

    /* Bloco obsoleto com cartas.h implementado pelo Pedro
    // Gerador de cartas de baralho
    PilhaEnc *baralho = criaPilhaEnc();
    for(i = 1; i <= NUMEROS_DE_CARTAS; i++){
        for(j = 1; j <= NUMEROS_DE_NAIPES; j++){
            Carta carta;
            carta.num = i;
            carta.naipe = j;
            empilhaPilhaEnc(baralho, carta);
        }
    }
    */

    // Jogadores
    int num_jog;

    // Laço de consistência
    do{
        printf("Quer jogar contra quantos jogadores? (Maximo 3 | Minimo 1)");
        scanf("%d", &num_jog);
    }while(num_jog > 3 || num_jog < 1);

    //Ordenamento da partida
    ListaCircEnc *ordem = criaListaCircEnc();

    // O jogador será representado pela chave 0 (zero)
    for(i = 0; i <= num_jog; i++){
        Jogador aux;
        aux.chave = i;
        aux.mao = criaListaEnc2();
        aux.monte = criaPilhaEnc();
        insereInicioListaCircEnc(ordem, aux);
    }

    // Utilizando o código do Pedro:
    PilhaEnc *baralho = criaBaralho();

    // Entrega as cartas
    int verifica;
    NodoLEnc *aux_circ = ordem->prim;

    for(i = 0; i <= num_jog; i++){
        for(j = 0; j < NUM_CARTAS_POR_JOGADOR; j++){
            // Pega a carta do topo do baralho (pilha) e insere no início da mão (deque) do jogador na ordem de jogada (lista circular)
            verifica = insereInicioListaEnc2(aux_circ->info.mao, desempilhaCarta(baralho));
        }
    }
    // Neste ponto, todos os jogadores tem 4 cartas em suas mãos (deques) e nenhuma carta em seus montes (pilhas)

    // Colocar cartas na mesa
    ListaEnc2 *mesa = criaListaEnc2();
    for(i = 0; i < 4; i++){
        verifica = insereInicioListaEnc2(mesa, desempilhaCarta(baralho));
        num_cartas_na_mesa++;
    }

    
//INICIALIZACOES
    SetupWindow();

//CARREGAMENTO DA MUSICA DE FUNDO
    Music Ambiente;
    Ambiente = LoadMusicStream("./fundo.mp3");
    PlayMusicStream(Ambiente);
    SetMusicVolume(Ambiente, VOLUME);

//TEXTURAS
    Texture2D a = LoadTexture("./Texturas/a.png");

//LACO PRINCIPAL DO JOGO
    while (!WindowShouldClose() && !vaziaPilhaEnc(baralho){

//MUSICA DE FUNDO
        UpdateMusicStream(Ambiente);

//PARA USAR A TEXTURA
        Rectangle Jogador_Rec; //Cria um retangulo para lidar com o jogador
        Jogador_Rec.x = posX;
        Jogador_Rec.y = posY;
        Jogador_Rec.width = ARESTA_BLOCO;
        Jogador_Rec.height = ARESTA_BLOCO;

        Vector2 Jogador_Vec; //Cria um vetor para lidar com o jogador
        Jogador_Vec.x = posX;
        Jogador_Vec.y = posY;

//RODADAS
        //IMPLEMENTAR JOGADA DO JOGADOR
        //As cartas na mesa são tais: 1 2 4 8 13
        //As cartas dos montes são tais: 3 9
        //As suas cartas são tais: 2 9 12 6
        //Qual carta deseja jogar? X
        //X é numero valido? (esta entre as cartas do jogador?)
        //Modifica as estruturas necessarias para a jogada
        
        // Faz as jogadas dos demais jogadores
        for(i = 1; i < num_jog; i++){
            rodada(ordem, mesa, num_cartas_na_mesa, i);
        }
        
//----------------------------------------------------------------------------------
//ATUALIZA A REPRESENTACAO VISUAL DO JOGO
//----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

//DESENHA JOGADOR
        DrawTextureEx(textura, Jogador_Vec, 0, 0.01, WHITE);

// PRINCIPAIS COISAS DO JOGO

//DEFINE O FIM DE JOGO
        //Vitoria
        if(--------------------){
            DrawRectangle(0, 0, LARGURA, ALTURA, BLACK);
            DrawText("VOCE VENCEU!!!", (LARGURA - MeasureText("VOCE VENCEU!!!", FONTE*2))/2, (ALTURA-(FONTE*2))/2, FONTE*2, WHITE);
            DrawText(status[4], (LARGURA - MeasureText(status[4], FONTE*2))/2, (ALTURA+200-(FONTE*2))/2, FONTE*2, WHITE);
        //Derrota
        }else if(--------------){
            DrawRectangle(0, 0, LARGURA, ALTURA, BLACK);
            DrawText("VOCE PERDEU...", (LARGURA - MeasureText("VOCE PERDEU...", FONTE*2))/2, (ALTURA-(FONTE*2))/2, FONTE*2, WHITE);
            DrawText(status[4], (LARGURA - MeasureText(status[4], FONTE*2))/2, (ALTURA+200-(FONTE*2))/2, FONTE*2, WHITE);
        }

        EndDrawing();
    }
    UnloadMusicStream(Ambiente);
    UnloadTexture(a);

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
