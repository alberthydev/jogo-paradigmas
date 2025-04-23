from abc import ABC, abstractmethod
import time
from sprites import (
    health_bar,
    player_punch_1, player_punch_2, player_punch_3, player_punch_4,
    opponent_punch_1, opponent_punch_2, opponent_punch_3, opponent_punch_4
)
from sound import play_sound

GLOBAL_TIME = 0.4

class Fighter(ABC):
    def __init__(self, name, health=5):
        self.name = name
        self.health = health

    @abstractmethod
    def attack(self, opponent, stdscr=None, defended=False):
        pass

    @abstractmethod
    def defend(self, stdscr=None):
        pass

    def is_alive(self):
        return self.health > 0

class Player(Fighter):
    def attack(self, opponent, stdscr=None, defended=False):
        self.animate_attack(opponent, stdscr, defended)
        if defended:
            play_sound("punchTest1.mp3")
            opponent.defend(stdscr)
        else:
            play_sound("defense.mp3")
            opponent.health -= 1

    def defend(self, stdscr=None):
        # lógica de defesa do jogador
        pass

    def animate_attack(self, opponent, stdscr, defended):
        if stdscr is None:
            return
        sprites = [player_punch_1, player_punch_2, player_punch_4] if defended else [player_punch_1, player_punch_2, player_punch_3]
        for sprite in sprites:
            stdscr.clear()
            sprite(stdscr)
            health_bar(stdscr, self.health, opponent.health)
            stdscr.refresh()
            time.sleep(GLOBAL_TIME)
        if not defended:
            health_bar(stdscr, self.health, opponent.health)
            stdscr.refresh()
            time.sleep(GLOBAL_TIME)

class Opponent(Fighter):
    def attack(self, opponent, stdscr=None, defended=None):
        player_defended = False
        if stdscr is not None:
            # opponent_punch_1
            stdscr.clear()
            opponent_punch_1(stdscr)
            health_bar(stdscr, self.health, opponent.health)
            stdscr.refresh()
            time.sleep(GLOBAL_TIME)

            # opponent_punch_2 + input defesa
            stdscr.clear()
            opponent_punch_2(stdscr)
            health_bar(stdscr, self.health, opponent.health)
            stdscr.refresh()
            import curses
            curses.flushinp()
            start = time.time()
            while time.time() - start < GLOBAL_TIME:
                k = stdscr.getch()
                if k == ord('1'):
                    player_defended = True
                    break
                time.sleep(0.01)
        else:
            player_defended = False if defended is None else defended

        self.animate_attack(opponent, stdscr, player_defended)
        if player_defended:
            play_sound("punchTest1.mp3")
            opponent.defend(stdscr)
        else:
            play_sound("defense.mp3")
            opponent.health -= 1

    def defend(self, stdscr=None):
        # lógica de defesa do oponente
        pass

    def animate_attack(self, opponent, stdscr, defended):
        if stdscr is None:
            return
        stdscr.clear()
        # opponent_punch_3 ou 4 já foi animado no attack, não precisa repetir aqui
        if defended:
            opponent_punch_4(stdscr)
        else:
            opponent_punch_3(stdscr)
        health_bar(stdscr, self.health, opponent.health)
        stdscr.refresh()
        time.sleep(GLOBAL_TIME)
