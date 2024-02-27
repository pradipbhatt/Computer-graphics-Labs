#include <stdio.h>
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
    struct Point myPoint = {3.0, 5.0};
    double angleDegrees = 45.0; // Rotation angle in degrees

    printf("Before Rotation: (%.2f, %.2f)\n", myPoint.x, myPoint.y);

    // Perform the rotation
    rotatePoint(&myPoint, angleDegrees);

    printf("After Rotation: (%.2f, %.2f)\n", myPoint.x, myPoint.y);

    return 0;
}

