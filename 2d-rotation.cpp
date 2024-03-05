#include <graphics.h>
#include <iostream>
#include <math.h>
#define PI 3.14159265
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

void printPoints(struct Point point[])
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Point " << i + 1 << ": (" << point[i].x << ", " << point[i].y << ")" << endl;
    }
}

void rotateRectangle(struct Point point[], double angleDegrees)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Original coordinates:\n";
    printPoints(point);
    setcolor(GREEN);
    drawRectangle(point);

    double angleRadians = angleDegrees * PI / 180.0;
    double cosTheta = cos(angleRadians);
    double sinTheta = sin(angleRadians);

    for (int i = 0; i < 4; i++)
    {
        double newX = point[i].x * cosTheta - point[i].y * sinTheta;
        double newY = point[i].x * sinTheta + point[i].y * cosTheta;

        point[i].x = newX;
        point[i].y = newY;
    }

    cout << "\nAfter rotation:\n";
    printPoints(point);
    setcolor(RED);
    drawRectangle(point);

    getch();
    closegraph();
}

int main()
{
    struct Point points[4];

    cout << "Enter coordinates of the rectangle:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter x-coordinate of point " << i + 1 << ": ";
        cin >> points[i].x;
        cout << "Enter y-coordinate of point " << i + 1 << ": ";
        cin >> points[i].y;
    }

    double angle;
    cout << "Enter the rotation angle in degrees: ";
    cin >> angle;

    rotateRectangle(points, angle);

    return 0;
}
