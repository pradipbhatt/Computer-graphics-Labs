#include <stdio.h>
#include <graphics.h>

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
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // 2D point coordinates (directly entered)
    struct Point beforeTranslation;
    struct Point afterTranslation;

    // Input coordinates
    printf("Enter the x-coordinate for before translation: ");
    scanf("%d", &beforeTranslation.x);
    printf("Enter the y-coordinate for before translation: ");
    scanf("%d", &beforeTranslation.y);

    // Translation amounts
    int tx, ty;
    printf("Enter the translation in the x-direction: ");
    scanf("%d", &tx);
    printf("Enter the translation in the y-direction: ");
    scanf("%d", &ty);

    // Perform the translation
    translatePoint(&beforeTranslation, tx, ty);
    afterTranslation = beforeTranslation;

    // Draw circles on the screen
    setcolor(GREEN); // Set color for before translation
    circle(beforeTranslation.x, beforeTranslation.y, 50); // Larger circle before translation

    setcolor(BLUE); // Set color for after translation
    circle(afterTranslation.x, afterTranslation.y, 50); // Larger circle after translation

    delay(10000);
    closegraph();
    return 0;
}
