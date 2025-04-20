import curses
from sprites import draw_menu, draw_interactive_menu, how_to_play
from fight import Fight

def main(stdscr):
    curses.curs_set(0)
    highlight = 0
    while True:
        stdscr.clear()
        draw_menu(stdscr)
        draw_interactive_menu(stdscr, highlight)
        stdscr.refresh()
        key = stdscr.getch()
        if key == curses.KEY_UP:
            highlight = (highlight - 1) % 3
        elif key == curses.KEY_DOWN:
            highlight = (highlight + 1) % 3
        elif key == ord('\n'):
            if highlight == 0:
                fight = Fight(stdscr)
                fight.run()
            elif highlight == 1:
                how_to_play(stdscr)
            elif highlight == 2:
                break

if __name__ == "__main__":
    curses.wrapper(main)
