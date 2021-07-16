# -*- coding: utf-8 -*-
"""
Name: tic-tac-toe game
Edition: 1.1
Author: Li

Update log:
Version 1.1: add interface to show the winner (def winner())

Plan log:
Version 1.2: add buttons to restart and end the game (def button_restart() button_end())
Version 2.0: 1.add human-robot-fighting pattern
             2.optimize the interface
"""
import pygame as pg
import sys
import random
import time
import numpy as np

def main():

    pg.init()
    game_window = pg.display.set_mode((600, 600))
    pg.display.set_caption('tic-tac-toe')

    window_color = (0, 0, 0)
    circle_color, cross_color, line_color  = (255, 255, 255) #元素颜色
    font_score = pg.font.Font(None, 50) #定义文字
    game_table = [[5,5,5],[5,5,5],[5,5,5]]
    #游戏界面的代码表示：5（没有被占用），1（被叉占用），0（被圈占用）

    inf = 0 #表示圈先下棋
    win = 0 #表示游戏正在进行

    game_window.fill(window_color)  # 设置窗口颜色
    draw_initial(game_window, line_color)  # 画分割线
    while True:
        for event in pg.event.get(): #防止闪退
            if event.type == pg.QUIT:
                exit()
            elif pg.mouse.get_pressed()[0] == 1:
                mouse_x, mouse_y = pg.mouse.get_pos()
                mouse_x_abstract = pos_abstract(mouse_x)
                mouse_y_abstract = pos_abstract(mouse_y)
                    #对应九宫格九个位置
                game_table = game_table_update(game_table, inf, mouse_x_abstract, mouse_y_abstract)
                    #更新棋盘
                draw(game_window, cross_color, circle_color, inf, mouse_x_abstract, mouse_y_abstract)
                    #画图
                inf = not inf
                    #下完一次后交换对手，0变1，1变0

        win = end_or_continue(game_table) #更新输赢状态
        if win == 1:
            winner(game_window, inf)
            pg.display.update()
            time.sleep(2.012)
            pg.quit()
            #如果满足胜利判断条件，结束游戏

        pg.display.update() #使得程序正常运行的关键语句
        time.sleep(0.012)

def pos_abstract(pos): #用于生成位置代码（123分别代表600个像素点中的三段）
    if 0 <= pos < 200:
        return 0
    if 200 <= pos < 400:
        return 1
    if 400 <= pos < 600:
        return 2

def pos_off_abstact(pos): #用于将位置代码转化为具体坐标用于画图
    if pos == 0:
        return 100
    if pos == 1:
        return 300
    if pos == 2:
        return 500

def game_table_update(game_table, inf, pos_x, pos_y): #用于更新游戏状态
    if inf == 1:
        game_table[pos_x][pos_y] = 1
    elif inf == 0:
        game_table[pos_x][pos_y] = 0
    return game_table

def end_or_continue(game_table): #判断是否已经分出胜负：1游戏结束；0继续进行
    game_table_array = np.array(game_table)
    value_x = np.sum(game_table_array, 1)
    value_y = np.sum(game_table_array, 0)
    for i in range(len(value_x)):
        if value_x[i] == 0 or value_x[i] == 3 or value_y[i] == 0 or value_y[i] == 3: #行列相等
            return 1
        elif game_table[0][0] == 0 and game_table[1][1] == 0 and game_table[2][2] == 0: #斜线相等，待优化
            return 1
        elif game_table[0][0] == 1 and game_table[1][1] == 1 and game_table[2][2] == 1:
            return 1
        elif game_table[0][2] == 0 and game_table[1][1] == 0 and game_table[2][0] == 0:
            return 1
        elif game_table[0][2] == 1 and game_table[1][1] == 1 and game_table[2][0] == 1:
            return 1
        else:
            return 0

def winner(game_window, inf):
    font_score = pg.font.Font(None, 80)
    if inf == 1:
        my_text_score = font_score.render('Circle win!', False, (255, 255, 255))  # True会平滑一些
    else:
        my_text_score = font_score.render('Rectangular win!', False, (255, 255, 255))
    game_window.fill((0, 0, 0)) #清屏
    game_window.blit(my_text_score, (0, 0))
    pass

def draw(game_window, cross_color, circle_color, inf, pos_x, pos_y): #画圈和叉（接受符号信息inf（1叉0圈），位置信息pos）
    if inf == 1:
        pg.draw.rect(game_window, cross_color, (pos_off_abstact(pos_x)-50,pos_off_abstact(pos_y)-50, 100, 100))
        pass
    elif inf == 0:
        pg.draw.circle(game_window, circle_color, (pos_off_abstact(pos_x),pos_off_abstact(pos_y)), 50)
        pass

def draw_initial(game_window, line_color):  #画棋盘分割线
    pg.draw.rect(game_window, line_color, (0, 200, 600, 10))
    pg.draw.rect(game_window, line_color, (0, 400, 600, 10))
    pg.draw.rect(game_window, line_color, (200, 0, 10, 600))
    pg.draw.rect(game_window, line_color, (400, 0, 10, 600))
    pass

if __name__ == "__main__":
    main()