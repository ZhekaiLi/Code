#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define High 50
#define Width 90 //游戏界面长宽 

int cells[High][Width]; //细胞
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
	int i, j; //循环变量
	for (i=0; i<High; i++)
	{
		for (j=0; j<Width; j++)
		{
			cells[i][j] = rand() % 2;
		}
	} 
	HideCursor();
}
void show()
{
	gotoxy(0, 0);
	int i, j; //循环变量
	for (i=0; i<High; i++)
	{
		for (j=0; j<Width; j++)
		{
			if (cells[i][j] == 1)
				printf("+");
			else
				printf(" "); 
		}
		printf("\n");
	} 
}
void updateWitoutInput()
{
	int i, j; //外循环变量
	int m, n; //内循环变量 
	int count=0; //记录周围细胞的存活个数 
	//这里选用简单模式，即不考虑边角上的点
	 
	for (i=1; i<High-1; i++)
	{
		for (j=1; j<Width-1; j++)
		{
			for (m=i-1; m<=i+1; m++)
				for (n=j-1; n<=j+1; n++)
					count+=cells[m][n]; 
			count-=cells[i][j];
			if (count == 3)
				cells[i][j] = 1;
			else if(count == 2) 
				continue;
			else
				cells[i][j] = 0;
			count = 0; 
		}
	}
	Sleep(150);	
}
void updateWithInput()
{

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
