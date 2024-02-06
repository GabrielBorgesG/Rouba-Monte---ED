//JOGO ROUBA-MONTE

//BIBLIOTECAS

#include "lista_enc_dupla.h"
#include "pilha_enc.h"
#include "lista_circ.h"
#include "lista_enc.h"

#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//DEFINICOES
#define FPS 8
#define LARGURA 880
#define ALTURA (520+(FONTE*6))
#define VEL 20
#define ARESTA_BLOCO 20
#define NUM_BLOC_LARGURA_MAPA 44
#define NUM_BLOC_ALTURA_MAPA 26
#define FONTE 20 //Fonte da letra
#define VOLUME 0.2 //Vai de 0.0 a 1.0

// FUNCOES

void SetupWindow(){
    InitWindow(LARGURA, ALTURA, "ROUBA MONTE");
    SetTargetFPS(FPS);
    HideCursor();
    InitAudioDevice();
    //ToggleFullscreen();
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
    int i;

    // Monte (baralho)
    PilhaEnc *baralho = criaPilhaEnc();

    // Jogadores
    int num_jog;

    do{
        printf("Quer jogar contra quantos jogadores? (Maximo 3 | Minimo 1)");
        scanf("%d", &num_jog);
    }while(num_jog > 3 || num_jog < 1);

    Jogador Jogador;
    Jogador.chave = 1;
    Jogador.mao = criaListaEnc2();
    Jogador.monte = criaPilhaEnc();

    if(num_jog == 1){
        Jogador adversario1;

        adversario1.chave = 2;
        adversario1.mao = criaListaCircEnc();
        adversario1.monte = criaPilhaEnc();
    }else if(num_jog == 2){
        Jogador adversario1, adversario2;

        adversario1.chave = 2;
        adversario1.mao = criaListaCircEnc();
        adversario1.monte = criaPilhaEnc();

        adversario2.chave = 3;
        adversario2.mao = criaListaCircEnc();
        adversario2.monte = criaPilhaEnc();
    }else{
        Jogador adversario1, adversario2, adversario3;

        adversario1.chave = 2;
        adversario1.mao = criaListaCircEnc();
        adversario1.monte = criaPilhaEnc();

        adversario2.chave = 3;
        adversario2.mao = criaListaCircEnc();
        adversario2.monte = criaPilhaEnc();

        adversario3.chave = 4;
        adversario3.mao = criaListaCircEnc();
        adversario3.monte = criaPilhaEnc();
    }

    //Ordenamento da partida
    ListaCircEnc *ordem = criaListaCircEnc();

    for(i = 0; i <= num_jog; i++){
        insereInicioListaCircEnc(ordem, adversario1);
    }
    insereInicioListaCircEnc(ordem, Jogador);

//INICIALIZACOES
    SetupWindow();

//CARREGAMENTO DA MUSICA DE FUNDO
    Music Ambiente;
    Ambiente = LoadMusicStream("./Som/fundo.mp3");
    PlayMusicStream(Ambiente);
    SetMusicVolume(Ambiente, VOLUME);

//TEXTURAS
    Texture2D a = LoadTexture("./Texturas/a.png");

//LACO PRINCIPAL DO JOGO
    while (!WindowShouldClose()){

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
