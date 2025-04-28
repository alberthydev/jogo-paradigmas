import curses
from sprites import draw_menu, draw_interactive_menu, how_to_play
from fight import Fight
from sound import play_music, stop_music, play_sound


def main(stdscr):
    curses.curs_set(0)
    highlight = 0
    play_music("menuSong.mp3")
    while True:
        stdscr.clear()
        draw_menu(stdscr)
        draw_interactive_menu(stdscr, highlight)
        stdscr.refresh()
        key = stdscr.getch()
        if key == curses.KEY_UP:
            highlight = (highlight - 1) % 3
            play_sound("menu2.mp3")
        elif key == curses.KEY_DOWN:
            highlight = (highlight + 1) % 3
            play_sound("menu2.mp3")
        elif key == ord('\n'):
            play_sound("Chose.mp3")
            if highlight == 0:
                stop_music()
                fight = Fight(stdscr)
                fight.run()
                play_music("menuSong.mp3")
            elif highlight == 1:
                how_to_play(stdscr)
            elif highlight == 2:
                break


if __name__ == "__main__":
    curses.wrapper(main)
