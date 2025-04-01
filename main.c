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
                    highlight = 3; // Número de opções no menu
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == 3)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: // Enter
                choice = highlight;
                break;
            default:
                break;
        }

        if (choice == 1) {
            clear();
            nodelay(win, false); // Certifique-se de que o modo bloqueante está ativado antes de entrar na luta
            fight(win);
            nodelay(win, false); // Restaura o modo bloqueante após a luta
            flushinp();          // Limpa o buffer de entrada
            choice = 0;          // Reset choice
        } else if (choice == 2) {
            clear();
            flushinp();          // Limpa o buffer de entrada antes de exibir "Como Jogar"
            how_to_play();
            wgetch(win);         // Espera por uma tecla para voltar ao menu
            choice = 0;          // Reset choice
        } else if (choice == 3) {
            break;
        }
        usleep(100000);
    }

    endwin();
    return 0;
}
