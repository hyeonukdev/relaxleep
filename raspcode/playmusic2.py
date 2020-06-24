import pygame
from pygame import mixer
import time
import sys

pygame.init()

mixer.init()
mixer.music.load('/home/pi/sleepwell.mp3')
run = True

while run:
  mixer.music.play()
  keys = pygame.key.get_pressed()
  if keys[pygame.K_ESCAPE]:
    print('잘자라우리아가 재생')
  time.sleep(1000)
  sys.exit()
