#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int x, y; //游戏界面长宽 
int x_bird, y_bird; //鸟位置
int x_bar, y_barTop, y_barDown;   //障碍位置 
int score; //得分 
 
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
	x = 30;
	y = 20;
	x_bird = x/2;
	y_bird = y/2;
	x_bar = x;
	y_barTop = rand()%13 + 1;
	y_barDown = y_barTop + 6;
	score = 0;
	HideCursor();
}
void show()
{
	gotoxy(0, 0);
	int i, j; //循环变量
	for (i=1; i<=y; i++)
	{
		for (j=1; j<=x; j++)
		{
			if (i==y_bird && j==x_bird)
				printf("@"); //输出小鸟 
			else if ((i<=y_barTop || i>=y_barDown) && j==x_bar)
				printf("*"); //输出障碍物 
			else
				printf(" ");	
		}
		printf("\n");
	}
	printf("得分：%d", score);

}
void updateWitoutInput()
{
	static int i = 0;
	static int j = 0;
	int v_bird = 9; //控制小鸟降落速度，越小越快
	int v_bar = 6;   //控制障碍左移速度，越小越快
	if (i==v_bird){
		y_bird++;
		i=0;
	}
	else
		i++; 
	if (j==v_bar){
		x_bar--;
		j=0;
		if (x_bar == 0){
			x_bar = x;
			y_barTop = rand()%13 + 1;
			y_barDown = y_barTop + 6;
		}
		//判断得分 
		if (x_bird == x_bar){
			if (y_bird>y_barTop && y_bird<y_barDown)
				score++;
			else
				exit(0);
		}	
		//根据得分加速
		if (score%3==0 && score>0 && v_bar>0)
			v_bar--; 
	}
	else
		j++; 
		

}
void updateWithInput()
{
	char input;
	if (kbhit())
	{
		input = getch();
		if (input == ' ')
			y_bird-=3;
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


