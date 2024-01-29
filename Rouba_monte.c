//JOGO ROUBA-MONTE

//BIBLIOTECAS
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
    int a;
   
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
