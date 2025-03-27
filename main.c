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
    
    refresh();  // Atualiza a tela

    while (true) {
        int pressed = wgetch(win);
        if(pressed == '1'){
            //printw("Left key pressed\n");
            for(;;){
                clear();  
                pressed = wgetch(win);
                if(pressed=='2'){
                    refresh();
                    return 0;
                }

                healthBar(playerH, opponentH);
                refresh();
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
            //printw("Right key pressed\n");
            break;
        }
        usleep(100000);
    }
    endwin();
}


