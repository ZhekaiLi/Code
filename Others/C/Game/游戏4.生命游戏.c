#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define High 50
#define Width 90 //��Ϸ���泤�� 

int cells[High][Width]; //ϸ��
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
	int i, j; //ѭ������
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
	int i, j; //ѭ������
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
	int i, j; //��ѭ������
	int m, n; //��ѭ������ 
	int count=0; //��¼��Χϸ���Ĵ����� 
	//����ѡ�ü�ģʽ���������Ǳ߽��ϵĵ�
	 
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
