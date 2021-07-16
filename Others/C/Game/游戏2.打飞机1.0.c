#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void For (int x, char y);

int main()
{
    int up = 0;
    int down = 20;
    int left = 0;
    int right = 50; //边界 
    
    int x = 2;
    int y = 20; //飞机坐标 
    
    int x_atk = 7;
    int y_atk = 0; //射击靶坐标 

    char input; //控制飞机 
    
    int isFired = 0; //是否发射子弹 
    int isHitted = 0; //目标是否被击中 
    
    int i; //循环变量 

    while (1)
    {
    	system("cls"); //清屏 
    	
    	if (isHitted == 0) //没击中则显示靶
    	{
    		For (x_atk, ' ');
    		printf("+\n");	
		}
    	
    	if (isFired == 1) //判断是否发射 
		{
			for (i=0; i<y; i++)
			{
				For (x, ' ');
				printf("  |\n");
			}
			if (x+2 == x_atk)
			{
				isHitted = 1;
			}
			isFired = 0;
		}
		else
		{
			For (y, '\n');
		}
		For (x, ' ');
		printf("  *\n");
		For (x, ' ');
		printf("*****\n");
		For (x, ' ');
		printf(" ***\n"); //输出飞机位置 
		
		input = getch();
		switch (input)
		{
			case 'd':
				x += 1;
				break;
			case 'a':
				x -= 1;
				break;
			case ' ':
				isFired = 1;
				break;
		} //a,d移动, 空格发射 
    }
    return 0;
}

void For (int x, char y) //x为循环次数，y为每次循环输出的内容 
{
	int i;
	for (i=0; i<x; i++)
	{
		printf("%c", y); 
	} 	
}
