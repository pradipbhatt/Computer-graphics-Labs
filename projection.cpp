#include <stdio.h>
#include <graphics.h>

// Structure to represent a 3D point
struct Point3D 
{
    double x;
    double y;
    double z;
};

// Structure to represent a 2D point (result after projection)
struct Point2D 
{
    double x;
    double y;
};

// Function to perform parallel projection (orthographic projection)
void parallelProjection(struct Point3D *point3D, struct Point2D *point2D) 
{
    // In parallel projection, the z-coordinate is ignored
    point2D->x = point3D->x;
    point2D->y = point3D->y;
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // 3D point coordinates (directly entered)
    struct Point3D myPoint3D = {300.0, 100.0, 100.0};

    // Result after projection
    struct Point2D myPoint2D;

    // Perform the parallel projection
    parallelProjection(&myPoint3D, &myPoint2D);

    // Draw points on the screen
    setcolor(YELLOW); // Set color for before projection
    circle(myPoint3D.x, myPoint3D.y, 20); // Larger circle at the 3D point

    setfillstyle(SOLID_FILL, YELLOW); // Set fill style to solid yellow
    floodfill(myPoint3D.x, myPoint3D.y, YELLOW); // Fill the circle

    setcolor(WHITE); // Set color for after projection
    circle(myPoint2D.x, myPoint2D.y, 20); // Larger circle at the 2D point

    setfillstyle(SOLID_FILL, WHITE); // Set fill style to solid blue
    floodfill(myPoint2D.x, myPoint2D.y, WHITE); // Fill the circle

    delay(5000);
    closegraph();
    return 0;
}
