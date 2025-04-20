import pygame
import os

pygame.mixer.init()

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
SOUNDS_DIR = os.path.join(BASE_DIR, "sounds")

def get_sound_path(filename):
    return os.path.join(SOUNDS_DIR, filename)

def play_music(filename, loop=True):
    path = get_sound_path(filename)
    pygame.mixer.music.load(path)
    pygame.mixer.music.play(-1 if loop else 0)

def stop_music():
    pygame.mixer.music.stop()

def play_sound(filename):
    path = get_sound_path(filename)
    sound = pygame.mixer.Sound(path)
    sound.play()
