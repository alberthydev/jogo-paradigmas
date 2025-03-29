#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sprites.c"

void fight(WINDOW*);
void player_punch();
void opponent_punch();

int option;
int playerH = 5;
int opponentH = 5;

void clear_screen(){
    move(2,0);
    clrtobot();
}

void fight(WINDOW* win) {
    srand(time(NULL));
    playerH = 5;
    opponentH = 5;
    int opponentAttackTime = rand() % 10;
    int sprite = 1;
        
    for(;;){
        clear();

        if(playerH == 0){
            clear();
            defeat(); 
            refresh();
            usleep(900000);
            clear();
            break;
        }
        else if(opponentH == 0){
            clear();
            victory(); 
            refresh();
            usleep(900000);
            clear();
            break;
        }

        health_bar(playerH, opponentH);
        if(opponentAttackTime == 0){
            clear_screen();
            opponent_punch();
            opponentAttackTime = rand() % 7;
        }
        else 
            opponentAttackTime--;
        
        keypad(win, true);
        nodelay(win, true);
        
        int kplayer_punch = wgetch(win);
        if(kplayer_punch == '2'){
            flushinp();
            clear_screen();
            player_punch();
        }
        kplayer_punch = -1;
        
        flushinp();
        clear_screen();
        if(sprite == 1){
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
        usleep(100000);
    } 
}

void player_punch(){
    int opponentDefense = rand() % 2;
    
    clear();
    health_bar(playerH, opponentH);
    refresh();

    player_punch_1();
    refresh();
    usleep(300000);

    clear_screen();
    player_punch_2();
    refresh();
    usleep(300000);

    clear_screen();
    if(opponentDefense == 0){
        player_punch_4();
        refresh();
        usleep(800000);

    }else{
        player_punch_3();
        refresh();
        usleep(800000);
        opponentH--;
        health_bar(playerH, opponentH);
    }
}

void opponent_punch(){ 
    WINDOW* teste = initscr();
    keypad(teste, true);
    int pressed = -1; 
    
    clear();
    health_bar(playerH, opponentH);
    refresh();
        
    opponent_punch_1();
    refresh();
    pressed=-1;
    usleep(300000);
    
    clear_screen();
    opponent_punch_2();
    refresh();
    flushinp();
    usleep(300000);
    pressed = wgetch(teste);

    clear_screen();
    if(pressed == '1'){
        flushinp();
        opponent_punch_4();
        refresh();
        usleep(800000);
    }else{
        opponent_punch_3();
        refresh();
        usleep(800000);
        playerH--;
        health_bar(playerH, opponentH);
    }
    pressed=-1;
}
