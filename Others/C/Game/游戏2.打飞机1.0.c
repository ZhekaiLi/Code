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
    int right = 50; //�߽� 
    
    int x = 2;
    int y = 20; //�ɻ����� 
    
    int x_atk = 7;
    int y_atk = 0; //��������� 

    char input; //���Ʒɻ� 
    
    int isFired = 0; //�Ƿ����ӵ� 
    int isHitted = 0; //Ŀ���Ƿ񱻻��� 
    
    int i; //ѭ������ 

    while (1)
    {
    	system("cls"); //���� 
    	
    	if (isHitted == 0) //û��������ʾ��
    	{
    		For (x_atk, ' ');
    		printf("+\n");	
		}
    	
    	if (isFired == 1) //�ж��Ƿ��� 
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
		printf(" ***\n"); //����ɻ�λ�� 
		
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
		} //a,d�ƶ�, �ո��� 
    }
    return 0;
}

void For (int x, char y) //xΪѭ��������yΪÿ��ѭ����������� 
{
	int i;
	for (i=0; i<x; i++)
	{
		printf("%c", y); 
	} 	
}
