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

    for (int i = 10; i < 500; i = i + 10)
    {
        delay(400);
        cleardevice();

        // Draw the car body (black)
        setcolor(BLACK);
        rectangle(100 + i, 200, 250 + i, 250);
        floodfill(175 + i, 225, BLACK);

        // Draw the car windows (blue)
        setcolor(BLUE);
        rectangle(120 + i, 210, 180 + i, 240);
        floodfill(150 + i, 225, BLUE);

        // Draw the wheels (white)
        setcolor(WHITE);
        circle(140 + i, 250, 15);
        circle(180 + i, 250, 15);

        // Move the car forward
        carX += 10;
        if (carX > getmaxx())
            carX = -250;
        rectangle(carX, 200, carX + 150, 250);
        floodfill(carX + 75, 225, BLACK);

        // Add comments to describe car movement
        setcolor(WHITE);
        outtextxy(10, 10, "Car moving forward...");

        // Uncomment the following lines to make the car move backward
        // carX -= 10;
        // if (carX < -250)
        //     carX = getmaxx();
        // rectangle(carX, 200, carX + 150, 250);
        // floodfill(carX + 75, 225, BLACK);
        // outtextxy(10, 10, "Car moving backward...");
    }

    closegraph();
    return 0;
}
