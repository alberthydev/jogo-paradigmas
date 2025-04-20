from abc import ABC, abstractmethod

class Fighter(ABC):
    def __init__(self, name, health=5):
        self.name = name
        self.health = health

    @abstractmethod
    def attack(self, opponent):
        pass

    @abstractmethod
    def defend(self):
        pass

    def is_alive(self):
        return self.health > 0

class Player(Fighter):
    def attack(self, opponent):
        # lógica de ataque do jogador
        opponent.health -= 1

    def defend(self):
        # lógica de defesa do jogador
        pass

class Opponent(Fighter):
    def attack(self, opponent):
        # lógica de ataque do oponente
        opponent.health -= 1

    def defend(self):
        # lógica de defesa do oponente
        pass
