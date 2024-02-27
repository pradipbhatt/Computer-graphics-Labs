#include <stdio.h>

// Structure to represent a 2D point
struct Point 
{
    int x;
    int y;
};

// Function to perform 2D translation
void translatePoint(struct Point *point, int tx, int ty) 
{
    point->x += tx;
    point->y += ty;
}

int main() 
{
    struct Point myPoint = {3, 5};
    int tx = 2;  // Translation in the x-direction
    int ty = -1; // Translation in the y-direction

    printf("Before Translation: (%d, %d)\n", myPoint.x, myPoint.y);

    // Perform the translation
    translatePoint(&myPoint, tx, ty);

    printf("After Translation: (%d, %d)\n", myPoint.x, myPoint.y);

    return 0;
}

