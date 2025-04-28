from abc import ABC, abstractmethod
import time
from sprites import (
    health_bar,
    player_punch_1, player_punch_2, player_punch_3, player_punch_4,
    opponent_punch_1, opponent_punch_2, opponent_punch_3, opponent_punch_4
)
from sound import play_sound

GLOBAL_TIME = 0.4  # Tempo global de animação


class Fighter(ABC):
    def __init__(self, name, health=5):
        """
        Classe abstrata base para lutadores, define nome e vida.
        """
        self.name = name
        self.health = health

    @abstractmethod
    def attack(self, opponent, stdscr=None, defended=False):
        """
        Método abstrato de ataque, deve ser implementado nas subclasses.
        """
        pass

    def is_alive(self):
        """
        Retorna True se o lutador ainda está vivo (vida > 0).
        """
        return self.health > 0


class Player(Fighter):
    def attack(self, opponent, stdscr=None, defended=False):
        """
        Realiza ataque do jogador, anima e aplica dano se não defendido.
        """
        self.animate_attack(opponent, stdscr, defended)
        if defended:
            play_sound("Punch.mp3")
        else:
            play_sound("Defense.mp3")
            opponent.health -= 1

    def animate_attack(self, opponent, stdscr, defended):
        """
        Anima o ataque do jogador usando diferentes sprites.
        """
        if stdscr is None:
            return
        sprites = [player_punch_1, player_punch_2, player_punch_4] if defended else [
            player_punch_1, player_punch_2, player_punch_3]
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
        """
        Realiza ataque do oponente, permite defesa do jogador se stdscr não for None.
        """
        player_defended = False
        if stdscr is not None:
            # Animação do ataque do oponente e input para defesa do jogador
            stdscr.clear()
            opponent_punch_1(stdscr)
            health_bar(stdscr, opponent.health, self.health)
            stdscr.refresh()
            time.sleep(GLOBAL_TIME)

            stdscr.clear()
            opponent_punch_2(stdscr)
            health_bar(stdscr, opponent.health, self.health)
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
            play_sound("Punch.mp3")
        else:
            play_sound("Defense.mp3")
            opponent.health -= 1

    def animate_attack(self, opponent, stdscr, defended):
        """
        Anima o ataque do oponente usando diferentes sprites.
        """
        if stdscr is None:
            return
        stdscr.clear()
        if defended:
            opponent_punch_4(stdscr)
        else:
            opponent_punch_3(stdscr)
        health_bar(stdscr, opponent.health, self.health)
        stdscr.refresh()
        time.sleep(GLOBAL_TIME)
