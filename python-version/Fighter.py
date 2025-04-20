from abc import ABC, abstractmethod


class Fighter(ABC):
    def __init__(self, health):
        self.__health = health

    @abstractmethod
    def attack():
        pass

    @abstractmethod
    def defend():
        pass

    def get_health(self):
        return self.__health

    def set_health(self, health):
        self.__health = health
