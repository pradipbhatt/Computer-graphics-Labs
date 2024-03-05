#include <graphics.h>
#include <iostream>
using namespace std;

class MidpointEllipse 
{
private:
    int x_center, y_center, a, b;

public:
    MidpointEllipse(int x, int y, int majorAxis, int minorAxis) : x_center(x), y_center(y), a(majorAxis), b(minorAxis) {}

    void drawEllipse() 
    {
        int x = 0, y = b;
        int a_squared = a * a;
        int b_squared = b * b;
        int two_a_squared = 2 * a_squared;
        int two_b_squared = 2 * b_squared;
        int four_a_squared = 4 * a_squared;
        int four_b_squared = 4 * b_squared;
        
        int decision_parameter;

        // Region 1
        decision_parameter = b_squared - a_squared * b + 0.25 * a_squared;
        while (four_b_squared * x <= four_a_squared * y) 
        {
            putPixel(x, y);
            x++;
            if (decision_parameter < 0)
                decision_parameter += two_b_squared * x + b_squared;
            else 
            {
                y--;
                decision_parameter += two_b_squared * x - two_a_squared * y + a_squared + b_squared;
            }
        }

        // Region 2
        decision_parameter = b_squared * (x + 0.5) * (x + 0.5) + a_squared * (y - 1) * (y - 1) - a_squared * b_squared;
        while (y >= 0) 
        {
            putPixel(x, y);
            y--;
            if (decision_parameter > 0)
                decision_parameter += a_squared - two_a_squared * y;
            else 
            {
                x++;
                decision_parameter += two_b_squared * x - two_a_squared * y + a_squared + b_squared;
            }
        }
    }

private:
    void putPixel(int x, int y) 
    {
        putpixel(x + x_center, y + y_center, WHITE);
        putpixel(-x + x_center, y + y_center, WHITE);
        putpixel(x + x_center, -y + y_center, WHITE);
        putpixel(-x + x_center, -y + y_center, WHITE);
    }
};

int main() 
{
    system("color 17");
    int gd = DETECT, gm;
    int x, y, majorAxis, minorAxis;

    cout << "Enter the value of X Coordinate of center: ";
    cin >> x;
    cout << "Enter the value of Y Coordinate of center: ";
    cin >> y;
    cout << "Enter the value of Major axis: ";
    cin >> majorAxis;
    cout << "Enter the value of Minor axis: ";
    cin >> minorAxis;

    initgraph(&gd, &gm, NULL);
    MidpointEllipse ellipse(x, y, majorAxis, minorAxis);
    ellipse.drawEllipse();
    delay(5000);
    getch();
    closegraph();
    return 0;
}
