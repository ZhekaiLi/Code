#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int x, y; //游戏界面长宽 
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
	x =
	y =
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
			if ()
			else
				printf(" ");	
		}
		printf("\n");
	}
}
void updateWitoutInput()
{
	
}
void updateWithInput()
{
	char input;
	if (kbhit())
	{
		if (input == )
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
