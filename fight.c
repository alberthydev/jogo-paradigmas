#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sprites.c"

void fight(WINDOW*);
void opponent_punch();

int option;
int playerH = 5;
int opponentH = 5;

void clear_screen(){
    move(2,0);
    clrtobot();
}

// Function to simulate a fight between two boxers
void fight(WINDOW* win) {
    srand(time(NULL));
    int opponentAttackTime = rand() % 10;
    int sprite = 1;
    
    for(;;){
        clear();
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
        usleep(200000);
    } 
}

void player_punch(){
    int opponentDefense = rand() % 2;
    
    clear();
    health_bar(playerH, opponentH);
    refresh();

    player_punch_1();
    refresh();
    usleep(450000);

    //clear();
    //health_bar(playerH, opponentH);
    clear_screen();
    player_punch_2();
    refresh();
    usleep(450000);


    //clear();
    clear_screen();
    if(opponentDefense == 0){
        //health_bar(playerH, opponentH);
        player_punch_4();
        refresh();

    }else{
        //health_bar(playerH, opponentH);
        player_punch_3();
        refresh();

        opponentH--;
    }
}

void opponent_punch(){ 
    WINDOW* teste = initscr();
    keypad(teste, true);
    int pressed = -1; 
    flushinp();
    
    clear();
    health_bar(playerH, opponentH);
    refresh();
        
    opponent_punch_1();
    refresh();
    pressed=-1;
    flushinp();
    usleep(450000);
    
    clear_screen();
    opponent_punch_2();
    refresh();
    flushinp();
    usleep(400000);
    pressed = wgetch(teste);

    clear_screen();
    if(pressed == '1'){
        flushinp();
        opponent_punch_4();
        refresh();
        usleep(800000);
        pressed=-1;

    }else{
        opponent_punch_3();
        refresh();
        usleep(800000);
        playerH--;
    }
    pressed=-1;
}
