#include <iostream>
#include <graphics.h>
using namespace std;

struct Point3D
{
    double x;
    double y;
    double z;
};

struct Point2D
{
    double x;
    double y;
};

void drawObject(struct Point2D point[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        line((int)point[i].x, (int)point[i].y, (int)point[i + 1].x, (int)point[i + 1].y);
    }
    line((int)point[s - 1].x, (int)point[s - 1].y, (int)point[0].x, (int)point[0].y);
}

void printPoints(struct Point2D point[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << "\npoint" << i << "\t\tx=" << point[i].x << "\t\ty=" << point[i].y;
    }
}

void parallelProjection(struct Point3D point3d[], struct Point2D point2d[], int s)
{
    cout << "\nBefore Projection:";
    printPoints(point2d, s);

    for (int i = 0; i < s; i++)
    {
        point2d[i].x = point3d[i].x;
        point2d[i].y = point3d[i].y;
    }

    cout << "\nAfter Projection:";
    printPoints(point2d, s);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    struct Point3D myp3d[100];
    struct Point2D myPoint2D[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter coordinates of point " << i << ": ";
        cin >> myp3d[i].x >> myp3d[i].y >> myp3d[i].z;
    }

    parallelProjection(myp3d, myPoint2D, n);

    cout << "\nParallel Projection visualization:\n";
    drawObject(myPoint2D, n);

    delay(5000);
    closegraph();
    return 0;
}
