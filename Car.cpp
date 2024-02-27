#include<stdio.h>
#include<graphics.h>

int main()
{
	
	int gd=DETECT, gm;
	initgraph(&gd,&gm,NULL);
	
	for(int i=10;i<500;i=i+10)
	{
		
		delay(400);
		cleardevice();
		line(100+i,200,200+i,200);
		line(200+i,200,250+i,250);
		line(100+i,200,50+i,250);
		line(50+i,250,100+i,250);
		line(250+i,250,200+i,250);
		circle(120+i,250,15);
		ellipse(120+i,250,0,180,20,20);
		circle(180+i,250,15);
		ellipse(180+i,250,0,180,20,20);
		line(140+i,250,160+i,250);
	
	}
		
	
	closegraph();
	return 0;
}
