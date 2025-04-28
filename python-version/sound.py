import pygame
import os

pygame.mixer.init()

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
SOUNDS_DIR = os.path.join(BASE_DIR, "sounds")

def get_sound_path(filename):
    """
    Retorna o caminho absoluto do arquivo de som.
    """
    return os.path.join(SOUNDS_DIR, filename)

def play_music(filename, loop=True):
    """
    Toca música de fundo, em loop se especificado.
    """
    path = get_sound_path(filename)
    pygame.mixer.music.load(path)
    pygame.mixer.music.play(-1 if loop else 0)

def stop_music():
    """
    Para a música de fundo.
    """
    pygame.mixer.music.stop()

def play_sound(filename):
    """
    Toca um efeito sonoro.
    """
    path = get_sound_path(filename)
    sound = pygame.mixer.Sound(path)
    sound.play()
