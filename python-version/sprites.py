import curses

def draw_menu(stdscr):
    """
    Desenha o sprite do menu principal na tela.
    """
    menu_lines = [
        "+-------------------------------------------------------------+",
        "|                                                             |",
        "|                                                             |",
        "|     ______   _______           _______  _______  _______    |",
        "|    (  ___ \\ (  ___  )|\\     /|(  ____ \\(  ____ )(  ____ \\   |",
        "|    | (   ) )| (   ) |( \\   / )| (    \\/| (    )|| (    \\/   |",
        "|    | (__/ / | |   | | \\ (_) / | (__    | (____)|| (_____    |",
        "|    |  __ (  | |   | |  ) _ (  |  __)   |     __)(_____  )   |",
        "|    | (  \\ \\ | |   | | / ( ) \\ | (      | (\\ (         ) |   |",
        "|    | )___) )| (___) |( /   \\ )| (____/\\| ) \\ \\__/\\____) |   |",
        "|    |/ \\___/ (_______)|/     \\|(_______/|/   \\__/\\_______)   |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "|                                                             |",
        "+-------------------------------------------------------------+"
    ]
    for idx, line in enumerate(menu_lines):
        stdscr.addstr(idx, 0, line)

def draw_interactive_menu(stdscr, highlight):
    """
    Desenha as opções do menu e destaca a selecionada.
    """
    options = ["1 - INICIAR", "2 - COMO JOGAR", "3 - SAIR"]
    start_y = 17
    start_x = 24
    for idx, option in enumerate(options):
        mode = curses.A_REVERSE if highlight == idx else curses.A_NORMAL
        stdscr.addstr(start_y + idx * 2, start_x, option, mode)

def how_to_play(stdscr):
    """
    Exibe o tutorial de como jogar e espera input para voltar ao menu.
    """
    tutorial_lines = [
        "+-------------------------------------------------------------+",
        "|                                                             |",
        "|                                                             |",
        "|  +-------------------------------------------------------+  |",
        "|  |                                                       |  |",
        "|  |   O JOGO E BEM SIMPLES, VOCE DEFENDE E ATACA, O SEU   |  |",
        "|  |   OPONENTE FARA O MESMO, QUANDO VOCE FOR SOFRER UMA   |  |",
        "|  |    TENTATIVA DE ATAQUE, APERTE O BOTAO DE DEFESA A    |  |",
        "|  |   TEMPO E NAO PERDERA VIDA, QUANDO VOCE ATACAR, SEU   |  |",
        "|  |    OPONENTE PODE DEFENDER TAMBEM ENTAO SEJA RAPIDO    |  |",
        "|  |          E ESTRATEGICO PARA CHEGAR A VITORIA          |  |",
        "|  |                                                       |  |",
        "|  |                                                       |  |",
        "|  |                                                       |  |",
        "|  |            1 - DEFENDE                                |  |",
        "|  |                                                       |  |",
        "|  |            2 - ATACA                                  |  |",
        "|  |                                                       |  |",
        "|  |            Q - SAIRA DE UMA LUTA JA INICIADA          |  |",
        "|  |                                                       |  |",
        "|  |                                                       |  |",
        "|  |                                                       |  |",
        "|  |                                                       |  |",
        "|  |     PARA VOLTAR AO MENU PRESSIONE QUALQUER TECLA      |  |",
        "|  |                                                       |  |",
        "|  |                                                       |  |",
        "|  +-------------------------------------------------------+  |",
        "|                                                             |",
        "|                                                             |",
        "+-------------------------------------------------------------+"
    ]
    stdscr.clear()
    for idx, line in enumerate(tutorial_lines):
        stdscr.addstr(idx, 0, line)
    stdscr.refresh()
    stdscr.getch()

def health_bar(stdscr, player_health, opponent_health):
    """
    Exibe a barra de vida do jogador e do oponente.
    """
    stdscr.addstr(0, 0, f"PLAYER: {player_health}   OPONENTE: {opponent_health}")

def fight_sprite_1(stdscr):
    """
    Desenha o primeiro sprite da luta.
    """
    lines = [
        ";                                                              ",
        ";                                         mmmmmmmmmmm          ",
        ";                                        mmmmmmmmmmmmmm        ",
        ";                                      mmmmmmmmmmmmmmmmmmm     ",
        ";                                      mmmmmmmmmmmmmmmmmm      ",
        ";                                     mmmm       mmmmmmmm      ",
        ";                                    mmx ----    ----   m      ",
        ";                                     x  +++--  --+++   x      ",
        ";                                     x   ++  t  +++    x      ",
        ";                                     xx     tt        xx      ",
        ";                                      xx   tttt      xqqqqq   ",
        ";                               qqqqqqq xx   hhhhhh qqqqqq qq  ",
        ";                             qq      qq xx   hhhh qqxx   qq q ",
        ";                            qqq       qq xxx     xqq      qqq ",
        ";                            qqq        q  xxxxxxxxqq      qqq ",
        ";                             qqq      qqq         qqqqqqqqqq  ",
        ";                              qqqqqqqqq qq           qq    qq ",
        ";                                qqq      qq           qq    qq",
        ";                                                              ",
        ";                                                              ",
        ";     xxxxxxxxx              xxxxxxxxxx                        ",
        ";   xxx        xx          xxx       xxxxx                     ",
        ";   xx           x        xxx           xxx                    ",
        ";  xxx            x        xx             xx                   ",
        ";  xx          xxxx         xxx           xx                   ",
        ";  xx         xx  x        xx  x          xx                   ",
        ";  xx            xx        x   xx        xx                    ",
        ";  xx          xx         xx   x       xxx                     ",
        ";   xxx      xxx           xx      xxxxx                       ",
        ";    x       x             x        x                          ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def fight_sprite_2(stdscr):
    """
    Desenha o segundo sprite da luta.
    """
    lines = [
        ";                                                              ",
        ";                                 mmmmmmmmmmm                  ",
        ";                                mmmmmmmmmmmmmm                ",
        ";                             mmmmmmmmmmmmmmmmmmmm             ",
        ";                             mmmmmmmmmmmmmmmmmm               ",
        ";                             mmmm       mmmmmmmm              ",
        ";                            mmx ----    ----   m              ",
        ";                             x  +++--  --+++   x              ",
        ";                             x   ++  t  +++    x              ",
        ";                             xx     tt        xx              ",
        ";                              xx   tttt      xqqqqq           ",
        ";                       qqqqqqq xx   hhhhhh qqqqqq qq          ",
        ";                     qq      qq xx   hhhh qqxx   qq q         ",
        ";                    qqq       qq xxx     xqq      qqq         ",
        ";                    qqq        q  xxxxxxxxqq      qqq         ",
        ";                     qqq      qqq         qqqqqqqqqq          ",
        ";                      qqqqqqqqq qq           qq    qq         ",
        ";                        qqq      qq           qq    qq        ",
        ";                                                              ",
        ";                                                              ",
        ";      xxxxxxxxx              xxxxxxxxxx                       ",
        ";    xxx        xx          xxx       xxxxx                    ",
        ";    xx           x        xxx           xxx                   ",
        ";   xxx            x        xx             xx                  ",
        ";   xx          xxxx         xxx           xx                  ",
        ";   xx         xx  x        xx  x          xx                  ",
        ";   xx            xx        x   xx        xx                   ",
        ";   xx          xx         xx   x       xxx                    ",
        ";    xxx      xxx           xx      xxxxx                      ",
        ";     x       x             x        x                         ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def player_punch_1(stdscr):
    """
    Sprite do primeiro estágio do ataque do jogador.
    """
    lines = [
        ";                                                              ",
        ";                                                              ",
        ";                                       mmmmmmmmmmm            ",
        ";                                      mmmmmmmmmmmmmm          ",
        ";                                    mmmmmmmmmmmmmmmmmmm       ",
        ";                                    mmmmmmmmmmmmmmmmmm        ",
        ";                                   mmmm       mmmmmmmm        ",
        ";                                  mmx ----    ----   m        ",
        ";                                   x  +++--  --+++   x        ",
        ";                                   x   ++  t  +++    x        ",
        ";                                   xx     tt        xx        ",
        ";                                    xx   tttt      xqqqqq     ",
        ";                             qqqqqqq xx   hhhhhh qqqqqq qq    ",
        ";                           qq      qq xx   hhhh qqxx   qq q   ",
        ";                          qqq       qq xxx     xqq      qqq   ",
        ";                          qqq        q  xxxxxxxxqq      qqq   ",
        ";                           qqq      qqq         qqqqqqqqqq    ",
        ";                            qqqqqqqqq qq           qq    qq   ",
        ";                              qqq      qq           qq    qq  ",
        ";                                                              ",
        ";     xxxxxxxxx              xxxxxxxxxx                        ",
        ";   xxx        xx          xxx       xxxxx                     ",
        ";   xx           x        xxx           xxx                    ",
        ";  xxx            x        xx             xx                   ",
        ";  xx          xxxx         xxx           xx                   ",
        ";  xx         xx  x        xx  x          xx                   ",
        ";  xx            xx        x   xx        xx                    ",
        ";  xx          xx         xx   x       xxx                     ",
        ";   xxx      xxx           xx      xxxxx                       ",
        ";    x       x             x        x                          ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def player_punch_2(stdscr):
    """
    Sprite do segundo estágio do ataque do jogador.
    """
    lines = [
        ";                                                              ",
        ";                                                              ",
        ";                                       mmmmmmmmmmm            ",
        ";                                      mmmmmmmmmmmmmm          ",
        ";                                    mmmmmmmmmmmmmmmmmmm       ",
        ";                                    mmmmmmmmmmmmmmmmmm        ",
        ";                                   mmmm       mmmmmmmm        ",
        ";                                  mmx ----    ----   m        ",
        ";                                   x  +++--  --+++   x        ",
        ";                                   x   ++  t  +++    x        ",
        ";                                   xx     tt        xx        ",
        ";                                    xx   tttt      xqqqqq     ",
        ";                             qqqqqqq xx   hhhhhh qqqqqq qq    ",
        ";                           qq      qq xx   hhhh qqxx   qq q   ",
        ";                          qqq       qq xxx     xqq      qqq   ",
        ";                          qqq        q  xxxxxxxxqq      qqq   ",
        ";                           qqq      qqq         qqqqqqqqqq    ",
        ";                            qqqqqqxxxxxxxxxx       qq    qq   ",
        ";                              qqxxx       xxxxx     qq    qq  ",
        ";                               xxx           xxx              ",
        ";     xxxxxxxxx                  xx             xx             ",
        ";   xxx        xx                 xxx           xx             ",
        ";   xx           x               xx  x          xx             ",
        ";  xxx            x              x   xx        xx              ",
        ";  xx          xxxx             xx   x       xxx               ",
        ";  xx         xx  x              xx      xxxxx                 ",
        ";  xx            xx                x        x                  ",
        ";  xx          xx                  x       xx                  ",
        ";   xxx      xxx                  xx      xx                   ",
        ";    x       x                   xx      xx                    ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def player_punch_3(stdscr):
    """
    Sprite do terceiro estágio do ataque do jogador.
    """
    lines = [
        ";                                                              ",
        ";                             .....                            ",
        ";                                 ...   mmmmmmmmm.m.           ",
        ";                                   .  mmmmmmmmmmmmm.. ...     ",
        "; iiiii i  i i  i iii i  i   ....    mmmmmmmmmmmmmmmmmmm .     ",
        "; i   i i  i ii i i   i  i       ..  mmmmmmmmmmmmmmmmmm        ",
        "; iiiii i  i i ii i   iiii.....   . mmmm       mm.m.m....      ",
        "; i     i  i i  i i   i  i    ..   mmx ----    ----   m....    ",
        "; i     iiii i  i iii i  i ........ o  +++--...-+++   o   .    ",
        ";                          ....   . o   ++  xxxxxxxxx o        ",
        ";                       ..     ...  oo   xxxx   ..  xxx        ",
        ";                                    oo xx       .    xxxq     ",
        ";                             qqqqqqq oox               xqq    ",
        ";                           qq      qqxxx               xx q   ",
        ";                          qqq       x   xx              xqq   ",
        ";                          qqq       x    xx             xqq   ",
        ";                           qqq      x    xxx            xq    ",
        ";                            qqqqqqqqqx     x           xxqq   ",
        ";                              qqq     xx              xx  qq  ",
        ";                                       x             xx       ",
        ";     xxxxxxxxx                  i      xxx          xx        ",
        ";   xxx        xx              ii   i   xxx          x         ",
        ";   xx           x            i   ii    xxxxxx      xx   i     ",
        ";  xxx            x            i  i     x   xxxxxxxxx    i     ",
        ";  xx          xxxx          iii       x         xx   i  i     ",
        ";  xx         xx  x         ii        xx         xx   i  i     ",
        ";  xx            xx         i     .  xx          x   ii        ",
        ";  xx          xx               ..  xx          xx        .    ",
        ";   xxx      xxx                .  xx           xx        .    ",
        ";    x       x                    xx            x              ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def player_punch_4(stdscr):
    """
    Sprite alternativo do ataque do jogador (usado em defesa).
    """
    lines = [
        ";                                                              ",
        ";                                   .                  ....    ",
        ";  ddd  ddd ddd ddd d  d  dd ddd    .   mmmmmmmmm.m.  .        ",
        ";  d  d d   d   d   dd d d   d   .  .  mmmmmmmmmmmmm.. ...     ",
        ";  d  d dd  dd  dd  dd d ddd dd  ..  mmmmmmmmmmmmmmmmmmm       ",
        ";  d  d d   d   d   d dd   d d    .  mmmmmmmmmmmmmmmmmm        ",
        ";  ddd  ddd d   ddd d  d dd  ddd    mmmmmmmmmmmmmmmmmm          ",
        ";               ...               mmmm       mmmmmmmm          ",
        ";   ...       ...    ...  ....   mmx ----    ----   m          ",
        ";     ..     .      ..    .       o  +++--  --+++   o          ",
        ";      xxxxxxxxxx qqqqqq xxxxxxxxxxx  ++  t  +++    o          ",
        ";   xxxx         xq    qxx          xx   tt        oo          ",
        ";  xx             xx   x             xx tttt      oqqqqq       ",
        ";  x               x  x               x  hhhhhh qqqqqq qq      ",
        ";  xxxx            x  x            xxxx   hhhh qq     qq q     ",
        "; xx  xxx          x  x          xxx  xxo     oqq      qqq     ",
        "; x     x          x  x          x     xoooooooqq      qqq     ",
        "; xx             xx   xx               x       qqqqqqqqqq      ",
        ";  xx           xxq    xx             xx          qq    qq     ",
        ";   xxx         x qqqqqqxx          xxx   ......   qq    qq    ",
        ";    xx         x qqq   xx          x      ..                  ",
        ";   xxxxxxxxxxxxxx  qqqqx           xx    .  ... .             ",
        ";     x        x       xxxxxxxxxxxxxxx     .      ....         ",
        "; ..  x        x         xx        x        ..                 ",
        "; ...  xx        x    ..    x        x           ..            ",
        ";    x        xx     .    x        x             . ..          ",
        ";    x        x     .     x        xx                ...       ",
        ";    x        x    ..     x         xx                         ",
        ";    x        x    .      x          x                         ",
        ";    x        x           x          x                         ",
        ";    x        x           x          xx                        ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def opponent_punch_1(stdscr):
    """
    Sprite do primeiro estágio do ataque do oponente.
    """
    lines = [
        ";                                                              ",
        ";                                                              ",
        ";                                     mmmmmmmmmmm              ",
        ";                                    mmmmmmmmmmmmmm            ",
        ";                                  mmmmmmmmmmmmmmmmmmm         ",
        ";                                  mmmmmmmmmmmmmmmmmm          ",
        ";                                 mmmm       mmmmmmmm          ",
        ";                                mmx ----    ----   m          ",
        ";                                 x  +++--  --+++   x          ",
        ";                                 x   ++  t  +++    x          ",
        ";                                 xx     tt        xx          ",
        ";                                  xx   tttt      xqqqqq       ",
        ";                           qqqqqqq xx   hhhhhh qqqqqq qq      ",
        ";                         qq      qq xx   hhhh qqxx   qq q     ",
        ";                        qqq       qq xxx     xqq      qqq     ",
        ";                        qqq        q  xxxxxxxxqq      qqq     ",
        ";                         qqq      qqq         qqqqqqqqqq      ",
        ";                          qqqqqqqqq qq           qq    qq     ",
        ";                            qqq      qq           qq    qq    ",
        ";                                                              ",
        ";     xxxxxxxxx              xxxxxxxxxx                        ",
        ";   xxx        xx          xxx       xxxxx                     ",
        ";   xx           x        xxx           xxx                    ",
        ";  xxx            x        xx             xx                   ",
        ";  xx          xxxx         xxx           xx                   ",
        ";  xx         xx  x        xx  x          xx                   ",
        ";  xx            xx        x   xx        xx                    ",
        ";  xx          xx         xx   x       xxx                     ",
        ";   xxx      xxx           xx      xxxxx                       ",
        ";    x       x             x        x                          ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def opponent_punch_2(stdscr):
    """
    Sprite do segundo estágio do ataque do oponente (com aviso).
    """
    lines = [
        ";                                                              ",
        "; !!!!!CAUTION!!!!!                                            ",
        ";     !!!!CAUTION!!!!!                mmmmmmmmmmm              ",
        ";                                    mmmmmmmmmmmmmm            ",
        ";                                  mmmmmmmmmmmmmmmmmmm         ",
        ";                                  mmmmmmmmmmmmmmmmmm          ",
        ";                                 mmmm       mmmmmmmm          ",
        ";                                mmx ----    ----   m          ",
        ";                                 x  +++--  --+++   x          ",
        ";                                 x   ++  t  +++    x          ",
        ";                                 xx     tt        xx          ",
        ";                     qqqqqqqqq    xx   tttt      xqqqqq       ",
        ";                   qqq        q    xx   hhhhhh qqqqqq qq      ",
        ";                  qq          qqq   xx   hhhh qqxx   qq q     ",
        ";                  q           qqq    xxx     xqq      qqq     ",
        ";                  qqq      qqqq qq    xxxxxxxxqq      qqq     ",
        ";                    qqqqqqq qq   q            qqqqqqqqqq      ",
        ";                      qqqqqqq                    qq    qq     ",
        ";                                                  qq    qq    ",
        ";                                                              ",
        ";     xxxxxxxxx              xxxxxxxxxx                        ",
        ";   xxx        xx          xxx       xxxxx                     ",
        ";   xx           x        xxx           xxx                    ",
        ";  xxx            x        xx             xx                   ",
        ";  xx          xxxx         xxx           xx                   ",
        ";  xx         xx  x        xx  x          xx                   ",
        ";  xx            xx        x   xx        xx                    ",
        ";  xx          xx         xx   x       xxx                     ",
        ";   xxx      xxx           xx      xxxxx                       ",
        ";    x       x             x        x                          ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def opponent_punch_3(stdscr):
    """
    Sprite do terceiro estágio do ataque do oponente.
    """
    lines = [
        ";                                                              ",
        ";                                                              ",
        ";  hh  hh  hh hhhhhhhh   hh hh        mmmmmmmmmmm              ",
        ";  hh  hh  hh hhhhhhhh   hh hh       mmmmmmmmmmmmmm            ",
        ";  hh  hh  hh    hh      hh hh     mmmmmmmmmmmmmmmmmmm         ",
        ";  hhhhhh  hh    hh      hh hh     mmmmmmmmmmmmmmmmmm          ",
        ";  hh  hh  hh    hh               mmmm       mmmmmmmm          ",
        ";  hh  hh  hh    hh      hh hh   mmx ----    ----   m          ",
        ";  hh  hh  hh    hh      hh hh    x  +++--  --+++   x          ",
        ";      .....         .            x   ++  t  +++    x          ",
        ";           ...      . .     ... .xx     tt        xx          ",
        "; .......   qqqqqqqq.q..q.... .... xx   tttt      xqqqqq       ",
        ";       qqqqq         ....qq...     xx   hhhhhh qqqqqq qq      ",
        ";     qqq            ...  .....      xx   hhhh qqxx   qq q     ",
        "; ...qq             ..    ... qqqq    xxx     xqq      qqq     ",
        ";   qq......             .. q q  ..    xxxxxxxxqq      qqq     ",
        ";  ...                      q q q q            qqqqqqqqqq      ",
        ";   q      ..       .  ...  q q qq .      ..      qq    qq     ",
        ";   q  .....    .   .     ... qqq  .......  ..     qq    qq    ",
        ";   qq..      ...    .    qq .qq        . .                    ",
        ";    qqq     ..      . qqqq  qq.. .xxxx    . .                 ",
        ";   xxx qqqq.qqqqqqqqq.q     q      ...xxx     . .             ",
        ";   xx    ..qqq        .    qq          xxx        ...         ",
        ";  xxx  ..    qqqqqqqqq.qqqqx             xx                   ",
        ";  xx  .       xxxx     .   xxx           xx                   ",
        ";  xx         xx  x        xx  x          xx                   ",
        ";  xx            xx        x   xx        xx                    ",
        ";  xx          xx         xx   x       xxx                     ",
        ";   xxx      xxx           xx      xxxxx                       ",
        ";    x       x             x        x                          ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def opponent_punch_4(stdscr):
    """
    Sprite alternativo do ataque do oponente (usado em defesa).
    """
    lines = [
        ";                                                              ",
        "; ddd  ddd ddd ddd d  d  dd ddd                                ",
        "; d  d d   d   d   dd d d   d         mmmmmmmmmmm              ",
        "; d  d dd  dd  dd  dd d ddd dd    .. mmmmmmmmmmmmmm            ",
        "; d  d d   d   d   d dd   d d    . mmmmmmmmmmmmmmmmmmm         ",
        "; ddd  ddd d   ddd d  d dd  ddd    mmmmmmmmmmmmmmmmmm          ",
        ";               ...               mmmm       mmmmmmmm          ",
        ";   ...       ...    ...  ....   mmx ----    ----   m          ",
        ";     ..     .      ..    .       o  +++--  --+++   o          ",
        ";      xxxxxxxxxx qqqqqq xxxxxxxxxxx  ++  t  +++    o          ",
        ";   xxxx         xq    qxx          xx   tt        oo          ",
        ";  xx             xx   x             xx tttt      oqqqqq       ",
        ";  x               x  x               x  hhhhhh qqqqqq qq      ",
        ";  xxxx            x  x            xxxx   hhhh qq     qq q     ",
        "; xx  xxx          x  x          xxx  xxo     oqq      qqq     ",
        "; x     x          x  x          x     xoooooooqq      qqq     ",
        "; xx             xx   xx               x       qqqqqqqqqq      ",
        ";  xx           xxq    xx             xx          qq    qq     ",
        ";   xxx         x qqqqqqxx          xxx   ......   qq    qq    ",
        ";    xx         x qqq   xx          x      ..                  ",
        ";   xxxxxxxxxxxxxx  qqqqx           xx    .  ... .             ",
        ";     x        x       xxxxxxxxxxxxxxx     .      ....         ",
        "; ..  x        x         xx        x        ..                 ",
        "; ...  xx        x    ..    x        x           ..            ",
        ";    x        xx     .    x        x             . ..          ",
        ";    x        x     .     x        xx                ...       ",
        ";    x        x    ..     x         xx                         ",
        ";    x        x    .      x          x                         ",
        ";    x        x           x          x                         ",
        ";    x        x           x          xx                        ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def victory(stdscr):
    """
    Exibe o sprite de vitória.
    """
    lines = [
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
        ";    vv     vv  vv    vvvv   vvvvvvvv  vvvv   vvvv  v      v   ",
        ";     vv   vv   vv   vv  vv  vvvvvvvv vv  vv  v   v  v    v    ",
        ";      v   v    vv   v          vv    v    v  v   v   v  v     ",
        ";      vv vv    vv   v          vv    v    v  vvvv     vv      ",
        ";       vvv     vv   vv  vv     vv    vv  vv  v  vv    v       ",
        ";        v      vv    vvvv      vv     vvvv   v   vv   v       ",
        ";                     .                                        ",
        ";                     .       .     ..                         ",
        ";           ..        .       .    ..   ...                    ",
        ";             .       .                ..         ...          ",
        ";     .  ..   ..  ..  .      xxxx             ....             ",
        ";      ..  ..  .    .      xxxxxxxxxxx       .         ..      ",
        ";       ..   ...    .     xx xxxxxxxxxx            ....  .     ",
        ";        .    .     ..   xxxxxx   xxxx                         ",
        ";         .     xxx     xxxx        xx    xxxxxx        ....   ",
        ";             xxx xxx   xxx   oo ooo x   xx    xxx     ..      ",
        ";......     xxx     x   xxx  ooo ooo x  xx       xx            ",
        ";     .    xx       x   xxx     ii   x  x         xx           ",
        ";         xx      xxx    xx    iiii  x  xxxxxx     x           ",
        ";         x    xxxx      xxx ~~~~~~ xx      xx     x   ..      ",
        ";         x      x         xxx ~~  xx        xx    xx   .......",
        ";         x      xxxx      x xxxxxxxx   xxxxxxx     x          ",
        ";    ..   xx     x  xxxxx xx        xxxxx x    xx   x          ",
        ";  ..      x             xx           xx           xx          ",
        ";  .       xx                                     xx   .....   ",
        ";           xxx                                xxxx            ",
        ";              xxx          .      .      xxxxxx               ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)

def defeat(stdscr):
    """
    Exibe o sprite de derrota.
    """
    lines = [
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
        ";            DDDD    DDDD  DDDDD  DDDD    D   DDDDDDD          ",
        ";            D   D   D     D      D      D D     D             ",
        ";            D    D  D     D      D      D D     D             ",
        ";            D    D  DDD   DDD    DDD   DDDDD    D             ",
        ";            D   D   D     D      D     D   D    D             ",
        ";            DDDD    DDDD  D      DDDD  D   D    D             ",
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
        ";                   xxxx             xxxxx                     ",
        ";                 xxx  xxx          xx    xx                   ",
        ";                xx      xx        xx      xx                  ",
        ";                xxx xx  xx        xx xxxx  x                  ",
        ";                  xxxxxx           xxxxxxxxx                  ",
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
        ";                         xxxxxxxxxxxxx                        ",
        ";                       xxx           xxx                      ",
        ";                      xx               xx                     ",
        ";                     xx                 xx                    ",
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
        ";                                                              ",
    ]
    for idx, line in enumerate(lines):
        stdscr.addstr(idx, 0, line)
