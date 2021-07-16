#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>

int main()
{
    int x = 4;
    int y = 10;
    int up = 0;
    int down = 20;
    int left = 0;
    int right = 50;
    
    int vx = 1;
    int vy = 1;
    
    int i, j; //ÉùÃ÷Ñ­»·±äÁ¿ 
    
    while (1)
    {
    	if (x==left || x==right)
    	{
    		vx = vx * (-1); 
		}
		if (y==up || y==down)
    	{
    		vy = vy * (-1);
    		if (y==down)
    		{
    			printf("\a"); //Åöµ×±ßÏìÁå 
			}
		}
		x += vx;
    	y += vy;
    	system("cls"); 
        for (i=0; i<y; i++)
        {
        	printf("\n");
		}
		for (j=0; j<x; j++)
		{
			printf(" ");
		}
		printf("o");
		Sleep(30);
    }
    return 0;
}
