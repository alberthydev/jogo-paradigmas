#include <curses.h>
#include <unistd.h>
#include "fight.c"

void draw_interactive_menu(WINDOW *menu_win, int highlight);

int main(){
    WINDOW* win = initscr();
    curs_set(0); 
    noecho();
    keypad(win, TRUE);

    int highlight = 1;
    int choice = 0;

    while (true) {
        clear();
        draw_interactive_menu(win, highlight);
        refresh();

        int pressed = wgetch(win);
        switch (pressed) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = 3; 
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == 3)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: 
                choice = highlight;
                break;
            default:
                break;
        }

        if (choice == 1) {
            clear();
            fight(win);
            choice = 0; 
        } else if (choice == 2) {
            clear();
            how_to_play();
            wgetch(win);
            choice = 0;
        } else if (choice == 3) {
            break;
        }
        usleep(100000);
    }

    endwin();
    return 0;
}

void draw_interactive_menu(WINDOW *menu_win, int highlight) {
    const char *options[] = {
        "1 - INICIAR",
        "2 - COMO JOGAR",
        "3 - SAIR"
    };

    draw_menu(); 
    int start_y = 17; 
    int start_x = 24; 

    for (int i = 0; i < 3; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE); 
            mvwprintw(menu_win, start_y + i * 2, start_x, "%s", options[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, start_y + i * 2, start_x, "%s", options[i]);
        }
    }
    wrefresh(menu_win);
}
