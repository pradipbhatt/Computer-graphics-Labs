#include<graphics.h>  
#include<conio.h>  
int main()  
{  
    int gd=DETECT,gm;  
    initgraph (&gd,&gm,NULL);  
    
    // Replace these values with your desired endpoints
    int x1 = 100, y1 = 100, x2 = 300, y2 = 200;
    int dx = x2-x1;
	int dy = y2-y1;
	int steps;
	if (abs(dx) > abs(dy))
		{ 
			steps = abs(dx);
		}
		
	else
		{
			steps = abs(dy);
		}
   	
	float x_increment = (float)dx / (float)steps;
    float y_increment = (float)dy / (float)steps;
	float x = x1, y = y1;
	

    for(int i=0; i < steps; i++)
	{
   		x = x + x_increment;
   		y = y + y_increment;
   		putpixel(x, y, WHITE);
	}
    delay(20000);
	closegraph();
	return 0;
}  
