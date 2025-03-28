#include <curses.h>
#include <unistd.h>
#include "sprites.c"

int main(){
    WINDOW* win = initscr();
    keypad(win, true);
    nodelay(win, true);
    curs_set(0);

    int playerH = 5;
    int opponentH = 5;
    int sprite = 1;
    int height = 32;
    int width = 62;

    draw_menu();
    
    refresh();  

    while (true) {
        int pressed = wgetch(win);
        if(pressed == '1'){
            for(;;){
                clear();  
                pressed = wgetch(win);
                if(pressed=='2'){
                    refresh();
                    clear();
                    healthBar(playerH, opponentH);
                }

                healthBar(playerH, opponentH);
                if(sprite == 1){
                    fight_sprite_1();
                    refresh();
                    sprite = 0;
                }
                else{
                    fight_sprite_2();
                    refresh();  
                    sprite = 1;
                }
                usleep(450000);  
            }
        }else if(pressed == '3'){
            break;
        }
        usleep(100000);
    }
    endwin();
}


