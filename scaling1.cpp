#include <iostream>
#include <graphics.h>
using namespace std;

struct Point
{
    double x;
    double y;
};

void drawTriangle(struct Point point[])
{
    line((int)point[0].x, (int)point[0].y, (int)point[1].x, (int)point[1].y);
    line((int)point[1].x, (int)point[1].y, (int)point[2].x, (int)point[2].y);
    line((int)point[2].x, (int)point[2].y, (int)point[0].x, (int)point[0].y);
}

void scaleTriangle(struct Point point[], int s, double scaleX, double scaleY)
{
    for (int i = 0; i < s; i++)
    {
        point[i].x *= scaleX;
        point[i].y *= scaleY;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    struct Point points[3];

    cout << "Enter coordinates of the triangle:\n";
    for (int i = 0; i < 3; i++)
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

    cout << "\nTriangle before scaling:\n";
    drawTriangle(points);

    delay(20000);
    cleardevice();

    scaleTriangle(points, 3, scaleX, scaleY);

    cout << "\nTriangle after scaling:\n";
    drawTriangle(points);

    delay(50000);
    closegraph();

    return 0;
}
