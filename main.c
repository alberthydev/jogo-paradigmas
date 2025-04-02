#include <curses.h>
#include <unistd.h>
#include "fight.c"

int main(){
    WINDOW* win = initscr(); // Define a janela no terminal para alterações
    curs_set(0); // Desabilita a exibição do cursor na tela
    noecho(); 
    keypad(win, TRUE); // Possibilita a leitura das setas do teclado

    int highlight = 1; // Variavel para definir a opção do menu interativo
    int choice = 0; // Escolha do menu interativo

    // While infinito para o menu principal
    while (true) {
        clear(); // Limpa a tela
        draw_interactive_menu(win, highlight); // Chama a função do menu interativo
        refresh(); // Confirma alterações na tela

        int pressed = wgetch(win); // Input do usuario
        switch (pressed) { // Switch case para definir a escolha do usuario no menu
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
            case 10: // Enter
                choice = highlight; // Define a escolha no menu
                break;
            default:
                break;
        }

        if (choice == 1) { // Chama a luta principal
            clear();
            nodelay(win, false); // Certifique-se de que o modo bloqueante está ativado antes de entrar na luta
            fight(win); // Chama a função luta do jogo
            nodelay(win, false); // Restaura o modo bloqueante após a luta
            flushinp(); // Limpa o buffer de entrada do usuário
            choice = 0; // Reseta a variável para novas entradas
        } else if (choice == 2) {
            clear();
            flushinp();          
            how_to_play(); // Chama a tela de tutorial do jogo
            wgetch(win); // Espera por uma tecla para voltar ao menu
            choice = 0;
        } else if (choice == 3) {
            break; // Sai do jogo
        }
    }

    endwin(); // Encerra a tela do terminal
    return 0;
}
