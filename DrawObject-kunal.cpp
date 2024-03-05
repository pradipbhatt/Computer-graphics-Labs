#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <iostream>
#define PI 3.14
using namespace std;

struct Point 
{
    double x;
    double y;
};

void drawObject(struct Point point[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        line((int)point[i].x, (int)point[i].y, (int)point[i + 1].x, (int)point[i + 1].y);
    }
    line((int)point[s - 1].x, (int)point[s - 1].y, (int)point[0].x, (int)point[0].y);
}

void print(struct Point point[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << "\npoint" << i << "\t\tx=" << point[i].x << "\t\ty=" << point[i].y;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    struct Point points[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter x-coordinate for point " << i << ": ";
        cin >> points[i].x;
        cout << "Enter y-coordinate for point " << i << ": ";
        cin >> points[i].y;
    }

    drawObject(points, n);
    print(points, n);

    delay(50000);
    closegraph();

    return 0;
}
