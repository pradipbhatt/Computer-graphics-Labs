#include <graphics.h>
#include <iostream>

class MidpointCircle 
{
private:
    int x_center, y_center, radius;

public:
    MidpointCircle(int x, int y, int r) : x_center(x), y_center(y), radius(r) {}

    void drawCircle() 
	{
        int x = radius;
        int y = 0;
        int p = 1 - radius;

        while (x > y) 
		{
            putPixel(x + x_center, y + y_center);
            putPixel(y + x_center, x + y_center);
            putPixel(-y + x_center, x + y_center);
            putPixel(-x + x_center, y + y_center);
            putPixel(-x + x_center, -y + y_center);
            putPixel(-y + x_center, -x + y_center);
            putPixel(y + x_center, -x + y_center);
            putPixel(x + x_center, -y + y_center);

            y++;

            if (p <= 0)
            {
            	p = p + 2 * y + 1;
			}   
            else 
			{
                x--;
                p = p + 2 * y - 2 * x + 1;
            }
        }

    }

private:
    void putPixel(int x, int y) 
	{
        putpixel(x, y, WHITE);
    }
};

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x=200, y=300, r=80;
    MidpointCircle circle(x, y, r);
    circle.drawCircle();
    delay(5000);
    closegraph();
    return 0;
}

