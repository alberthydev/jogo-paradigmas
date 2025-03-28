#include <curses.h>
#include <unistd.h>
#include "fight.c"

int main(){
    WINDOW* win = initscr();
    curs_set(0); 

    draw_menu();
    
    refresh();  

    while (true) {
        int pressed = wgetch(win);
        if(pressed == '1'){
            clear();
            fight(win);
        }else if(pressed == '3'){
            break;
        }
        usleep(100000);
    }
    endwin();
}


