#include <conio2.h>
#include <windows.h>
#include <stdio.h>
#include <locale.h>

#include "cartas.h"
#include "pilhas.h"
#include "listas.h"

#include "baralho.h"
#include "mao.h"
#include "mesa.h"
#include "jogadores.h"

void menu();

void titulo() {

    gotoxy((TAMANHO_TELA_X - 64)/2, 5);
    printf("  ____   ___  _   _ ____    _      __  __  ___  _   _ _____ _____ \n");
    
    gotoxy((TAMANHO_TELA_X - 64)/2, 6);
    printf(" |  _ \\ / _ \\| | | | __ )  / \\    |  \\/  |/ _ \\| \\ | |_   _| ____|\n");
    
    gotoxy((TAMANHO_TELA_X - 64)/2, 7);
    printf(" | |_) | | | | | | |  _ \\ / _ \\   | |\\/| | | | |  \\| | | | |  _|  \n");
    
    gotoxy((TAMANHO_TELA_X - 64)/2, 8);
    printf(" |  _ <| |_| | |_| | |_) / ___ \\  | |  | | |_| | |\\  | | | | |___ \n");
    
    gotoxy((TAMANHO_TELA_X - 64)/2, 9);
    printf(" |_| \\_\\\\___/ \\___/|____/_/   \\_\\ |_|  |_|\\___/|_| \\_| |_| |_____|\n");

}

void bordas(){
    for(int i = 0; i<TAMANHO_TELA_X; i++){
        gotoxy(i, 1); printf("*");
        gotoxy(i, TAMANHO_TELA_Y); printf("*");
    }

    for(int i = 0; i< TAMANHO_TELA_Y; i++){
        gotoxy(1, i); printf("*");
        gotoxy(TAMANHO_TELA_X, i); printf("*");
    }

}

void creditos(){
    clrscr();

    gotoxy(10, 5);

    printf("Produzido por:");

    gotoxy(10,6);
    printf("Bernardo Kappaun de Oliveira");
    gotoxy(10,7);
    printf("Gabriel Borges Gambim");
    gotoxy(10,8);
    printf("Pedro Bezerra Iatauro");

    gotoxy(10,10);
    printf("Pressione qualquer tecla para voltar ao menu.");

    getch(); // Aguarda o usuário pressionar uma tecla

    menu();
}

void imprimeJogadoresPC(int nJogadores, NodoLEnc* aux){
    aux = aux->prox;
    imprimePilha(aux->jogador->monte, 29, 2);
    gotoxy(29,7); printf("Monte %d", aux->jogador->id);
    gotoxy((TAMANHO_TELA_X - 9)/2, 2); printf("Jogador %d", aux->jogador->id);
    gotoxy((TAMANHO_TELA_X - 16)/2, 3); printf("Cartas na mao: %d", aux->jogador->mao->tam);
    if(nJogadores >= 3){
        aux = aux->prox;
        imprimePilha(aux->jogador->monte, 5, 20);
        gotoxy(5,25); printf("Monte %d", aux->jogador->id);
        gotoxy(6, 14); printf("Jogador %d", aux->jogador->id);
        gotoxy(3, 15); printf("Cartas na mao: %d", aux->jogador->mao->tam);
    }if(nJogadores >= 4){
        aux = aux->prox;
        imprimePilha(aux->jogador->monte, 109, 5);
        gotoxy(109,10); printf("Monte %d", aux->jogador->id);
        gotoxy(105, 14); printf("Jogador %d", aux->jogador->id);
        gotoxy(102, 15); printf("Cartas na mao: %d", aux->jogador->mao->tam);
    }
}

void imprimeOpcoesPossiveis(){
    gotoxy(100, 23); printf("Opcoes Possiveis");
    gotoxy(100, 25); printf("[R] Roubar Monte");
    gotoxy(100, 26); printf("[P] Pegar da mesa");
    gotoxy(100, 27); printf("[D] Descartar");
}

void opcoes(int opcaoSelecionada) {
    char *opcoes[] = {"Iniciar Jogo", "Creditos", "Sair"};
    #define NUMERO_OPCOES 3

    gotoxy(10, 12);
    printf("Selecione uma opcao e pressione Enter para confirmar:");

    for (int i = 0; i < NUMERO_OPCOES; i++) {
        gotoxy(10, 14 + i);
        if (i == opcaoSelecionada - 1) {
            textcolor(LIGHTBLUE);
            printf("%d. %s\n", i + 1, opcoes[i]);
            textcolor(WHITE); // Reseta a cor do texto
        } else {
            printf("%d. %s\n", i + 1, opcoes[i]);
        }
    }
}

void jogo(int nJogadores){
    Pilha* baralho;
    OrdemJogadas* ordenacao;
    Mesa* mesa;
    NodoLEnc* rodada;
    NodoLEnc* aux;
    Carta cartaMao;
    Jogador* roubavel;
    int posMao;
    int posMesa;
    int cartaSelecionada = 0;
    int cartasBaralho = TAMANHO_BARALHO;
    char indiceCarta;
    char str[3];
    char opcao;

    baralho = criaBaralho();

    embaralhaBaralho(baralho);

    ordenacao = criaOrdemJogadas(baralho, nJogadores);
    cartasBaralho -= nJogadores*TAMANHO_MAO;

    mesa = criaMesa(baralho);
    cartasBaralho -= TAMANHO_MESA;

    rodada = ordenacao->prim;
    while(rodada->jogador->mao->prim != NULL){
        // RODADA DO JOGADOR //
        clrscr();
        bordas();
        gotoxy(3,2);
        printf("Cartas no baralho: %d", cartasBaralho);
        imprimeListaEnc2(mesa, (TAMANHO_TELA_Y - 5)/2);
        imprimeListaEnc2(rodada->jogador->mao, 24);
        gotoxy(84,23); printf("Seu monte");
        imprimePilha(rodada->jogador->monte, 85, 24);
        imprimeJogadoresPC(nJogadores, rodada);
        imprimeIndicesCarta(rodada->jogador->mao, 23, cartaSelecionada);
        indiceCarta = getch(); // Lê uma tecla pressionada pelo usuário
        int indiceCartaInt = indiceCarta - '0';
        // Loop para navegação
        while (indiceCarta != '\r') { // Enquanto o jogador não pressionar Enter
            if(indiceCartaInt >= 1 && indiceCartaInt <= rodada->jogador->mao->tam){
                cartaSelecionada = indiceCartaInt;
                imprimeIndicesCarta(rodada->jogador->mao, 23, cartaSelecionada);
            }
            indiceCarta = getch(); // Lê a próxima tecla pressionada pelo usuário
            indiceCartaInt = indiceCarta - '0';
        }

        // Agora o jogador pressionou Enter, então prosseguimos com a seleção
        imprimeOpcoesPossiveis();
        // Limpa a entrada de teclado
        opcao = getch();
        while(opcao != 'R' && opcao != 'P' && opcao != 'D' && opcao != 'r' && opcao != 'p' && opcao != 'd'){
            opcao = getch();
        }
        cartaMao = removeCartaListaEnc2(rodada->jogador->mao, cartaSelecionada);
        int retorno = 0;
        while(retorno == 0){
            switch(opcao){
                case 'R':
                case 'r':
                    roubavel = buscaMontes(rodada, cartaMao);
                    if(roubavel != NULL){
                        roubaMonte(rodada->jogador, roubavel, cartaMao);
                        retorno = 1;
                    }
                    break;
                case 'P':
                case 'p':
                    posMesa = buscaMesa(mesa, cartaMao);
                    if(posMesa != -1){
                        pegaMesa(rodada->jogador, mesa, cartaMao, posMesa);
                        retorno = 1;
                    }
                    break;
                case 'D':
                case 'd':
                    insereCartaListaEnc2(mesa, cartaMao);
                    retorno = 1;
                    break;
            }
            if (retorno == 0){
                opcao = getch();
            }
        }

        if(mesa->prim == NULL && !vaziaPilha(baralho)){
            mesa = criaMesa(baralho);
            cartasBaralho -= TAMANHO_MESA;
        }

        if(rodada->jogador->mao->prim == NULL && !vaziaPilha(baralho)){
            rodada->jogador->mao = criaMao(baralho);
            cartasBaralho -= TAMANHO_MAO;
        }

        // APENAS PARA TESTE
        int single_multi = 2;

        if(single_multi == 1) rodada = rodada->prox; // Jogo multiplayer (cada jogador faz suas próprias jogadas)
        if(single_multi == 2) jogo_singleplayer(ordenacao, mesa, nJogadores); // Jogo singleplayer (o computador faz as jogadas)

    }

    clrscr();
    gotoxy((TAMANHO_TELA_X - 64)/2, 5);
    printf("  _____ ___ __  __    ____  _____        _  ___   ____  ___  \n");
    gotoxy((TAMANHO_TELA_X - 64)/2, 6);
    printf(" |  ___|_ _|  \\/  |  |  _ \\| ____|      | |/ _ \\ / ___|/ _ \\ \n");
    gotoxy((TAMANHO_TELA_X - 64)/2, 7);
    printf(" | |_   | || |\\/| |  | | | |  _|     _  | | | | | |  _| | | |\n");
    gotoxy((TAMANHO_TELA_X - 64)/2, 8);
    printf(" |  _|  | || |  | |  | |_| | |___   | |_| | |_| | |_| | |_| |\n");
    gotoxy((TAMANHO_TELA_X - 64)/2, 9);
    printf(" |_|   |___|_|  |_|  |____/|_____|   \\___/ \\___/ \\____|\\___/ \n");

    rodada = ordenacao->prim;

    // Cria um array temporário para armazenar as pontuações e os jogadores
    struct {
        int pontuacao;
        Jogador* jogador;
    } ranking[nJogadores];

    // Preenche o array com as pontuações e os jogadores
    NodoLEnc* nodo = ordenacao->prim;
    for (int i = 0; i < nJogadores; i++) {
        ranking[i].pontuacao = 0;
        while(!vaziaPilha(nodo->jogador->monte)){
            Carta aux = desempilhaCarta(nodo->jogador->monte);
            ranking[i].pontuacao++;
        }
        ranking[i].jogador = nodo->jogador;
        nodo = nodo->prox;
    }

    // Ordena o array em ordem decrescente de pontuação usando Bubble Sort
    for (int i = 0; i < nJogadores; i++) {
        for (int j = 0; j < nJogadores - i - 1; j++) {
            if (ranking[j].pontuacao < ranking[j+1].pontuacao) {
                // Troca ranking[j] e ranking[j+1]
                int tempPontuacao = ranking[j].pontuacao;
                Jogador* tempJogador = ranking[j].jogador;
                ranking[j].pontuacao = ranking[j+1].pontuacao;
                ranking[j].jogador = ranking[j+1].jogador;
                ranking[j+1].pontuacao = tempPontuacao;
                ranking[j+1].jogador = tempJogador;
            }
        }
    }

    // Imprime as pontuações e os jogadores em ordem
    gotoxy((TAMANHO_TELA_X - 10)/2, 14); printf("Ranking:");
    for (int i = 0; i < 4; i++) {
        gotoxy((TAMANHO_TELA_X - 25)/2, 15 + i);
        printf("Jogador %d | Pontuacao: %d\n", ranking[i].jogador->id, ranking[i].pontuacao);
    }

    gotoxy(10,25);
    printf("Pressione qualquer tecla para ir aos creditos.");

    getch(); // Aguarda o usuário pressionar uma tecla

}

void menu(){
    int opcaoSelecionada = 0;
    char tecla;
    int nJogadores;

    while(1){
        clrscr();
        titulo();
        opcoes(opcaoSelecionada);
        tecla = getch(); // Lê uma tecla pressionada pelo usuário

        if (tecla >= '1' && tecla <= '3') {
            opcaoSelecionada = tecla - '0';
        }

        if (tecla == '\r') {
            // O usuário pressionou Enter, então executa a opção selecionada
            switch (opcaoSelecionada) {
                case 1:
                    // Iniciar Jogo
                    do{
                        clrscr();
                        titulo();
                        gotoxy(10, 12);
                        printf("Quer jogar contra quantos jogadores? (Maximo 3 | Minimo 1)");
                        gotoxy(10,15);
                        printf("Regras:");
                        gotoxy(10, 16);
                        printf("1. Cartas so podem ser empilhadas se possuirem o mesmo valor (naipes nao importam);");
                        gotoxy(10, 17);
                        printf("2. Pode se pegar cartas tanto da mesa quanto roubar montes de outros jogadores;");
                        gotoxy(10, 18);
                        printf("3. Ganha quem tiver mais cartas ao final do jogo.");
                        gotoxy(10,20);
                        printf("Tutorial: Selecione as cartas da sua mao pela sua posicao (de 1 ate 4) e pressione Enter.");
                        gotoxy(10,21);
                        printf("As opcoes possiveis aparecerao posteriormente");
                        gotoxy(10, 13);
                        scanf("%d", &nJogadores);
                    }while(nJogadores > 3 || nJogadores < 1);
                    nJogadores++;
                    jogo(nJogadores);
                case 2:
                    // Creditos
                    creditos();
                case 3:
                    // Sair
                    return;
            }
        }


    }
}

//Função que conta o número de cartas do jogador
int quantasCartas(ListaCircEnc* ordem, int chave_jogador){
    int cont = 0;
    NodoLEnc *b = ordem->prim;

    // For que faz b apontar para o jogador desejado
    for(; cont < chave_jogador; cont++){
        b = b->prox;
    }

    // Agora que se tem o jogador desejado, c irá percorrer a mao (deque) do jogador
    // Note que cont é reiniciado para ser reutilizado
    cont = 0;
    NodoLEnc2 *c = b->jogador->mao->prim;
    while(c != NULL){
        c = c->prox;
        cont++;
    }
    
    return cont;
}

// Segunda versão da função (para ver se dá certo) -> reutilizando a funçao quantasCartas
void rodada(ListaCircEnc* ordem, ListaEnc2 *mesa, int chave_jogador){
    int cont = 0, i, umaJogada = 0;
    NodoLEnc *b = ordem->prim, *f;

    // For que faz b apontar para o jogador desejado
    for(; cont < chave_jogador; cont++){
        b = b->prox;
    }

    // Verifica os montes
    NodoLEnc2 *c = b->jogador->mao->prim;
    for(f = ordem->prim; f != NULL; f = f->prox){ // Muda jogador
        for(c = b->jogador->mao->prim; c != NULL; c = c->prox){ // Muda carta
            if(b->jogador->id != f->jogador->id){
                if(c->carta.valor == f->jogador->monte->topo->carta.valor){  
                    roubaMonte(b, f, f->jogador->monte->topo->carta);
                    umaJogada = 1;
                }
            }
        }
    }

    // Agora que se tem o jogador desejado, c irá percorrer a mao (deque) do jogador
    c = b->jogador->mao->prim; // Para a mao do jogador desejado
    NodoLEnc2 *d = mesa->prim;
    while(c != NULL && umaJogada == 0){
        for(; d != NULL; d = d->prox){
            if(c->carta.valor == d->carta.valor){ // Se encontrar cartas de mesmo valor entre mão e mesa

                // Coloca na pilha do jogador
                empilhaPilhaEnc(b->jogador->monte, c->carta);
                empilhaPilhaEnc(b->jogador->monte, d->carta);

                // Remove da mesa e da mão
                removeInfoListaEnc2(b->jogador->mao, c->carta.valor);
                removeInfoListaEnc2(mesa, d->carta.valor);
                umaJogada = 1;
            }
        }
        c = c->prox;
        d = mesa->prim;
    }

    // Se não houver carta, o jogador joga uma para a mesa
    if(umaJogada == 0){
        insereInicioListaEnc2(mesa, b->jogador->mao->prim);
        removeInfoListaEnc2(b->jogador->mao, b->jogador->mao->prim->carta.valor);
    }
}

void jogo_singleplayer(ListaCircEnc *ordem, ListaEnc2 *mesa, int nJogadores){

    int i;

//RODADA        
        NodoLEnc2 *cartas_mesa = mesa->prim;
        NodoLEnc2 *cartas_mao = ordem->prim->jogador->mao->prim; // Pega a mão do primeiro jogador (chave  = 0), que no caso é o usuário
        NodoLEnc *players = ordem->prim->prox;
        
        // Faz as jogadas dos demais jogadores
        for(i = 1; i < nJogadores; i++){
            rodada(ordem, mesa, i);
        }
}

int main() {
    // Obtém o manipulador para o console de saída padrão
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Define o tamanho do console
    SMALL_RECT windowSize = {0, 0, TAMANHO_TELA_X, TAMANHO_TELA_Y};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // Define o tamanho do buffer do console para ser o mesmo que o tamanho da janela do console
    COORD bufferSize = {windowSize.Right - windowSize.Left + 1, windowSize.Bottom - windowSize.Top + 1};
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Set the locale to the default system locale
    setlocale(LC_ALL, "Portuguese");

    menu();
    return 0;
}