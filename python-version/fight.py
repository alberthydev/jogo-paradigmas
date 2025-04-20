import curses
import random
import time
from fighter import Player, Opponent
from sprites import (
    health_bar, victory, defeat,
    fight_sprite_1, fight_sprite_2,
    player_punch_1, player_punch_2, player_punch_3, player_punch_4,
    opponent_punch_1, opponent_punch_2, opponent_punch_3, opponent_punch_4
)
from sound import play_music, stop_music, play_sound

GLOBAL_TIME = 0.4

class Fight:
    def __init__(self, stdscr):
        self.stdscr = stdscr
        self.player = Player("Jogador")
        self.opponent = Opponent("Oponente")

    def animate_fight(self):
        for _ in range(2):
            self.stdscr.clear()
            fight_sprite_1(self.stdscr)
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(GLOBAL_TIME)
            self.stdscr.clear()
            fight_sprite_2(self.stdscr)
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(GLOBAL_TIME)

    def run(self):
        play_music("track1.mp3")  # Só o nome do arquivo
        # Configura o modo não bloqueante para o loop principal
        self.stdscr.nodelay(True)
        opponent_attack_timer = int(random.uniform(2, 8))
        sprite = 0
        while self.player.is_alive() and self.opponent.is_alive():
            # Alterna sprites de luta
            self.stdscr.clear()
            if sprite == 0:
                fight_sprite_1(self.stdscr)
                sprite = 1
            else:
                fight_sprite_2(self.stdscr)
                sprite = 0
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(GLOBAL_TIME)

            # Ataque do oponente se timer chegar a zero
            opponent_attack_timer -= 1
            if opponent_attack_timer <= 0:
                # Ataque do oponente, lógica de defesa será tratada no método attack
                self.opponent.attack(self.player, stdscr=self.stdscr)
                opponent_attack_timer = int(random.uniform(2, 8))

            # Input do jogador
            key = self.stdscr.getch()
            if key == ord('2'):
                opponent_defended = (random.random() < 0.3)  # 30% de chance de defesa
                self.player.attack(self.opponent, stdscr=self.stdscr, defended=opponent_defended)
                curses.flushinp()  # Limpa o buffer de entrada para evitar spam
            elif key in (ord('q'), ord('Q')):
                break
            time.sleep(0.05)
        self.stdscr.nodelay(False)
        stop_music()
        # Exibe vitória ou derrota com sprite
        if self.player.is_alive() and self.opponent.is_alive():
            # Saiu pelo 'q', não mostra vitória/derrota
            return
        self.stdscr.clear()
        if self.player.is_alive():
            victory(self.stdscr)
        else:
            defeat(self.stdscr)
        self.stdscr.refresh()
        time.sleep(GLOBAL_TIME)
