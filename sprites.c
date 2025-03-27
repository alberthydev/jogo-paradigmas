#include <string.h>
#include <unistd.h>
#include <ncurses.h>

void healthBar(int, int);
void print_fight_1();

// CANVAS 32x62

void draw_box() {
    int height = 32;
    int width = 62;
    int start_x = 0;
    int start_y = 0;

    // Desenha a borda da caixa usando strings
    for (int i = 0; i < width; i++) {
        mvaddch(start_y, start_x + i, '-');  // Linha superior
        mvaddch(start_y + height - 1, start_x + i, '-');  // Linha inferior
    }
    for (int i = 0; i < height; i++) {
        mvaddch(start_y + i, start_x, '|');  // Linha esquerda
        mvaddch(start_y + i, start_x + width - 1, '|');  // Linha direita
    }
    mvaddch(start_y, start_x, '+');  // Canto superior esquerdo
    mvaddch(start_y, start_x + width - 1, '+');  // Canto superior direito
    mvaddch(start_y + height - 1, start_x, '+');  // Canto inferior esquerdo
    mvaddch(start_y + height - 1, start_x + width - 1, '+');  // Canto inferior direito
}

void draw_text_centered(const char* text, int y, int width) {
    int text_len = strlen(text);
    int start_x = (width - text_len) / 2;
    mvprintw(y, start_x, "%s", text);
}

void healthBar(int playerLife, int opponentLife){
    // Desenha a barra de vida do jogador
    printw("; PLAYER: ");
    for (int i = 0; i < playerLife; i++) {
        printw("S2 ");  // Exibe o coração
    }
    for (int i = playerLife; i < 3; i++) {
        printw("  ");  // Espaço em branco para representar a vida perdida
    }
    printw("\n");

    // Desenha a barra de vida do oponente
    printw("; OPONENTE: ");
    for (int i = 0; i < opponentLife; i++) {
        printw("S2 ");  // Exibe o coração
    }
    for (int i = opponentLife; i < 3; i++) {
        printw("  ");  // Espaço em branco para representar a vida perdida
    }
    printw("\n");
}

void fight_sprite_1(){
    printw(";                                                              \n");
    printw(";                                         mmmmmmmmmmm          \n");
    printw(";                                        mmmmmmmmmmmmmm        \n");
    printw(";                                      mmmmmmmmmmmmmmmmmmm     \n");
    printw(";                                      mmmmmmmmmmmmmmmmmm      \n");
    printw(";                                     mmmm       mmmmmmmm      \n");
    printw(";                                    mmx ----    ----   m      \n");
    printw(";                                     x  +++--  --+++   x      \n");
    printw(";                                     x   ++  t  +++    x      \n");
    printw(";                                     xx     tt        xx      \n");
    printw(";                                      xx   tttt      xqqqqq   \n");
    printw(";                               qqqqqqq xx   hhhhhh qqqqqq qq  \n");
    printw(";                             qq      qq xx   hhhh qqxx   qq q \n");
    printw(";                            qqq       qq xxx     xqq      qqq \n");
    printw(";                            qqq        q  xxxxxxxxqq      qqq \n");
    printw(";                             qqq      qqq         qqqqqqqqqq  \n");
    printw(";                              qqqqqqqqq qq           qq    qq \n");
    printw(";                                qqq      qq           qq    qq\n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";     xxxxxxxxx              xxxxxxxxxx                        \n");
    printw(";   xxx        xx          xxx       xxxxx                     \n");
    printw(";   xx           x        xxx           xxx                    \n");
    printw(";  xxx            x        xx             xx                   \n");
    printw(";  xx          xxxx         xxx           xx                   \n");
    printw(";  xx         xx  x        xx  x          xx                   \n");
    printw(";  xx            xx        x   xx        xx                    \n");
    printw(";  xx          x          xx   x       xxx                     \n");
    printw(";   xxx      xxx           xx      xxxxx                       \n");
    printw(";    x       x             x        x                          \n");
}

void fight_sprite_2(){
    printw(";                                                              \n");
    printw(";                                 mmmmmmmmmmm                  \n");
    printw(";                                mmmmmmmmmmmmmm                \n");
    printw(";                              mmmmmmmmmmmmmmmmmmm             \n");
    printw(";                              mmmmmmmmmmmmmmmmmm              \n");
    printw(";                             mmmm       mmmmmmmm              \n");
    printw(";                            mmx ----    ----   m              \n");
    printw(";                             x  +++--  --+++   x              \n");
    printw(";                             x   ++  t  +++    x              \n");
    printw(";                             xx     tt        xx              \n");
    printw(";                              xx   tttt      xqqqqq           \n");
    printw(";                       qqqqqqq xx   hhhhhh qqqqqq qq          \n");
    printw(";                     qq      qq xx   hhhh qqxx   qq q         \n");
    printw(";                    qqq       qq xxx     xqq      qqq         \n");
    printw(";                    qqq        q  xxxxxxxxqq      qqq         \n");
    printw(";                     qqq      qqq         qqqqqqqqqq          \n");
    printw(";                      qqqqqqqqq qq           qq    qq         \n");
    printw(";                        qqq      qq           qq    qq        \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";      xxxxxxxxx              xxxxxxxxxx                        \n");
    printw(";    xxx        xx          xxx       xxxxx                     \n");
    printw(";    xx           x        xxx           xxx                    \n");
    printw(";   xxx            x        xx             xx                   \n");
    printw(";   xx          xxxx         xxx           xx                   \n");
    printw(";   xx         xx  x        xx  x          xx                   \n");
    printw(";   xx            xx        x   xx        xx                    \n");
    printw(";   xx          x          xx   x       xxx                     \n");
    printw(";    xxx      xxx           xx      xxxxx                       \n");
    printw(";     x       x             x        x                          \n");
}

//void punch(){
//    
//}
