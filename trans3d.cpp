#include <iostream>
#include <graphics.h>

struct Point 
{
    int x;
    int y;
};

void translatePoint(Point *point, int tx, int ty) 
{
    point->x += tx;
    point->y += ty;
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Point beforeTranslation = {200, 200};
    Point afterTranslation;

    int tx = 50; // Translation in the x-direction
    int ty = -30; // Translation in the y-direction

    translatePoint(&beforeTranslation, tx, ty);
    afterTranslation = beforeTranslation;

    setcolor(YELLOW); // Set color for before translation
    circle(beforeTranslation.x, beforeTranslation.y, 20); // Larger circle before translation

    setfillstyle(SOLID_FILL, YELLOW); // Set fill style to solid yellow
    floodfill(beforeTranslation.x, beforeTranslation.y, YELLOW); // Fill the circle

    setcolor(BLUE); // Set color for after translation
    circle(afterTranslation.x, afterTranslation.y, 20); // Larger circle after translation

    setfillstyle(SOLID_FILL, BLUE); // Set fill style to solid blue
    floodfill(afterTranslation.x, afterTranslation.y, BLUE); // Fill the circle

    delay(5000);
    closegraph();
    return 0;
}
