#include <stdio.h>
#include <graphics.h>

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

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // 2D point coordinates (directly entered)
    struct Point beforeScaling = {100.0, 100.0};
    struct Point afterScaling;

    // Scaling factors
    double scaleX = 2.0; // Scaling factor in the x-direction
    double scaleY = 1.5; // Scaling factor in the y-direction

    // Perform the scaling
    scalePoint(&beforeScaling, scaleX, scaleY);
    afterScaling = beforeScaling;

    // Draw circles on the screen
    setcolor(YELLOW); // Set color for before scaling
    circle(beforeScaling.x, beforeScaling.y, 20); // Larger circle before scaling

    setfillstyle(SOLID_FILL, YELLOW); // Set fill style to solid yellow
    floodfill(beforeScaling.x, beforeScaling.y, YELLOW); // Fill the circle

    // Perform the scaling
    scalePoint(&afterScaling, scaleX, scaleY);

    setcolor(BLUE); // Set color for after scaling
    circle(afterScaling.x, afterScaling.y, 20); // Larger circle after scaling

    setfillstyle(SOLID_FILL, BLUE); // Set fill style to solid blue
    floodfill(afterScaling.x, afterScaling.y, BLUE); // Fill the circle

    delay(5000);
    closegraph();
    return 0;
}
