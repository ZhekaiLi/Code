# -*- coding: utf-8 -*-
"""
Created on Sat Nov 17 10:51:21 2018

@author: lzk12
"""

import pygame as pg
import sys
import random
import time
from pygame.locals import *


pg.init() 

game_window = pg.display.set_mode((600,500))
pg.display.set_caption('接球')
font_score = pg.font.Font(None, 50)
font_highest_score = pg.font.Font(None, 30)
window_color = (0, 0, 255)
ball_color = (255, 165, 0)
rect_color = (255, 0, 0)
ball_x = random.randint(20, 580)
ball_y = 20
rect_x = 0

move_x = 2
move_y = 2

score = 0
point = 1
count = 0
ropen = open(r'C:\Users\lzk12\Desktop\PY\file_score.txt','r+')
highest_score = int(ropen.read())
ropen.close()
while True:
    game_window.fill(window_color)
    
    for event in pg.event.get():
        if event.type == pg.QUIT:
            sys.exit()
            
    for event in pg.event.get(): 
        if event.type== pg.KEYDOWN: 
            if event.key==pg.K_LEFT and rect_x < 440: 
                rect_x += 110
            if event.key==pg.K_RIGHT and rect_x > 0: 
                rect_x -= 110
        if event.type==pg.KEYUP: 
            if event.key==pg.K_LEFT: 
                continue
            if event.key==pg.K_RIGHT: 
                continue
    pg.draw.circle(game_window, ball_color, (ball_x, ball_y), 20)
    pg.draw.rect(game_window, rect_color, (rect_x, 490, 160, 10))
    
    ball_x += move_x
    ball_y += move_y
    
    if ball_x <= 20 or ball_x >= 580:
        move_x = -move_x
    if ball_y <= 20:
        move_y = -move_y   
    elif rect_x-20 < ball_x < rect_x+180 and ball_y >= 470:
        move_y = -move_y
        score += point
        count += 1
        if count == 3:
            count = 0
            point += 1 #point的迭代
            if move_x > 0:
                move_x += 1
            else:
                move_x -= 1
            move_y -= 1 
    #反弹
    elif ball_y >= 480 and (ball_x <= rect_x-20 or ball_x >= rect_x+180):
        if score > highest_score:
            highest_score = score
            wopen = open(r'C:\Users\lzk12\Desktop\PY\file_score.txt','w')
            wopen.write(str(highest_score))
            wopen.close()
        break
    
    #判断退出条件
    my_text_score = font_score.render('Score: '+str(score), False, (255, 255, 255)) #True会平滑一些
    my_text_highest_score = font_highest_score.render('Highest Score: '+str(highest_score), False, (255, 255, 255))
    game_window.blit(my_text_score, (400, 30))
    game_window.blit(my_text_highest_score, (400, 90))
    
    pg.display.update()
    
    time.sleep(0.012)

