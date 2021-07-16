# -*- coding: utf-8 -*-
"""
Created on Sat Nov 17 10:51:21 2018

@author: lzk12
"""

import pygame as pg
import sys
import random
import time

pg.init() 

game_window = pg.display.set_mode((1210,500))
pg.display.set_caption('接球对战')
font_score1 = pg.font.Font(None, 50)
font_score2 = pg.font.Font(None, 50)

window_color = (0, 0, 255)
ball_color = (255, 165, 0)
rect_color = (255, 0, 0)
frontier_color = (255, 255, 255)
ball1_x = random.randint(20, 580)
ball1_y = 20
ball2_x = random.randint(630, 1190)
ball2_y = 20

move1_x = 2
move1_y = 2
move2_x = 2
move2_y = 2

score1 = 0
point1 = 1
count1 = 0
score2 = 0
point2 = 1
count2 = 0

while True:
    game_window.fill(window_color)
    
    for event in pg.event.get():
        if event.type == pg.QUIT:
            sys.exit()
            
    mouse_x, mouse_y = pg.mouse.get_pos()
    pg.draw.circle(game_window, ball_color, (ball1_x, ball1_y), 20)
    pg.draw.circle(game_window, ball_color, (ball2_x, ball2_y), 20)
    pg.draw.rect(game_window, rect_color, (mouse_x, 490, 160, 10))
    pg.draw.rect(game_window, frontier_color, (600, 0, 10, 500))
    
    ball1_x += move1_x
    ball1_y += move1_y
    
    if ball1_x <= 20 or ball1_x >= 580:
        move1_x = -move1_x
    if ball2_x <= 630 or ball2_x >= 1190:
        move2_x = -move2_x
    if ball1_y <= 20:
        move1_y = -move1_y   
    if ball2_y <= 20:
        move2_y = -move2_y  
    elif mouse_x-20 < ball_x < mouse_x+180 and ball_y >= 470:
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
    elif ball_y >= 480 and (ball_x <= mouse_x-20 or ball_x >= mouse_x+180):
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

