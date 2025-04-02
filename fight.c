#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sprites.c"

// Declaração das funções do arquivo
void clear_screen();
void fight(WINDOW*);
void player_punch();
void opponent_punch();

// Variaveis globais
int option;
int playerH = 5;
int opponentH = 5;

// Limpa a tela, partir de uma coordenada
void clear_screen(){
    move(2,0); // Move o cursor para Y=2 e X=0
    clrtobot(); // Limpa a tela a partir dessa coordenada do cursor
}

// Função principal da luta
void fight(WINDOW* win) {
    srand(time(NULL)); // Define a seed do random
    playerH = 5; // Garante os valores de vida do jogador
    opponentH = 5; // Garante os valores de vida do oponente
    int opponentAttackTime = rand() % 10; // Define o tempo de ataque do oponente
    int sprite = 1; // Define o primeiro sprite da luta
        
    for(;;){
        clear(); // Limpa a tela

        // Chama as telas de vitória ou derrota
        if(playerH == 0){
            clear();
            defeat(); 
            refresh(); 
            usleep(1000000); // Aguarda 1 segundo
            clear();
            break;
        }
        else if(opponentH == 0){
            clear();
            victory(); 
            refresh();
            usleep(1000000);
            clear();
            break;
        }

        // Desenha a barra de vida
        health_bar(playerH, opponentH);

        // Ataque do oponente
        if(opponentAttackTime == 0){ 
            clear_screen(); // Limpa a tela abaixo da barra de vida
            opponent_punch(win); // Chama o sprite de soco do oponente
            opponentAttackTime = rand() % 7; // Redefine o tempo de ataque do oponente
        }
        else 
            opponentAttackTime--; // Decrementa um do tempo de ataque do oponente
        
        nodelay(win, true); // Garante a continuidade de execução
         
        int kplayer_punch = wgetch(win); // Ataque do jogador
        if(kplayer_punch == '2' && playerH > 0){ // Verifica se o jogador ainda tem vida
            flushinp(); // Limpa o cache
            clear_screen();
            player_punch(); // Soco do jogador
        }

        // Sair da luta a qualquer momento pressionando "Q" ou "q"
        if(kplayer_punch == 'q'|| kplayer_punch == 'Q'){
            break;
        }
        kplayer_punch = -1; // Redefine o valor de ataque do jogador
        
        flushinp();
        clear_screen();
        if(sprite == 1){ // Define qual dos sprites de animação irá ser exibido
            fight_sprite_1();
            refresh();
            usleep(300000);
            sprite = 0;
        }
        else{
            fight_sprite_2();
            refresh();  
            usleep(300000);
            sprite = 1;
        }
        usleep(100000); // Aguarda um segundo
    } 
}

void player_punch(){
    int opponentDefense = rand() % 2; // Define se o oponente irá defender ou não
    
    clear();
    health_bar(playerH, opponentH);
    refresh();

    player_punch_1(); // Chama o primeiro sprite do ataque do jogador
    refresh();
    usleep(300000);

    clear_screen();
    player_punch_2(); // Chama o segundo sprite do ataque do jogador
    refresh();
    usleep(300000);

    clear_screen();
    if(opponentDefense == 0){ // Defesa do oponente
        player_punch_4();
        refresh();
        usleep(800000);

    }else{
        player_punch_3();
        refresh();
        opponentH--; // Diminui a vida do oponente
        health_bar(playerH, opponentH);
        usleep(800000);
    }
}

void opponent_punch(WINDOW* win){ 
    int pressed = -1; // Defesa do ataque do oponente

    clear();
    health_bar(playerH, opponentH);
    refresh();
        
    opponent_punch_1(); // Chama o primeiro sprite do ataque do oponente
    refresh();
    usleep(300000);
    
    clear_screen();
    opponent_punch_2(); // Chama o segundo sprite do ataque do oponente
    refresh();
    flushinp(); // Limpa o buffer de entrada do usuário

    // Aguarda um curto período para capturar a entrada do jogador
    for (int i = 0; i < 10; i++) { 
        pressed = wgetch(win);
        if (pressed == '1') break; // Se o jogador pressionar "1", interrompe o loop
        usleep(30000); // Aguarda 30ms antes de tentar novamente
    }

    clear_screen();
    if(pressed == '1'){ // Se o jogador pressionar "1" a tempo, ele defende
        flushinp();
        opponent_punch_4(); // Chama a defesa do jogador
        refresh();
        usleep(800000);
    }else{
        opponent_punch_3(); // Chama o soco no jogador
        refresh();
        playerH--; // Diminui a vida do jogador
        health_bar(playerH, opponentH);
        usleep(800000);
    }
    pressed = -1;
}
