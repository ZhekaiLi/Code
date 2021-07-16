#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int mx, my;             //��Ϸ����ĳ���
int x_plane, y_plane;   //�ɻ�λ��
int x_bullet, y_bullet; //�ӵ�λ�� 
int x_enermy, y_enermy; //�л�λ�� 
int score;              //�÷� 
//ȫ�ֱ��� 

void start();   //��ʼ���� 
void show();    //��ʾ���� 
void updateWitoutInput(); //�������޹صĸ��� 
void updateWithInput();   //�������йصĸ��� 
void gotoxy(int x, int y); //���ˢ�»������� 
void HideCursor();         //��������˸���� 

int main() //���� 
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
	int i, j; //ѭ������ 
	for (i=1; i<=my; i++)
	{
		for (j=1; j<=mx; j++)
		{
			if (i==y_plane && j==x_plane) //�ɻ�"*" 
			{
				printf("*");
			}
			else if (i==y_bullet && j==x_bullet) //�ӵ�"|"
			{
				printf("|");
			} 
			else if (i==y_enermy && j==x_enermy) //�л�"@" 
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
	printf("�÷�: %d", score);
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
	int speed=6; //�л��ٶȣ�Խ��Խ�� 
	if (y_bullet >= 1) //�ӵ��ƶ� 
		y_bullet--;
	if (i == speed)
	{
		if (y_enermy > my) //�л��ƶ� 
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
