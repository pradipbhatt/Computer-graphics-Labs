#include <iostream>
#include <graphics.h>
using namespace std;

struct Point
{
    double x;
    double y;
};

void drawRectangle(struct Point point[])
{
    line((int)point[0].x, (int)point[0].y, (int)point[1].x, (int)point[1].y);
    line((int)point[1].x, (int)point[1].y, (int)point[2].x, (int)point[2].y);
    line((int)point[2].x, (int)point[2].y, (int)point[3].x, (int)point[3].y);
    line((int)point[3].x, (int)point[3].y, (int)point[0].x, (int)point[0].y);
}

void scaleRectangle(struct Point point[], double scaleX, double scaleY)
{
    for (int i = 0; i < 4; i++)
    {
        point[i].x *= scaleX;
        point[i].y *= scaleY;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    struct Point points[4];

    cout << "Enter coordinates of the rectangle:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter x-coordinate of point " << i + 1 << ": ";
        cin >> points[i].x;
        cout << "Enter y-coordinate of point " << i + 1 << ": ";
        cin >> points[i].y;
    }

    double scaleX, scaleY;
    cout << "Enter the scaling factor for x-axis: ";
    cin >> scaleX;
    cout << "Enter the scaling factor for y-axis: ";
    cin >> scaleY;

    cout << "\nRectangle before scaling:\n";
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(4, (int *)points);
    drawRectangle(points);

    delay(20000);
    cleardevice();

    scaleRectangle(points, scaleX, scaleY);

    cout << "\nRectangle after scaling:\n";
    setfillstyle(SOLID_FILL, YELLOW);
    fillpoly(4, (int *)points);
    drawRectangle(points);

    delay(50000);
    closegraph();

    return 0;
}
