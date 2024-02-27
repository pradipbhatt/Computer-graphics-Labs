#include <stdio.h>
#include <graphics.h>

// Function to calculate the point on a quadratic Bezier curve
void bezier(float t, int* x, int* y, int* ctrlPoints) 
{
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    // Bezier curve formula for x and y coordinates
    *x = uuu * ctrlPoints[0] + 3 * uu * t * ctrlPoints[2] + 3 * u * tt * ctrlPoints[4] + ttt * ctrlPoints[6];
    *y = uuu * ctrlPoints[1] + 3 * uu * t * ctrlPoints[3] + 3 * u * tt * ctrlPoints[5] + ttt * ctrlPoints[7];
}

// Function to draw a quadratic Bezier curve
void drawQuadraticBezier(int* ctrlPoints) 
{
    float t;
    int x, y;

    for (t = 0.0; t <= 1.0; t += 0.001) 
	{
        bezier(t, &x, &y, ctrlPoints);
        putpixel(x, y, WHITE);
    }
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int ctrlPoints[] = {50, 200, 150, 50, 250, 200};

    // Draw control points
    setcolor(YELLOW);
    for (int i = 0; i < 6; i += 2) 
	{
        circle(ctrlPoints[i], ctrlPoints[i + 1], 5);
    }

    // Draw the quadratic Bezier curve
    setcolor(WHITE);
    drawQuadraticBezier(ctrlPoints);

    delay(5000);
    closegraph();

    return 0;
}

