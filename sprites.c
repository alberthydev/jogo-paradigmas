#include <curses.h>

void draw_interactive_menu(WINDOW*, int);
void draw_menu();
void how_to_play();
void health_bar(int, int);
void fight_sprite_1();
void fight_sprite_2();
void player_punch_1();
void player_punch_2();
void player_punch_3();
void player_punch_4();
void opponent_punch_1();
void opponent_punch_2();
void opponent_punch_3();
void opponent_punch_4();
void victory();
void defeat();

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

void draw_menu() {
    printw("+-------------------------------------------------------------+\n"); 
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|     ______   _______           _______  _______  _______    |\n");
    printw("|    (  ___ \\ (  ___  )|\\     /|(  ____ \\(  ____ )(  ____ \\   |\n");
    printw("|    | (   ) )| (   ) |( \\   / )| (    \\/| (    )|| (    \\/   |\n");
    printw("|    | (__/ / | |   | | \\ (_) / | (__    | (____)|| (_____    |\n");
    printw("|    |  __ (  | |   | |  ) _ (  |  __)   |     __)(_____  )   |\n");
    printw("|    | (  \\ \\ | |   | | / ( ) \\ | (      | (\\ (         ) |   |\n");
    printw("|    | )___) )| (___) |( /   \\ )| (____/\\| ) \\ \\__/\\____) |   |\n");
    printw("|    |/ \\___/ (_______)|/     \\|(_______/|/   \\__/\\_______)   |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("+-------------------------------------------------------------+\n");

    refresh();
}

void how_to_play() {
    clear(); // Limpa a tela antes de desenhar
    printw("+-------------------------------------------------------------+\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("|  +-------------------------------------------------------+  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |   O JOGO E BEM SIMPLES, VOCE DEFENDE E ATACA, O SEU   |  |\n");
    printw("|  |   OPONENTE FARA O MESMO, QUANDO VOCE FOR SOFRER UMA   |  |\n");
    printw("|  |    TENTATIVA DE ATAQUE, APERTE O BOTAO DE DEFESA A    |  |\n");
    printw("|  |   TEMPO E NAO PERDERA VIDA, QUANDO VOCE ATACAR, SEU   |  |\n");
    printw("|  |    OPONENTE PODE DEFENDER TAMBEM ENTAO SEJA RAPIDO    |  |\n");
    printw("|  |          E ESTRATEGICO PARA CHEGAR A VITORIA          |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |            1 - DEFENDE                                |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |            2 - ATACA                                  |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |            Q - SAIRA DE UMA LUTA JA INICIADA          |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |     PARA VOLTAR AO MENU PRESSIONE QUALQUER TECLA      |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  |                                                       |  |\n");
    printw("|  +-------------------------------------------------------+  |\n");
    printw("|                                                             |\n");
    printw("|                                                             |\n");
    printw("+-------------------------------------------------------------+\n");
    refresh();
}

void health_bar(int playerLife, int opponentLife){
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
    printw(";  xx          xx         xx   x       xxx                     \n");
    printw(";   xxx      xxx           xx      xxxxx                       \n");
    printw(";    x       x             x        x                          \n");
}

void fight_sprite_2(){
    printw(";                                                              \n");
    printw(";                                 mmmmmmmmmmm                  \n");
    printw(";                                mmmmmmmmmmmmmm                \n");
    printw(";                             mmmmmmmmmmmmmmmmmmmm             \n");
    printw(";                             mmmmmmmmmmmmmmmmmm               \n");
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
    printw(";      xxxxxxxxx              xxxxxxxxxx                       \n");
    printw(";    xxx        xx          xxx       xxxxx                    \n");
    printw(";    xx           x        xxx           xxx                   \n");
    printw(";   xxx            x        xx             xx                  \n");
    printw(";   xx          xxxx         xxx           xx                  \n");
    printw(";   xx         xx  x        xx  x          xx                  \n");
    printw(";   xx            xx        x   xx        xx                   \n");
    printw(";   xx          xx         xx   x       xxx                    \n");
    printw(";    xxx      xxx           xx      xxxxx                      \n");
    printw(";     x       x             x        x                         \n");
}

void player_punch_1(){
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                       mmmmmmmmmmm            \n");            
    printw(";                                      mmmmmmmmmmmmmm          \n"); 
    printw(";                                    mmmmmmmmmmmmmmmmmmm       \n"); 
    printw(";                                    mmmmmmmmmmmmmmmmmm        \n"); 
    printw(";                                   mmmm       mmmmmmmm        \n");
    printw(";                                  mmx ----    ----   m        \n");
    printw(";                                   x  +++--  --+++   x        \n");
    printw(";                                   x   ++  t  +++    x        \n");
    printw(";                                   xx     tt        xx        \n");
    printw(";                                    xx   tttt      xqqqqq     \n");
    printw(";                             qqqqqqq xx   hhhhhh qqqqqq qq    \n");
    printw(";                           qq      qq xx   hhhh qqxx   qq q   \n");
    printw(";                          qqq       qq xxx     xqq      qqq   \n");
    printw(";                          qqq        q  xxxxxxxxqq      qqq   \n");
    printw(";                           qqq      qqq         qqqqqqqqqq    \n");
    printw(";                            qqqqqqqqq qq           qq    qq   \n");
    printw(";                              qqq      qq           qq    qq  \n");
    printw(";                                                              \n");
    printw(";     xxxxxxxxx              xxxxxxxxxx                        \n");
    printw(";   xxx        xx          xxx       xxxxx                     \n");
    printw(";   xx           x        xxx           xxx                    \n");
    printw(";  xxx            x        xx             xx                   \n");
    printw(";  xx          xxxx         xxx           xx                   \n");
    printw(";  xx         xx  x        xx  x          xx                   \n");
    printw(";  xx            xx        x   xx        xx                    \n");
    printw(";  xx          xx         xx   x       xxx                     \n");
    printw(";   xxx      xxx           xx      xxxxx                       \n");
    printw(";    x       x             x        x                          \n");    
}

void player_punch_2(){
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                       mmmmmmmmmmm            \n");
    printw(";                                      mmmmmmmmmmmmmm          \n");
    printw(";                                    mmmmmmmmmmmmmmmmmmm       \n");
    printw(";                                    mmmmmmmmmmmmmmmmmm        \n");
    printw(";                                   mmmm       mmmmmmmm        \n");
    printw(";                                  mmx ----    ----   m        \n");
    printw(";                                   x  +++--  --+++   x        \n");
    printw(";                                   x   ++  t  +++    x        \n");
    printw(";                                   xx     tt        xx        \n");
    printw(";                                    xx   tttt      xqqqqq     \n");
    printw(";                             qqqqqqq xx   hhhhhh qqqqqq qq    \n");
    printw(";                           qq      qq xx   hhhh qqxx   qq q   \n");
    printw(";                          qqq       qq xxx     xqq      qqq   \n");
    printw(";                          qqq        q  xxxxxxxxqq      qqq   \n");
    printw(";                           qqq      qqq         qqqqqqqqqq    \n");
    printw(";                            qqqqqqxxxxxxxxxx       qq    qq   \n");
    printw(";                              qqxxx       xxxxx     qq    qq  \n");
    printw(";                               xxx           xxx              \n");
    printw(";     xxxxxxxxx                  xx             xx             \n");
    printw(";   xxx        xx                 xxx           xx             \n");
    printw(";   xx           x               xx  x          xx             \n");
    printw(";  xxx            x              x   xx        xx              \n");
    printw(";  xx          xxxx             xx   x       xxx               \n");
    printw(";  xx         xx  x              xx      xxxxx                 \n");
    printw(";  xx            xx                x        x                  \n");
    printw(";  xx          xx                  x       xx                  \n");
    printw(";   xxx      xxx                  xx      xx                   \n");
    printw(";    x       x                   xx      xx                    \n");
}

void player_punch_3(){
    printw(";                                                              \n");
    printw(";                             .....                            \n");
    printw(";                                 ...   mmmmmmmmm.m.           \n");
    printw(";                                   .  mmmmmmmmmmmmm.. ...     \n");
    printw("; iiiii i  i i  i iii i  i   ....    mmmmmmmmmmmmmmmmmmm .     \n");
    printw("; i   i i  i ii i i   i  i       ..  mmmmmmmmmmmmmmmmmm        \n");
    printw("; iiiii i  i i ii i   iiii.....   . mmmm       mm.m.m....      \n");
    printw("; i     i  i i  i i   i  i    ..   mmx ----    ----   m....    \n");
    printw("; i     iiii i  i iii i  i ........ o  +++--...-+++   o   .    \n");
    printw(";                          ....   . o   ++  xxxxxxxxx o        \n");
    printw(";                       ..     ...  oo   xxxx   ..  xxx        \n");
    printw(";                                    oo xx       .    xxxq     \n");
    printw(";                             qqqqqqq oox               xqq    \n");
    printw(";                           qq      qqxxx               xx q   \n");
    printw(";                          qqq       x   xx              xqq   \n");
    printw(";                          qqq       x    xx             xqq   \n");
    printw(";                           qqq      x    xxx            xq    \n");
    printw(";                            qqqqqqqqqx     x           xxqq   \n");
    printw(";                              qqq     xx              xx  qq  \n");
    printw(";                                       x             xx       \n");
    printw(";     xxxxxxxxx                  i      xxx          xx        \n");
    printw(";   xxx        xx              ii   i   xxx          x         \n");
    printw(";   xx           x            i   ii    xxxxxx      xx   i     \n");
    printw(";  xxx            x            i  i     x   xxxxxxxxx    i     \n");
    printw(";  xx          xxxx          iii       x         xx   i  i     \n");
    printw(";  xx         xx  x         ii        xx         xx   i  i     \n");
    printw(";  xx            xx         i     .  xx          x   ii        \n");
    printw(";  xx          xx               ..  xx          xx        .    \n");
    printw(";   xxx      xxx                .  xx           xx        .    \n");
    printw(";    x       x                    xx            x              \n");
}

void player_punch_4(){
    printw(";                                                              \n");
    printw(";                                   .                  ....    \n");
    printw(";  ddd  ddd ddd ddd d  d  dd ddd    .   mmmmmmmmm.m.  .        \n");
    printw(";  d  d d   d   d   dd d d   d   .  .  mmmmmmmmmmmmm.. ...     \n");
    printw(";  d  d dd  dd  dd  dd d ddd dd  ..  mmmmmmmmmmmmmmmmmmm .  ...\n");
    printw(";  d  d d   d   d   d dd   d d    .  mmmmmmmmmmmmmmmmmm        \n");
    printw(";  ddd  ddd d   ddd d  d dd  ddd    mmmm       mm.m.m....      \n");
    printw(";                                qqqqqqq --    qqqqqqqq....    \n");
    printw(";     !!!!!!!!!!!!!!!!!!!!!    qq      qqq--..qq      qqq .    \n");
    printw(";                             q q        q  xxxxxxxxxxx q      \n");
    printw(";          !!!!!!!!!!!!!!     q q        xxxx          xq  ..  \n");
    printw(";                              q        xx              xq     \n");
    printw(";                               qq     ox               xqq    \n");
    printw(";                         ...     qqqqxxx               xx q   \n");
    printw(";                      ....   ..  q  x   xx              xqq   \n");
    printw(";                      .     ..   q  x    xx             xqq   \n");
    printw(";                                qq  x    xxx            xq    \n");
    printw(";                               qq  qqx     x           xxqq   \n");
    printw(";                              qq      xx              xx  qq  \n");
    printw(";                             qq        x             xx       \n");
    printw(";     xxxxxxxxx                  i      xxx          xx        \n");
    printw(";   xxx        xx              ii   i   xxx          x         \n");
    printw(";   xx           x            i   ii    xxxxxx      xx   i     \n");
    printw(";  xxx            x            i  i     x   xxxxxxxxx    i     \n");
    printw(";  xx          xxxx          iii       x         xx   i  i     \n");
    printw(";  xx         xx  x         ii        xx         xx   i  i     \n");
    printw(";  xx            xx         i     .  xx          x   ii        \n");
    printw(";  xx          xx               ..  xx          xx        .    \n");
    printw(";   xxx      xxx                .  xx           xx        .    \n");
    printw(";    x       x                    xx            x              \n");
}


void opponent_punch_1(){
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                     mmmmmmmmmmm              \n");
    printw(";                                    mmmmmmmmmmmmmm            \n");
    printw(";                                  mmmmmmmmmmmmmmmmmmm         \n");
    printw(";                                  mmmmmmmmmmmmmmmmmm          \n");
    printw(";                                 mmmm       mmmmmmmm          \n");
    printw(";                                mmx ----    ----   m          \n");
    printw(";                                 x  +++--  --+++   x          \n");
    printw(";                                 x   ++  t  +++    x          \n");
    printw(";                                 xx     tt        xx          \n");
    printw(";                                  xx   tttt      xqqqqq       \n");
    printw(";                           qqqqqqq xx   hhhhhh qqqqqq qq      \n");
    printw(";                         qq      qq xx   hhhh qqxx   qq q     \n");
    printw(";                        qqq       qq xxx     xqq      qqq     \n");
    printw(";                        qqq        q  xxxxxxxxqq      qqq     \n");
    printw(";                         qqq      qqq         qqqqqqqqqq      \n");
    printw(";                          qqqqqqqqq qq           qq    qq     \n");
    printw(";                            qqq      qq           qq    qq    \n");
    printw(";                                                              \n");
    printw(";     xxxxxxxxx              xxxxxxxxxx                        \n");
    printw(";   xxx        xx          xxx       xxxxx                     \n");
    printw(";   xx           x        xxx           xxx                    \n");
    printw(";  xxx            x        xx             xx                   \n");
    printw(";  xx          xxxx         xxx           xx                   \n");
    printw(";  xx         xx  x        xx  x          xx                   \n");
    printw(";  xx            xx        x   xx        xx                    \n");
    printw(";  xx          xx         xx   x       xxx                     \n");
    printw(";   xxx      xxx           xx      xxxxx                       \n");
    printw(";    x       x             x        x                          \n");
}
 
void opponent_punch_2(){
    printw(";                                                              \n");
    printw("; !!!!!CAUTION!!!!!                                            \n");
    printw(";     !!!!CAUTION!!!!!                mmmmmmmmmmm              \n");
    printw(";                                    mmmmmmmmmmmmmm            \n");
    printw(";                                  mmmmmmmmmmmmmmmmmmm         \n");
    printw(";                                  mmmmmmmmmmmmmmmmmm          \n");
    printw(";                                 mmmm       mmmmmmmm          \n");
    printw(";                                mmx ----    ----   m          \n");
    printw(";                                 x  +++--  --+++   x          \n");
    printw(";                                 x   ++  t  +++    x          \n");
    printw(";                                 xx     tt        xx          \n");
    printw(";                     qqqqqqqqq    xx   tttt      xqqqqq       \n");
    printw(";                   qqq        q    xx   hhhhhh qqqqqq qq      \n");
    printw(";                  qq          qqq   xx   hhhh qqxx   qq q     \n");
    printw(";                  q           qqq    xxx     xqq      qqq     \n");
    printw(";                  qqq      qqqq qq    xxxxxxxxqq      qqq     \n");
    printw(";                    qqqqqqq qq   q            qqqqqqqqqq      \n");
    printw(";                      qqqqqqq                    qq    qq     \n");
    printw(";                                                  qq    qq    \n");
    printw(";                                                              \n");
    printw(";     xxxxxxxxx              xxxxxxxxxx                        \n");
    printw(";   xxx        xx          xxx       xxxxx                     \n");
    printw(";   xx           x        xxx           xxx                    \n");
    printw(";  xxx            x        xx             xx                   \n");
    printw(";  xx          xxxx         xxx           xx                   \n");
    printw(";  xx         xx  x        xx  x          xx                   \n");
    printw(";  xx            xx        x   xx        xx                    \n");
    printw(";  xx          xx         xx   x       xxx                     \n");
    printw(";   xxx      xxx           xx      xxxxx                       \n");
    printw(";    x       x             x        x                          \n");
}  
 
void opponent_punch_3(){
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";  hh  hh  hh hhhhhhhh   hh hh        mmmmmmmmmmm              \n");
    printw(";  hh  hh  hh hhhhhhhh   hh hh       mmmmmmmmmmmmmm            \n");
    printw(";  hh  hh  hh    hh      hh hh     mmmmmmmmmmmmmmmmmmm         \n");
    printw(";  hhhhhh  hh    hh      hh hh     mmmmmmmmmmmmmmmmmm          \n");
    printw(";  hh  hh  hh    hh               mmmm       mmmmmmmm          \n");
    printw(";  hh  hh  hh    hh      hh hh   mmx ----    ----   m          \n");
    printw(";  hh  hh  hh    hh      hh hh    x  +++--  --+++   x          \n");
    printw(";      .....         .            x   ++  t  +++    x          \n");
    printw(";           ...      . .     ... .xx     tt        xx          \n");
    printw("; .......   qqqqqqqq.q..q.... .... xx   tttt      xqqqqq       \n");
    printw(";       qqqqq         ....qq...     xx   hhhhhh qqqqqq qq      \n");
    printw(";     qqq            ...  .....      xx   hhhh qqxx   qq q     \n");
    printw("; ...qq             ..    ... qqqq    xxx     xqq      qqq     \n");
    printw(";   qq......             .. q q  ..    xxxxxxxxqq      qqq     \n");
    printw(";  ...                      q q q q            qqqqqqqqqq      \n");
    printw(";   q      ..       .  ...  q q qq .      ..      qq    qq     \n");
    printw(";   q  .....    .   .     ... qqq  .......  ..     qq    qq    \n");
    printw(";   qq..      ...    .    qq .qq        . .                    \n");
    printw(";    qqq     ..      . qqqq  qq.. .xxxx    . .                 \n");
    printw(";   xxx qqqq.qqqqqqqqq.q     q      ...xxx     . .             \n");
    printw(";   xx    ..qqq        .    qq          xxx        ...         \n");
    printw(";  xxx  ..    qqqqqqqqq.qqqqx             xx                   \n");
    printw(";  xx  .       xxxx     .   xxx           xx                   \n");
    printw(";  xx         xx  x        xx  x          xx                   \n");
    printw(";  xx            xx        x   xx        xx                    \n");
    printw(";  xx          xx         xx   x       xxx                     \n");
    printw(";   xxx      xxx           xx      xxxxx                       \n");
    printw(";    x       x             x        x                          \n");
}       
     
void opponent_punch_4(){
    printw(";                                                              \n");
    printw("; ddd  ddd ddd ddd d  d  dd ddd                                \n");
    printw("; d  d d   d   d   dd d d   d         mmmmmmmmmmm              \n");
    printw("; d  d dd  dd  dd  dd d ddd dd    .. mmmmmmmmmmmmmm            \n");
    printw("; d  d d   d   d   d dd   d d    . mmmmmmmmmmmmmmmmmmm         \n");
    printw("; ddd  ddd d   ddd d  d dd  ddd    mmmmmmmmmmmmmmmmmm          \n");
    printw(";               ...               mmmm       mmmmmmmm          \n");
    printw(";   ...       ...    ...  ....   mmx ----    ----   m          \n");
    printw(";     ..     .      ..    .       o  +++--  --+++   o          \n");
    printw(";      xxxxxxxxxx qqqqqq xxxxxxxxxxx  ++  t  +++    o          \n");
    printw(";   xxxx         xq    qxx          xx   tt        oo          \n");
    printw(";  xx             xx   x             xx tttt      oqqqqq       \n");
    printw(";  x               x  x               x  hhhhhh qqqqqq qq      \n");
    printw(";  xxxx            x  x            xxxx   hhhh qq     qq q     \n");
    printw("; xx  xxx          x  x          xxx  xxo     oqq      qqq     \n");
    printw("; x     x          x  x          x     xoooooooqq      qqq     \n");
    printw("; xx             xx   xx               x       qqqqqqqqqq      \n");
    printw(";  xx           xxq    xx             xx          qq    qq     \n");
    printw(";   xxx         x qqqqqqxx          xxx   ......   qq    qq    \n");
    printw(";    xx         x qqq   xx          x      ..                  \n");
    printw(";   xxxxxxxxxxxxxx  qqqqx           xx    .  ... .             \n");
    printw(";     x        x       xxxxxxxxxxxxxxx     .      ....         \n");
    printw("; ..  x        x         xx        x        ..                 \n");
    printw("...  xx        x    ..    x        x           ..              \n");
    printw(";    x        xx     .    x        x             . ..          \n");
    printw(";    x        x     .     x        xx                ...       \n");
    printw(";    x        x    ..     x         xx                         \n");
    printw(";    x        x    .      x          x                         \n");
    printw(";    x        x           x          x                         \n");
    printw(";    x        x           x          xx                        \n");   
}

void victory(){
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";    vv     vv  vv    vvvv   vvvvvvvv  vvvv   vvvv  v      v   \n");
    printw(";     vv   vv   vv   vv  vv  vvvvvvvv vv  vv  v   v  v    v    \n");
    printw(";      v   v    vv   v          vv    v    v  v   v   v  v     \n");
    printw(";      vv vv    vv   v          vv    v    v  vvvv     vv      \n");
    printw(";       vvv     vv   vv  vv     vv    vv  vv  v  vv    v       \n");
    printw(";        v      vv    vvvv      vv     vvvv   v   vv   v       \n");
    printw(";                     .                                        \n");
    printw(";                     .       .     ..                         \n");
    printw(";           ..        .       .    ..   ...                    \n");
    printw(";             .       .                ..         ...          \n");
    printw(";     .  ..   ..  ..  .      xxxx             ....             \n");
    printw(";      ..  ..  .    .      xxxxxxxxxxx       .         ..      \n");
    printw(";       ..   ...    .     xx xxxxxxxxxx            ....  .     \n");
    printw(";        .    .     ..   xxxxxx   xxxx                         \n");
    printw(";         .     xxx     xxxx        xx    xxxxxx        ....   \n");
    printw(";             xxx xxx   xxx   oo ooo x   xx    xxx     ..      \n");
    printw(";......     xxx     x   xxx  ooo ooo x  xx       xx            \n");
    printw(";     .    xx       x   xxx     ii   x  x         xx           \n");
    printw(";         xx      xxx    xx    iiii  x  xxxxxx     x           \n");
    printw(";         x    xxxx      xxx ~~~~~~ xx      xx     x   ..      \n");
    printw(";         x      x         xxx ~~  xx        xx    xx   .......\n");
    printw(";         x      xxxx      x xxxxxxxx   xxxxxxx     x          \n");
    printw(";    ..   xx     x  xxxxx xx        xxxxx x    xx   x          \n");
    printw(";  ..      x             xx           xx           xx          \n");
    printw(";  .       xx                                     xx   .....   \n");
    printw(";           xxx                                xxxx            \n");
    printw(";              xxx          .      .      xxxxxx               \n");
}

void defeat(){
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";            DDDD    DDDD  DDDDD  DDDD    D   DDDDDDD          \n");
    printw(";            D   D   D     D      D      D D     D             \n");
    printw(";            D    D  D     D      D      D D     D             \n");
    printw(";            D    D  DDD   DDD    DDD   DDDDD    D             \n");
    printw(";            D   D   D     D      D     D   D    D             \n");
    printw(";            DDDD    DDDD  D      DDDD  D   D    D             \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                   xxxx             xxxxx                     \n");
    printw(";                 xxx  xxx          xx    xx                   \n");
    printw(";                xx      xx        xx      xx                  \n");
    printw(";                xxx xx  xx        xx xxxx  x                  \n");
    printw(";                  xxxxxx           xxxxxxxxx                  \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                         xxxxxxxxxxxxx                        \n");
    printw(";                       xxx           xxx                      \n");
    printw(";                      xx               xx                     \n");
    printw(";                     xx                 xx                    \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
    printw(";                                                              \n");
}
