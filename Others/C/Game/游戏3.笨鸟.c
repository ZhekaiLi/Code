#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int x, y; //��Ϸ���泤�� 
int x_bird, y_bird; //��λ��
int x_bar, y_barTop, y_barDown;   //�ϰ�λ�� 
int score; //�÷� 
 
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
	int i, j; //ѭ������
	for (i=1; i<=y; i++)
	{
		for (j=1; j<=x; j++)
		{
			if (i==y_bird && j==x_bird)
				printf("@"); //���С�� 
			else if ((i<=y_barTop || i>=y_barDown) && j==x_bar)
				printf("*"); //����ϰ��� 
			else
				printf(" ");	
		}
		printf("\n");
	}
	printf("�÷֣�%d", score);

}
void updateWitoutInput()
{
	static int i = 0;
	static int j = 0;
	int v_bird = 9; //����С�����ٶȣ�ԽСԽ��
	int v_bar = 6;   //�����ϰ������ٶȣ�ԽСԽ��
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
		//�жϵ÷� 
		if (x_bird == x_bar){
			if (y_bird>y_barTop && y_bird<y_barDown)
				score++;
			else
				exit(0);
		}	
		//���ݵ÷ּ���
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


