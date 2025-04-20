from Fighter import Fighter


class Player(Fighter):
    def __init__(self, name, health):
        super().__init__(health)

    def attack(self):
        print("Player attacks!")

    def defend(self):
        print("Player defends!")
