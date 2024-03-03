#include <graphics.h>
#include <iostream>

class MidpointCircle {
private:
    int x_center, y_center, radius;

public:
    MidpointCircle(int x, int y, int r) : x_center(x), y_center(y), radius(r) {}

    void drawCircle() {
        int x = radius;
        int y = 0;
        int p = 1 - radius;

        while (x > y) {
            putPixel(x + x_center, y + y_center);
            putPixel(y + x_center, x + y_center);
            putPixel(-y + x_center, x + y_center);
            putPixel(-x + x_center, y + y_center);
            putPixel(-x + x_center, -y + y_center);
            putPixel(-y + x_center, -x + y_center);
            putPixel(y + x_center, -x + y_center);
            putPixel(x + x_center, -y + y_center);

            y++;

            if (p <= 0)
                p = p + 2 * y + 1;
            else {
                x--;
                p = p + 2 * y - 2 * x + 1;
            }
        }
    }

private:
    void putPixel(int x, int y) {
        putpixel(x, y, YELLOW); // Set pixel color to yellow
    }
};

int main() {
    int x, y, r;
    std::cout << "Enter the x-coordinate of the center: ";
    std::cin >> x;
    std::cout << "Enter the y-coordinate of the center: ";
    std::cin >> y;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    MidpointCircle circle(x, y, r);
    circle.drawCircle();

    delay(5000);
    getch();
    closegraph();
    return 0;
}
