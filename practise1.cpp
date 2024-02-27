#include <graphics.h>

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 

    // Draw a circle
    circle(300, 200, 100);

    // Wait for a key press
    getch();

    // Close graphics mode
    closegraph();

    return 0;
}
