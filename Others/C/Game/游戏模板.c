#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int x, y; //��Ϸ���泤�� 
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
	x =
	y =
	HideCursor();
}
void show()
{
	gotoxy(0, 0);
	int i, j; //ѭ������
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
