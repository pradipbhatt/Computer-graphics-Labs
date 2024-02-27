#include <stdio.h>

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

// Function to perform perspective projection
void perspectiveProjection(struct Point3D *point3D, struct Point2D *point2D, double focalLength) 
{
    // Perspective projection formula
    point2D->x = point3D->x * focalLength / point3D->z;
    point2D->y = point3D->y * focalLength / point3D->z;
}

int main() 
{
    struct Point3D myPoint3D = {3.0, 5.0, 10.0}; // 3D point
    struct Point2D myPoint2D;                      // Result after projection
    double focalLength = 5.0;                      // Focal length

    printf("Before Projection: (%.2f, %.2f, %.2f)\n", myPoint3D.x, myPoint3D.y, myPoint3D.z);

    // Perform the perspective projection
    perspectiveProjection(&myPoint3D, &myPoint2D, focalLength);

    printf("After Projection: (%.2f, %.2f)\n", myPoint2D.x, myPoint2D.y);

    return 0;
}

