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
    int tx,ty;
    printf("Enter translation in x and y directions=\n ");
    scanf("%d%d",&tx,ty);

    printf("Before Translation: (%d, %d)\n", myPoint.x, myPoint.y);

    // Perform the translation
    translatePoint(&myPoint, tx, ty);

    printf("After Translation: (%d, %d)\n", myPoint.x, myPoint.y);

    return 0;
}

