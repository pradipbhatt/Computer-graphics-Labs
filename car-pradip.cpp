#include <stdio.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set the background color to black
    setbkcolor(BLACK);

    // Car position (initially at x = 100)
    int carX = 100;
    char direction;

    // Main loop for user input
    while (1)
    {
        printf("Enter 'f' to move forward, 'b' to move backward, or 'q' to quit: ");
        scanf(" %c", &direction);

        if (direction == 'q')
            break;

        // Clear the screen
        cleardevice();

        // Draw the car body (black)
        setcolor(BLACK);
        rectangle(100 + carX, 200, 250 + carX, 250);
        floodfill(175 + carX, 225, BLACK);

        // Draw the car windows (blue)
        setcolor(BLUE);
        rectangle(120 + carX, 210, 180 + carX, 240);
        floodfill(150 + carX, 225, BLUE);

        // Draw the wheels (white)
        setcolor(WHITE);
        circle(140 + carX, 250, 15);
        circle(180 + carX, 250, 15);

        // Move the car forward
        if (direction == 'f')
        {
            carX += 10;
            if (carX > getmaxx())
                carX = -250;
            rectangle(carX, 200, carX + 150, 250);
            floodfill(carX + 75, 225, BLACK);
            outtextxy(10, 10, "Car moving forward...");
        }
        // Move the car backward
        else if (direction == 'b')
        {
            carX -= 10;
            if (carX < -250)
                carX = getmaxx();
            rectangle(carX, 200, carX + 150, 250);
            floodfill(carX + 75, 225, BLACK);
            outtextxy(10, 10, "Car moving backward...");
        }
    }

    closegraph();
    return 0;
}
