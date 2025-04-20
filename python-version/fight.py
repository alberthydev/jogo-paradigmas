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
            time.sleep(0.15)
            self.stdscr.clear()
            fight_sprite_2(self.stdscr)
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(0.15)

    def animate_player_attack(self, opponent_defended):
        if opponent_defended:
            self.stdscr.clear()
            player_punch_4(self.stdscr)  # Defesa do oponente
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(0.25)
        else:
            for sprite in [player_punch_1, player_punch_2, player_punch_3]:
                self.stdscr.clear()
                sprite(self.stdscr)
                health_bar(self.stdscr, self.player.health, self.opponent.health)
                self.stdscr.refresh()
                time.sleep(0.08)
            self.stdscr.clear()
            player_punch_4(self.stdscr)
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(0.08)

    def animate_opponent_attack(self, player_defended):
        # Mostra os dois primeiros sprites
        self.stdscr.clear()
        opponent_punch_1(self.stdscr)
        health_bar(self.stdscr, self.player.health, self.opponent.health)
        self.stdscr.refresh()
        time.sleep(0.08)
        self.stdscr.clear()
        opponent_punch_2(self.stdscr)
        health_bar(self.stdscr, self.player.health, self.opponent.health)
        self.stdscr.refresh()
        time.sleep(0.08)
        # Defesa ou acerto
        self.stdscr.clear()
        if player_defended:
            opponent_punch_4(self.stdscr)  # Defesa do player
        else:
            opponent_punch_3(self.stdscr)  # Player levou o golpe
        health_bar(self.stdscr, self.player.health, self.opponent.health)
        self.stdscr.refresh()
        time.sleep(0.18)

    def run(self):
        while self.player.is_alive() and self.opponent.is_alive():
            self.animate_fight()
            self.stdscr.addstr(13, 0, "Pressione 1 para defender, 2 para atacar, Q para sair")
            self.stdscr.refresh()
            key = self.stdscr.getch()
            if key == ord('2'):
                # Ataque do player
                opponent_defended = (random.randint(0, 2) == 0)
                self.animate_player_attack(opponent_defended)
                if not opponent_defended:
                    self.player.attack(self.opponent)
            elif key == ord('1'):
                self.player.defend()
                self.animate_fight()
            elif key in (ord('q'), ord('Q')):
                break
            # Ataque do oponente
            if random.choice([True, False]):
                # Mostra os dois primeiros sprites e espera defesa do player
                self.stdscr.nodelay(True)
                player_defended = False
                # Sprite 1
                self.stdscr.clear()
                opponent_punch_1(self.stdscr)
                health_bar(self.stdscr, self.player.health, self.opponent.health)
                self.stdscr.refresh()
                time.sleep(0.08)
                # Sprite 2 e espera defesa
                self.stdscr.clear()
                opponent_punch_2(self.stdscr)
                health_bar(self.stdscr, self.player.health, self.opponent.health)
                self.stdscr.refresh()
                start = time.time()
                while time.time() - start < 0.18:
                    k = self.stdscr.getch()
                    if k == ord('1'):
                        player_defended = True
                        break
                    time.sleep(0.01)
                self.stdscr.nodelay(False)
                # Sprite final
                self.animate_opponent_attack(player_defended)
                if not player_defended:
                    self.opponent.attack(self.player)
            else:
                self.animate_fight()
            time.sleep(0.2)
        # Exibe vitória ou derrota com sprite
        self.stdscr.clear()
        if self.player.is_alive():
            victory(self.stdscr)
        else:
            defeat(self.stdscr)
        self.stdscr.refresh()
        time.sleep(2)
