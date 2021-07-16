#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int mx, my;             //游戏界面的长宽
int x_plane, y_plane;   //飞机位置
int x_bullet, y_bullet; //子弹位置 
int x_enermy, y_enermy; //敌机位置 
int score;              //得分 
//全局变量 

void start();   //初始数据 
void show();    //显示画面 
void updateWitoutInput(); //与输入无关的更新 
void updateWithInput();   //与输入有关的更新 
void gotoxy(int x, int y); //解决刷新晃眼问题 
void HideCursor();         //解决光标闪烁问题 

int main() //主体 
{
	start();
	while (1)
    {
    	show();
    	updateWithInput();
    	updateWitoutInput();
    }
    return 0;
}

void start()
{
	mx = 40;
	my = 20;
	x_plane = mx/2;
	y_plane = my;
	x_bullet = 0;
	y_bullet = 0;
	x_enermy = rand() % 40;
	y_enermy = 0;
	score = 0;
	
	HideCursor();
}
void show()
{
	gotoxy(0, 0);
	int i, j; //循环变量 
	for (i=1; i<=my; i++)
	{
		for (j=1; j<=mx; j++)
		{
			if (i==y_plane && j==x_plane) //飞机"*" 
			{
				printf("*");
			}
			else if (i==y_bullet && j==x_bullet) //子弹"|"
			{
				printf("|");
			} 
			else if (i==y_enermy && j==x_enermy) //敌机"@" 
			{
				printf("@");
			} 
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("得分: %d", score);
}
void updateWitoutInput()
{
	if (x_enermy == x_bullet && y_enermy == y_bullet)
	{
		y_enermy = 0;
		x_enermy = rand() % 40;
		y_bullet = 0;
		x_bullet = 0;
		score++;
	}
	static int i=0; 
	int speed=6; //敌机速度，越大越慢 
	if (y_bullet >= 1) //子弹移动 
		y_bullet--;
	if (i == speed)
	{
		if (y_enermy > my) //敌机移动 
		{
			y_enermy = 0;
			x_enermy = rand() % 40;
		}
		else
		{
			y_enermy++;
		}
		i = 0;		
	}
	else
	{
		i++;
	}		
}
void updateWithInput()
{
	char input;
	if (kbhit())
	{
		input = getch();
		if (input == 'a')
		{
			if (x_plane >= 2)
				x_plane--;			
		}
		if (input == 'd')
		{
			if (x_plane <= mx-1)
				x_plane++;
		}
		if (input == ' ')
		{
			x_bullet = x_plane;
			y_bullet = y_plane-1;
		}			
	}
}
void gotoxy(int x, int y) 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); 
} 
