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

// Function to perform parallel projection (orthographic projection)
void parallelProjection(struct Point3D *point3D, struct Point2D *point2D) 
{
    // In parallel projection, the z-coordinate is ignored
    point2D->x = point3D->x;
    point2D->y = point3D->y;
}

int main() 
{
    struct Point3D myPoint3D = {3.0, 5.0, 10.0}; // 3D point
    struct Point2D myPoint2D;                      // Result after projection

    printf("Before Projection: (%.2f, %.2f, %.2f)\n", myPoint3D.x, myPoint3D.y, myPoint3D.z);

    // Perform the parallel projection
    parallelProjection(&myPoint3D, &myPoint2D);

    printf("After Projection: (%.2f, %.2f)\n", myPoint2D.x, myPoint2D.y);

    return 0;
}

