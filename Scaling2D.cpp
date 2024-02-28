#include <stdio.h>

// Structure to represent a 2D point
struct Point 
{
    double x;
    double y;
};

// Function to perform 2D scaling
void scalePoint(struct Point *point, double scaleX, double scaleY) 
{
    point->x *= scaleX;
    point->y *= scaleY;
}

int main() {
    struct Point myPoint = {3.0, 5.0};
    double scaleX = 2.0; // Scaling factor in the x-direction
    double scaleY = 0.5; // Scaling factor in the y-direction

    printf("Before Scaling: (%.2f, %.2f)\n", myPoint.x, myPoint.y);

    // Perform the scaling
    scalePoint(&myPoint, scaleX, scaleY);

    printf("After Scaling: (%.2f, %.2f)\n", myPoint.x, myPoint.y);

    return 0;
}

