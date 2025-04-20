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
            time.sleep(0.5)
            self.stdscr.clear()
            fight_sprite_2(self.stdscr)
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(0.5)

    def animate_player_attack(self, opponent_defended):
        if opponent_defended:
            self.stdscr.clear()
            player_punch_4(self.stdscr)  # Defesa do oponente
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(0.5)
        else:
            for sprite in [player_punch_1, player_punch_2, player_punch_3]:
                self.stdscr.clear()
                sprite(self.stdscr)
                health_bar(self.stdscr, self.player.health, self.opponent.health)
                self.stdscr.refresh()
                time.sleep(0.5)
            
            self.stdscr.clear()
            health_bar(self.stdscr, self.player.health, self.opponent.health)
            self.stdscr.refresh()
            time.sleep(0.5)

    def animate_opponent_attack(self):
        # Captura defesa do player durante o segundo sprite
        player_defended = False
        self.stdscr.clear()
        opponent_punch_1(self.stdscr)
        health_bar(self.stdscr, self.player.health, self.opponent.health)
        self.stdscr.refresh()
        time.sleep(0.5)
        self.stdscr.clear()
        opponent_punch_2(self.stdscr)
        health_bar(self.stdscr, self.player.health, self.opponent.health)
        self.stdscr.refresh()
        # Limpa o buffer antes de capturar o input para evitar defesa automática
        curses.flushinp()
        start = time.time()
        while time.time() - start < 0.5:
            k = self.stdscr.getch()
            if k == ord('1'):
                player_defended = True
                break
            time.sleep(0.01)
        # Defesa ou acerto
        self.stdscr.clear()
        if player_defended:
            opponent_punch_4(self.stdscr)  # Defesa do player
        else:
            opponent_punch_3(self.stdscr)  # Player levou o golpe
        health_bar(self.stdscr, self.player.health, self.opponent.health)
        self.stdscr.refresh()
        time.sleep(0.5)
        return player_defended

    def run(self):
        # Configura o modo não bloqueante para o loop principal
        self.stdscr.nodelay(True)
        opponent_attack_timer = random.randint(3, 8)
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
            time.sleep(0.5)

            # Ataque do oponente se timer chegar a zero
            opponent_attack_timer -= 1
            if opponent_attack_timer <= 0:
                # Chama animação e captura defesa do player
                player_defended = self.animate_opponent_attack()
                if not player_defended:
                    self.opponent.attack(self.player)
                opponent_attack_timer = random.randint(3, 8)

            # Input do jogador (não bloqueante)
            key = self.stdscr.getch()
            if key == ord('2'):
                opponent_defended = (random.randint(0, 2) == 0)
                self.animate_player_attack(opponent_defended)
                if not opponent_defended:
                    self.player.attack(self.opponent)
            elif key == ord('1'):
                self.player.defend()
            elif key in (ord('q'), ord('Q')):
                break
            time.sleep(0.05)
        self.stdscr.nodelay(False)
        # Exibe vitória ou derrota com sprite
        self.stdscr.clear()
        if self.player.is_alive():
            victory(self.stdscr)
        else:
            defeat(self.stdscr)
        self.stdscr.refresh()
        time.sleep(2)
