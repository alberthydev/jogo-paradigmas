from Fighter import Fighter


class Opponent(Fighter):
    def __init__(self, name, health):
        super().__init__(health)

    def attack(self):
        print("Opponent attacks!")

    def defend(self):
        print("Opponent defends!")
