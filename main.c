#include <curses.h>
#include <unistd.h>

void main(){
    WINDOW* win = initscr();
    keypad(win, true);
    nodelay(win, true);
    while (true) {
        int pressed = wgetch(win);
        if(pressed == KEY_LEFT){
            printw("Left key pressed\n");
        }
        usleep(100000);
    }
    endwin();
}


