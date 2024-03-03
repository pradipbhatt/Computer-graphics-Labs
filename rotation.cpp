#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Structure to represent a 2D point
struct Point 
{
    double x;
    double y;
};

// Function to perform 2D rotation
void rotatePoint(struct Point *point, double angleDegrees) 
{
    // Convert angle from degrees to radians
    double angleRadians = angleDegrees * M_PI / 180.0;

    // Rotation matrix
    double cosTheta = cos(angleRadians);
    double sinTheta = sin(angleRadians);

    // Perform the rotation
    double newX = point->x * cosTheta - point->y * sinTheta;
    double newY = point->x * sinTheta + point->y * cosTheta;

    point->x = newX;
    point->y = newY;
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // 2D point coordinates (directly entered)
    struct Point myPoint = {300.0, 5.0};

    // Rotation angle in degrees
    double angleDegrees = 45.0;

    printf("Before Rotation: (%.2f, %.2f)\n", myPoint.x, myPoint.y);

    // Perform the rotation
    rotatePoint(&myPoint, angleDegrees);

    printf("After Rotation: (%.2f, %.2f)\n", myPoint.x, myPoint.y);

    // Draw points on the screen
    setcolor(YELLOW); // Set color for before rotation
    circle(myPoint.x, myPoint.y, 20); // Larger circle at the 2D point

    setfillstyle(SOLID_FILL, YELLOW); // Set fill style to solid yellow
    floodfill(myPoint.x, myPoint.y, YELLOW); // Fill the circle

    delay(5000);
    closegraph();
    return 0;
}
